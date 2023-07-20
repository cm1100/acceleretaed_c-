#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


int main(){

    vector<int> arr= {8,4,5,0,0,0,0,7};
    /*
    1 0 0 2 3 0 4 5
    1 
    
    */

   unordered_map<int,int> m;

   int i =0;
   while(i<arr.size()){

    if(arr[i]==0){
            int j=arr.size()-1;
            while(j>i+1){
                arr[j]=arr[j-1];
                j--;
            }
            arr[i+1]=arr[i];
            i=i+2;
        }else{
            i++;
        }



   }

   

    copy(arr.begin(),arr.end(),ostream_iterator<int>(cout," "));

    return 0;
}