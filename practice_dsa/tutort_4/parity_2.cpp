#include <iostream>
#include <vector>

using namespace std;

/*
lets see some cases

what will i like


*/

int main()
{

    vector<int> nums = {4, 2, 5, 7};

    vector<int> nums2(nums.size());

    int fill_even =0;
    int fill_odd =1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            nums2[fill_even]=nums[i];
            fill_even+=2;
        }else{
            nums2[fill_odd] = nums[i];
            fill_odd+=2;


        }
    }


    
   


    copy(nums.begin(),nums.end(),ostream_iterator<int>(cout," "));


    cout<<endl;
    copy(nums2.begin(),nums2.end(),ostream_iterator<int>(cout," "));

    return 0;
}