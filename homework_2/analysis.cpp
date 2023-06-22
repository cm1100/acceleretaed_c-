#include<iostream>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include<cctype>
#include<numeric>
using namespace std;


double grade_aux(const Student_info &s){
     cout<<endl<<endl;
    try{
        cout<<"in here"<<endl;
        return grade(s);
        cout<<"passed"<<endl;
    }catch(domain_error){
       cout<<"in catch"<<endl;
        return grade(s.midterm,s.final,0);
    }
}


double median_analysis(const vector<Student_info>& students){
    vector<double> grades;

    transform(students.begin(),students.end(),back_inserter(grades),grade_aux);
    cout<<"students size"<<students.size()<<endl;

    return median(grades);
}


void write_analysis(ostream& out,const string &name,double analysis(const vector<Student_info>&),
                    const vector<Student_info>&did,const vector<Student_info>&didnt)

{
    cout<<"students did homework size"<<did.size()<<endl;
    cout<<"students did not do homework size"<<didnt.size()<<endl;
    out<<name<<" : median(did) = " << analysis(did)<<", median(didnt) = "<<analysis(didnt)<<endl;
}


double average(const vector<double>&v){
    return accumulate(v.begin(),v.end(),0.0)/v.size();
}

double average_grade(const Student_info& s){
    return grade(s.midterm,s.final,average(s.homework));
}


double average_analysis(const vector<Student_info>& students){
    vector<double> grades;

    transform(students.begin(),students.end(),back_inserter(grades),average_grade);
}


double optimistic_median(const Student_info& s){
    vector<double> nonzero;

    remove_copy(s.homework.begin(),s.homework.end(),back_inserter(nonzero),0);

    if(nonzero.empty()){
        return grade(s.midterm,s.final,0);
    }else{
        return grade(s.midterm,s.final,median(nonzero));

    }
}