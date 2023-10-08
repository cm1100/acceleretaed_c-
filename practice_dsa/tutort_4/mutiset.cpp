#include<iostream>
#include<set>

using namespace std;

int main(){
    std::multiset<int> myMultiset;

    // Insert elements into the multiset
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(10);
    myMultiset.insert(50);
    myMultiset.insert(1);
    myMultiset.insert(3);
    myMultiset.insert(5); // Duplicate element

    // Iterate through the multiset and print its elements
    for (const auto& element : myMultiset) {
        std::cout << element << " ";
    }



    cout<<endl;
    cout<<*myMultiset.upper_bound(10);

    return 0;
}