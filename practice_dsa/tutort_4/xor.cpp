
#include<iostream>
#include<vector>


/*
input = [1,2,3]
first = 1
output = [1,0,2,1]
1^0 0^2 2^1

1^a=0
a^b = 0


0001

0000

xor :- whenever odd number of 1 the output is 1 , otherwise 0



[4 2 0 7 4]
[6 2 7 3]
first = 4

4 ^ x = 6
0100
abcd
0010

0110


conditions:-
 1 1 :- 0
 0 1 :- 1
 1 0 :- 1
 0 0 :- 0
*/

using namespace std;

int main(){

    vector<int> inp = {6 ,2 ,7 ,3};

    int first =4;

    for(int i=0;i<inp.size();i++){
        first = first^inp[i];
        cout<<first<<endl;
    }
    



    return 0;
}