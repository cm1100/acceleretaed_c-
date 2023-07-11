#include<iostream>

using namespace std;


int next(int n){

    return n+1;
}

typedef int (*net_fp)(int);

typedef int int2;

net_fp get_next(){
    return next;
}

int main(){
    int x = 5;

    int *p = &x;

    cout<<"x ="<<x<<endl;

    *p=6;
    cout<<"x ="<<x<<endl;


    int (*fp)(int);

    fp = next;

    int2 i = 1;

    cout<<(*fp)(i)<<endl;

    cout<<get_next()(10);


    return 0;
}