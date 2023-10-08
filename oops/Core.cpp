#include<iostream>
#include"Core.h"

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


string Core::name() const {return n;}

double Core::grade() const{
    return ::grade(midterm,final,homework);
}

istream& Core::read_common(istream& in){
    // read and store the students name and exams grades
    in>>n>>midterm>>final;
    return in;
}

istream & Core::read(istream& in){
    read_common(in);
    read_hw(in,homework);
    return in;
}


istream& Grad::read(istream& in){
    read_common(in);
    in>>thesis;
    read_hw(in,homework);
    return in;
}

double Grad::grade() const
{
    return min(Core::grade(),thesis);
}




int main(){



    return 0;
}