#include<iostream>
using namespace std;

int main(){
    int *p = new int(42);

    ++*p;

    cout<<*p;

    delete p;


    return 0;
}