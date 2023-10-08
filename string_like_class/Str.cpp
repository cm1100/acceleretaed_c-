#include<iostream>
#include"Str.h"

using namespace std;

Str operator+(const Str& s,const Str&t){
    Str r =s;
    r+=t;
    return r;
}

ostream& operator<<(ostream& os,const Str& s){
    for(Str::size_type i=0;i!=s.size();++i){
        os<<s[i];
    }

    return os;
}


istream& operator>>(istream& is, Str&s){
    s.data.clear();
    
    char c;
    while(is.get(c)&&isspace(c)){
        // nothing to do except testing condition
    }
    if(is){
        do s.data.push_back(c);
        while(is.get(c)&&!isspace(c));

        if(is)
            cout<<"in here"<<endl;
            cout<<c<<"good"<<endl;
            is.unget();
    }

    return is;
}



int main(){

    //Str s("hello");

    //Str t = "hello 2";

    // string s2="chaitanya";
    

    //cout<<t[0];

    Str s3;
    cin>>s3;

    cout<<s3<<endl;
    
    Str a ="chaitanya";
    Str b ="malik";
    a+=b;

    cout<<a<<endl;

    return 0;
}