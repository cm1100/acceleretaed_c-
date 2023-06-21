#include<algorithm>
#include<iomanip>
#include<stdexcept>
#include"Student_info.h"
#include"grade.h"


using namespace std;

int main(){

    vector<Student_info> students,did,didnt;
    Student_info record;



    while(read(cin,record)){
        if(did_all_hw(record))
            did.push_back(record);
        else
            didnt.push_back(record);

        
        if(did.empty()){
            cout<<"No student did all the homework";
        }

        if(didnt.empty()){
            cout<<"every student did the homework";
        }

    }


    






    return 0;
}