#include<iostream>
#include"Student_info.h"



using namespace std;

int main(){
    Student_info s;
    s.read(cin);

    cout<<s.getName();

    return 0;
}