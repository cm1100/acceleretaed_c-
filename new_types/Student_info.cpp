#include"Student_info.h"
#include<iostream>

using namespace std;


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

istream& Student_info::read(istream& in){
    in>>name>>midterm>>final;
    read_hw(in,homework);
    return in;
}


double grade(double midterm, double final , double homework){
    return 0.2*midterm+0.4*final+0.4*homework;
}

double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if(size==0){
        throw domain_error("median of an empty vector");
    }

    sort(vec.begin(),vec.end());
    vec_sz mid = size/2;
    return size%2==0?(vec[mid]+vec[mid-1])/2:vec[mid];

}


double grade(double midterm , double final, const vector<double>&hw){

    

    if(hw.size()==0){
        throw domain_error("No Homework done");
    }
    return grade(midterm,final,median(hw));
}



double Student_info::grade() const{
    return ::grade(midterm,final,homework);
}


bool compare(Student_info& x , Student_info & y){
    return x.getName()<y.getName();
}

Student_info::Student_info():midterm(0),final(0){}

Student_info::Student_info(istream&is){
    read(is);
}