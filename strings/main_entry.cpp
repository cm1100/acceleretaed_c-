#include<iostream>
#include"string_operations.h"

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){

        auto k=split(s);
        cout<<k[0]<<endl;
    }


    return 0;
}