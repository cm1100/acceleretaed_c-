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

};

int main(){


    Cm1 c;
    Cm1 c2=c;
    Cm1 c3(c);




    return 0;
}