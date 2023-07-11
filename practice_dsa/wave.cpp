#include<iostream>
#include<vector>


using namespace std;



void convertToWave(int n, vector<int>& arr){
        
       for(int i=0;i<n;i=2){
        int t = arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=arr[t];
       }
        
    }


int main(){

    vector<int> ex={1 ,2 ,3, 4, 5};
    convertToWave(ex.size(),ex);

    return 0;
}