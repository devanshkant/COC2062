#include<iostream>
#include"LL.h"
using namespace std;

//integer to linked list in reverse order
ListNode<int>* int_2_LL(int num){
    if(num == 0) return new ListNode<int>(0);    
    ListNode<int> *head = nullptr;
    ListNode<int> *tail = nullptr;
    
    while(num > 0){
        int digit = num % 10;
        ListNode<int>* newNode = new ListNode<int>(digit);
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

int multiply_2_int(ListNode<int>* h1, ListNode<int>* h2){
    int result = 0;
    ListNode<int> *t1 = h1;
    ListNode<int> *t2 = h2;
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
    ListNode<int>* head = int_2_LL(341);
    ListNode<int>* number = int_2_LL(72);
    
    cout << "First number: ";
    head->print();
    
    cout << "Second number: ";
    number->print();
    
    int res = multiply_2_int(head, number);
    cout << "Result is = " << res << '\n';
    
    return 0;
}