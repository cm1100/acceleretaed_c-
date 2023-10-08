#include<iostream>
#include"implement_vector.h"

using namespace std;

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    if(&rhs!=this){
        uncreate();
        create(rhs.begin(),rhs.end());
    }
    return *this;
}

template<class T>
void Vec<T>::create(){
    data = avail=limit=0;
}

template<class T>
void Vec<T>::create(size_type n,const T&val){
    data = alloc.allocate(n);
    limit =avail=data+n;
    uninitialized_fill(data,limit,val);
}

template<class T>
void Vec<T>::create(const_iterator i , const_iterator j){
    data = alloc.allocate(j-i);
    limit = avail = std::uninitialized_copy(i,j,data);
}


template <class T> void Vec<T>::uncreate(){
    if(data){
        //dsetroy (in reverse order) the elements were constructed
        iterator it = avail;
        while(it!=data){
            alloc.destroy(--it);
        }
        // returns all the space to the os we deallocated from 
        alloc.deallocate(data,limit-data);
    }
    data = limit = avail=0;
}

template<class T>
void Vec<T>::grow(){
    // when growing allocating  twice as much space as we currently use
    size_type new_size = std::max(2*(limit-data),ptrdiff_t(1));

    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data,avail,new_data);

    // return the old space
    uncreate();


    //reset pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data+new_size;
}

template<class T>
void Vec<T>::unchecked_append(const T& val){
    alloc.construct(avail++,val);
}

using namespace std;
int main(){

    cout<<"started";

    Vec<int> i ;
    i.push_back(10);

    for(Vec<int>::iterator it = i.begin();it!=i.end();it++){
        cout<<*it;
    }

    cout<<endl;

    for( int j=0;j<i.size();j++){
        cout<<i[j];
    }
    

    return 0;
}


