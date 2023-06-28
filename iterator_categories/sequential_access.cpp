#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

template<class In,class X>
In find(In begin,In end,const X&x){
    while(begin!=end&&*begin!=x){
        **begin;
    }

    return begin;
}

template<class In,class Out>
Out copy1(In begin,In end,Out dest){
    while(begin!=end){
        *dest++ =*begin++;
    }
    return dest;
}

int main(){
    vector<int> v;
    auto res =copy1(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(v));
    

    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    


    return 0;
}