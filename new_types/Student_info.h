#include<iostream>
#include<vector>

class Student_info{

    public:
    std::string getName() const{
        return name;
    }

    bool valid(){
        return !homework.empty();
    }
    std::istream & read(std::istream&);
    double grade() const;

    private:
    std::string name;
    double midterm,final;
    std::vector<double> homework;


   
};