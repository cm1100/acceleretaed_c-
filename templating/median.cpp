#include<iostream>
#include<vector>


using namespace std;


template<class T>
T median(vector<T> v){

    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if(size==0){
        throw domain_error("median of an empty vector");
    }

    sort(v.begin(),v.end());

    vec_sz mid = v.size()/2;

    return size%2==0?(v[mid]+v[mid-1])/2:v[mid];

}


int main(){
    vector<int> abv ={1,4,5,2,4};

    cout<<median<int>(abv);

    return 0;
}
