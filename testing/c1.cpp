
#include<iostream>
#include<vector>

using namespace std;



int thirdMax(vector<int>& nums) {

if(nums.size()==1){
    return nums[0];
}

if(nums.size()==2){
    return max(nums[0],nums[1]);
}

int firstMax=INT_MIN,secondMax=INT_MIN,thirdMax=INT_MIN;


int flag=0,flag2=0;

for(vector<int>::iterator it= nums.begin();it!=nums.end();it++){
    if((*it)==INT_MIN && secondMax!=(*it) &&firstMax!=(*it)){
        flag=1;
    }
    if((*it)>=firstMax){
        cout<<"in here"<<endl;
        thirdMax = secondMax;
        secondMax = firstMax;
        firstMax = (*it);
    }else if((*it)>=secondMax && (*it)!=firstMax){
        cout<<"in here "<<endl;

        thirdMax= secondMax;
        secondMax=(*it);


    }else if((*it)>=thirdMax && (*it)!=secondMax && (*it)!=firstMax){
        cout<<"in here";
        thirdMax=(*it);
    }
}


if(thirdMax==INT_MIN && flag==0){
    return firstMax;
}


return thirdMax;

}




int main(){

    vector<int> arra= {1,-2147483648,1};

    int tird =thirdMax(arra);

    cout<<tird;


    return 0;
}