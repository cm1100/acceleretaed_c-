#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdexcept>


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

// reads grade from a function

double grade(double midterm, double final , double homework){
    return 0.2*midterm+0.4*final+0.4*homework;
}


//gets median 
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


// gets grade of a full size homework
double grade(double midterm , double final, const vector<double>&hw){

    if(hw.size()==0){
        throw domain_error("No Homework done");
    }
    return grade(midterm,final,median(hw));
}

double grade(const Student_info& s){
    return grade(s.midterm,s.final,s.homework);
}


// writing a comparison function
bool compare(const Student_info&x , const Student_info & y){
    return x.name<y.name;
}


//Generating the report

int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen=0;

    // lets review this code what is happening??
    while (read(cin,record))
    {   

        maxlen = max(maxlen,record.name.size());
        cout<<"array pushed"<<endl;
        students.push_back(record);
        /* code */
    }


    cout<<endl;

    sort(students.begin(),students.end(),compare);

    for(vector<Student_info>::size_type i=0;i!=students.size();++i){

        cout<<students[i].name<<string(maxlen+1-students[i].name.size(),' ');


        try{
            double final_grade= grade(students[i]);
            cout<<final_grade<<endl;;
        }catch(exception e){
            cout<<e.what();
        }

    }



    
    
}
