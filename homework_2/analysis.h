#include<iostream>
#include<vector>
#include"Student_info.h"


void write_analysis(std::ostream& out,const std::string &name,double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>&did,const std::vector<Student_info>&didnt);


double median_analysis(const std::vector<Student_info>& students);