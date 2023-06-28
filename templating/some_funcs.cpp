#include<iostream>


template<class T>
T max(const T&left,const T&right){

    return left>right?left:right;

}


int main(){
    int a=5;
    double b = 7;
    std::cout<<max(5,6);
    return 0;
}