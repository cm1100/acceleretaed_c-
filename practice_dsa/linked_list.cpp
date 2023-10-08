#include<iostream>



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

void recursive_traverse(Node *head){

    cout<<"printing nodes"<<endl;

    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head = head->next;

    } 

}

void delete_given_value(int value,Node *head){

    if(head->data==value){
        Node * del=head->next;
        head->next = head->next->next;
        delete del;
        return;
    }

    
    while(head->next!=NULL){
        if(head->next->data==value){
            Node *del = head->next;
            head->next = head->next->next;
            delete del;
            return;
        }
        head= head->next;
        
    }

}


void remove_nth_element_from_end_of_list(int n,Node *head){
    cout<<"removing nth element"<<endl;
    Node*fast,*slow;
    fast = slow = head;
    for(int i=0;i<=n;i++){
        fast = fast->next;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow=slow->next;
    }

    Node * prev = slow->next;
    slow->next = slow->next->next;
    delete prev;



}


void print_middle(Node *head){
    cout<<"finding middle for you"<<endl;
    Node *fast = head;
    Node *slow = head;
    Node *slow_prev = slow;
    int size=0;
    while(fast!=NULL){
        if(fast->next!=NULL){

        fast= fast->next->next;
        slow_prev = slow;
        slow=slow->next;


        }else{
            fast=fast->next;
            size++;
        }

        size++;
        
        
    } 

    //cout<<size<<endl;
    if(size%2==0){
        cout<<slow_prev->data<<endl;
    }
    cout<<slow->data<<endl;

    

}


int main(){

    Node *n1 = new Node(5);

    Node *n2 = new Node(7);
    Node *n3 = new Node(10);
    Node *n4 = new Node(11);

    n1->next =n2;
    n2->next = n3;
    n3->next = n4;

    //cout<<(n1.next)->data;

    Node *head = n1;

    //recursive_traverse(head);


    //delete_given_value(7,head);
    //delete_given_value(10,head);
    //delete_given_value(5,head);
    recursive_traverse(head);
    //print_middle(head);
    remove_nth_element_from_end_of_list(2,head);
    recursive_traverse(head);



    return 0;
}