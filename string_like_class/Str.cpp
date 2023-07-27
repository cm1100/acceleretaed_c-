#include<iostream>
#include"Str.h"

using namespace std;


ostream& operator<<(ostream& os,const Str& s){
    for(Str::size_type i=0;i!=s.size();++i){
        os<<s[i];
    }

    return os;
}



int main(){

    Str s("hello");

    Str t = "hello 2";

    string s2="chaitanya";
    

    cout<<t[0];


    cout<<t;


    



    return 0;
}