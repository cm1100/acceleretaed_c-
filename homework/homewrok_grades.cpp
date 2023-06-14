#include<iostream>
#include<vector>

using namespace std;
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

void read_hw(istream& in,vector<double>&hw ){
    if(in){
        hw.clear();

        double x;
        while(in>>x){
            hw.push_back(x);
        }
        in.clear();
    }
    //return in;
}


double grade(double midterm , double final, const vector<double>&hw){

    if(hw.size()==0){
        throw domain_error("No Homework done");
    }
    return grade(midterm,final,median(hw));
}

int main(){

    cout<<"Please enter your first name";
    string name;
    cin>>name;
    cout<<"Hello, "<<name<<"!"<<endl;

    cout<<"Please enter your midterm and final exam grades"<<endl;
    double midterm,final;
    cin>>midterm>>final;


    cout<<"Enter your all homework gardes"<<endl;
    vector<double>homework;

    read_hw(cin,homework);


    try{
        double final_grade = grade(midterm,final,homework);
        cout<<final_grade<<endl;

    }catch(exception e){
        cout<<"Some exception occured";
    }

    return 0;
}