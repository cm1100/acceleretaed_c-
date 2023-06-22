#include "Student_info.h"
#include "median.h"
#include<stdexcept>
#include<vector>


using namespace std;



double grade(double midterm, double final , double homework){
    cout<<"in overload first"<<endl;
    return 0.2*midterm+0.4*final+0.4*homework;
}


double grade(double midterm , double final, const vector<double>&hw){

    cout<<"in overload 2"<<endl;

    if(hw.size()==0){
        throw domain_error("No Homework done");
    }
    return grade(midterm,final,median(hw));
}

double grade(const Student_info& s){
    cout<<"in overload 3"<<endl;
    return grade(s.midterm,s.final,s.homework);
}