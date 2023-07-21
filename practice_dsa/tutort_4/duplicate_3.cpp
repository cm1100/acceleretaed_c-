#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


 bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

     /*
     i want to control both the indexDiff and valueDiff
     i want to find 
     a-b <= valuediff
     a<=valuediff+b
     a should be between +-indexDiff
     */

    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++){
        int valuetoFind = valueDiff+nums[i];
        
    }

    return false; 


    
    }


int main(){
    vector<int> nums={2,1,3,1,5,7,9};
    /*
    a-b <=0
    |2-b| <=0
    |b|<= 0+1

    
    0+2
    <=

    */
   
    int indexDiff = 3;
    int valeDiff = 1;

    bool ans =containsNearbyAlmostDuplicate(nums,indexDiff,valeDiff);

    cout<<ans<<endl;

    return 0;
}
