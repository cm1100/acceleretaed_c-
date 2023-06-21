#ifndef GUARD_Student_info
#define GUARD_Student_info

#include<iostream>
#include<string>
#include<vector>

struct Student_info{
    std::string name;
    double midterm,final;
    std::vector<double> homework;
};


std::istream& read(std::istream& is,Student_info&s);
std::istream & read_hw(std::istream& in,std::vector<double>&hw );
bool compare(const Student_info&x , const Student_info & y);

bool did_all_hw(const Student_info&s);



#endif