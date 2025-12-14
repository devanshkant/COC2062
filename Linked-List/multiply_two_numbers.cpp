#include<iostream>

using namespace std;
class Node{
public:
    int val;
    Node* next;

    Node(int value){
        val = value;
        next = nullptr;
    }
};
//integer to linked list in reverse order
Node* int_2_LL(int num){
    if(num == 0) return new Node(0);    
    Node *head = nullptr,
         *tail = nullptr;
    while(num > 0){
        int digit = num % 10;
        Node* newNode = new Node(digit);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }   
        num = num / 10;
    }
    return head;
}
int multiply_2_int(Node* h1, Node *h2){
    int result = 0;
    Node *t1 = h1, *t2 = h2;
    int q = 1;
    while(t2){
        int d = t2->val;
        int p = 1;
        t1 = h1;
        while(t1){
            int h = t1->val;
            result = result + d*h*p*q;
            p *= 10;
            t1 = t1->next;
        }
        q *= 10;
        t2 = t2->next;
    }
    return result;
}

int main(){
    Node* head = int_2_LL(341);
    Node* number = int_2_LL(72);
    int res = multiply_2_int(head, number);
    cout << "result is = "<< res << '\n';
    return 0;
}