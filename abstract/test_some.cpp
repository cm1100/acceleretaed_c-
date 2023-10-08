#include<iostream>



using namespace std;

class Cm1{
public:
int o;
Cm1(){

}
Cm1(const Cm1&c){

    cout<<"in here"<<endl;
    

}
Cm1 & operator=(const Cm1&c){
    cout<<"in here as well";

    return *this;
}

Cm1 & operator=(Cm1&c){
    cout<<"in here as well";

    return *this;
}

};

int main(){


    Cm1 c;
    Cm1 c2=c;
    Cm1 c3(c);
    c3=c2;


    




    return 0;
}