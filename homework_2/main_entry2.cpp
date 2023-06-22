#include<algorithm>
#include<iomanip>
#include<stdexcept>
#include"Student_info.h"
#include"grade.h"
#include"analysis.h"


using namespace std;

int main(){

    vector<Student_info> did,didnt;
    Student_info record;



    while(read(cin,record)){
        if(did_all_hw(record))
            did.push_back(record);
        else
            didnt.push_back(record);

        
   

    }

     if(did.empty()){
        cout<<"No student did all the homework"<<endl;
    }

    if(didnt.empty()){
        cout<<"every student did the homework"<<endl;
    }


    write_analysis(cout,"median",median_analysis,did,didnt);







    return 0;
}