#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        data=0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        next = NULL;
    }



};

Node * construct_from_vector(vector<int> nums){
    Node * head = new Node(nums[0]);
    Node * temp = head;
    for(int i=1;i<nums.size();i++){
        Node* toAdd = new Node(nums[i]);
        temp->next = toAdd;
        temp = toAdd;
    }

    return head;
}


void print_list(Node *head){

    while(head!=NULL){

        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}


int main(){

    vector<int> nums ={2,1,5};
    // output needed [5,5,0]
    
    Node*head = construct_from_vector(nums);

    print_list(head);

    return 0;
}