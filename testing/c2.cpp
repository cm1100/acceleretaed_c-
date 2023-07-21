#include<iostream>

using namespace std;

int& ret(int& a){
    a=5;
    return a;
}

int main(){


    int b =10;
    int& c =ret(b);
    c=100;

    cout<<b<<c;



    return 0;
}