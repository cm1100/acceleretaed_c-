#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


int main(){

    vector<int> arr= {1,0,2,3,0,4,5,0};
    /*
    1 0 0 2 3 0 4 5
    1 
    
    */

   unordered_map<int,int> m;

   int i =0;
   int number_of_zeroes;
   while(i<arr.size()){

    if(arr[i]==0 && i+number_of_zeroes<arr.size()){
          m[number_of_zeroes+i]=0;
          m[i+number_of_zeroes+1]=0;
          number_of_zeroes++;  
            i=i+1;
        }else{
            m[i+number_of_zeroes]=arr[i];
            i++;
        }



   }


    for (const auto& entry : m) {
        if(entry.first<arr.size()){
            arr[entry.first]=entry.second;
        
        }
    }



    copy(arr.begin(),arr.end(),ostream_iterator<int>(cout," "));

    return 0;
}