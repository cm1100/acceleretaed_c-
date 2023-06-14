#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Student_info{
    string name;
    double midterm,final;
    vector<double> homework;
};


istream & read_hw(istream& in,vector<double>&hw ){
    if(in){
        hw.clear();

        double x;
        while(in>>x){
            hw.push_back(x);
        }
       in.clear();
    }
    return in;
}

istream& read(istream& is,Student_info&s){

    

    cout<<"enter the name of the student"<<endl;
    is>>s.name;
   
    cout<<"enter the final and midterm"<<endl;
    is>>s.midterm>>s.final;
    
    cout<<"enter the hoework grades"<<endl;
    read_hw(is,s.homework);
    return is;
}


bool compare(const Student_info&x , const Student_info & y){
    return x.name<y.name;
}


