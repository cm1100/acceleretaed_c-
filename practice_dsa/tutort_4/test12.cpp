#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{

    int n = nums.size();
    multiset<int> ms; // to store window elements in sorted order

    int i = 0, j = 0;
    while (j < n)
    {
        auto up = ms.upper_bound(nums[j]);
        cout<<"multiset is ";
        copy(ms.begin(),ms.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        cout<<"upper bound is "<<*up<<endl;
        if ((up != ms.end() and *up - nums[j] <= valueDiff) || (up != ms.begin() and nums[j] - *(--up) <= valueDiff)){
            cout<<"in return "<<*up<<nums[j]<<endl;
            return true;
        }
            
        ms.insert(nums[j]);

        if (ms.size() == indexDiff + 1)
        {
            ms.erase(nums[i]);
            i++;
        }
        j++;
        
    }
    return false;
}

int main()
{

    vector<int> inp = {1, 3, 1, 2};
    bool ans = containsNearbyAlmostDuplicate(inp, 2, 0);
    cout << ans;
    return 0;
}