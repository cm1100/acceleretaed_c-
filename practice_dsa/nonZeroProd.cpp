#include<iostream>
#include<vector>
#include<numeric>


using namespace std;
const int MOD = 1000000007;

int power(int x, int times) {
    if (times == 0) {
        return 1;
    }
    long long temp = power(x, times / 2);
    temp = (temp * temp) % MOD;
    if (times % 2) {
        temp = (temp * x) % MOD;
    }
    return temp;
}

int minNonZeroProduct(int p) {

    int x = (1<<p)-1;
    //int complementPairs = (1 << (p - 1)) - 1;
    int mult = x-1;
    // multiply by 7
    // divide by 2 is 3 which will be -1 2
    // 6**3
    //
    cout<<x/2;
    int res =power(mult,x/2);

    cout<<res*x;



    cout<<x;
      

    return 0;
}

int main(){

    minNonZeroProduct(3);
    
    return 0;
}