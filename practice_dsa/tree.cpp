#include<iostream>

using namespace std;

class Node{

    public:
    int val;
    Node*left;
    Node*right;

    Node(int val,Node*left,Node*right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
    Node(int val){
        this->val = val;
    }
};

Node* defaul_tree(){

    Node*level_2_1=new Node(4);
    Node*level_2_2 = new Node(5);
    Node *level_2_3 = new Node(6);
    Node *level_2_4 = new Node(7);
    Node* level_1_1 = new Node(2,level_2_1,level_2_2);
    Node * level_1_2= new Node(3,level_2_3,level_2_4);
    Node*head = new Node(1,level_1_1,level_1_2);

    return head;



}

void traverse(Node * root){
    if(root==NULL){
        return;
    }
    
    traverse(root->left);
    traverse(root->right);
     cout<<root->val;

}

int main(){

    Node * root = defaul_tree();
    traverse(root);
    cout<<endl;
    return 0;
}