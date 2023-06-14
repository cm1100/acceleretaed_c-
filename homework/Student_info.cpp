#include<iostream>
#include<string>
#include<vector>
#include"grade.h"
#include<list>

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

bool fgrade(const Student_info& s){
    return grade(s)<60;
}

vector<Student_info> extract_fails_apr_1(vector<Student_info>& students){

    vector<Student_info> pass ,fail;

    for(vector<Student_info>::size_type i=0;i<students.size(),++i){
        if(fgrade(students[i])){
            fail.push_back(students[i]);
        }else{
            pass.push_back(students[i]);
        }
    
    }

    students = pass;

    return fail;
}

vector<Student_info> extract_fails_apr_2(vector<Student_info>& students){
    vector<Student_info> fail;

    vector<Student_info>::size_type  i=0;

    while(i!=students.size()){
        if(fgrade(students[i])){
            fail.push_back(students[i]);
            students.erase(students.begin()+i);
        }else{
            ++i;
        }
    }
    return fail;
}

/*
every stabdard container such as vector defines 2 iterator types
container-type::cont_iterator
container-type::iterator
*/

vector<Student_info> extract_fails_apr_3(vector<Student_info>& students){
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

    while(iter!=students.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }else{
            iter++;
        }
    }


    return fail;
}

/*
this wokrs as a linked list which is great i guess
list:- linked list
vector :- array
*/
list<Student_info> extract_fails_apr_4(list<Student_info>& students){
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while(iter!=students.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }else{
            iter++;
        }
    }


    return fail;
}

