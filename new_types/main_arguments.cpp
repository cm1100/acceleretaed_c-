#include<iostream>

using namespace std;
int main(int argc,char** argv){
    cout<<argc<<endl;

    if(argc>1){
        cout<<"printing first ";
        cout<<argv[1]<<endl;


        for(int i =2;i!=argc;++i){
        cout<<" "<<argv[i];
    }
    }

    
    cout<<endl;
    return 0;
}