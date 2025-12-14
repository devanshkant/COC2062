#ifndef     LINKED_LIST_H
#define     LINKED_LIST_H

#include<iostream>
#include<vector>
template<typename T>
class ListNode{
public:
    T val;
    ListNode<T> *next;

    ListNode(T value){
        val = value;
        next = nullptr;
    }
    ListNode<T>* reverse(){
        ListNode<T> *curr = this;
        ListNode<T> *prev = nullptr;
        
        while(curr) {
            ListNode<T> *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void append(T value){
        ListNode<T> *temp = this;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new ListNode<T>(value);
    }
    ListNode<T>* deleteValue(T value){
        if(this->val == value) {
            ListNode<T> *temp = this->next;
            delete this;
            return temp;
        }
        
        ListNode<T> *curr = this;
        while(curr->next) {
            if(curr->next->val == value) {
                ListNode<T> *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return this;
            }
            curr = curr->next;
        }
        return this;
    }
    void insert(int position, T value){
        if(position == 0){
            ListNode<T> *newNode = new ListNode<T>(value);
            newNode->next = this->next;
            this->next = newNode;
            return;
        }
        
        ListNode<T> *curr = this;
        for(int i = 0; i < position && curr; i++){
            curr = curr->next;
        }
        
        if(curr){
            ListNode<T> *newNode = new ListNode<T>(value);
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    void print() {
        ListNode<T> *curr = this;
        while(curr){
            std::cout << curr->val;
            if(curr->next) std::cout << " -> ";
            curr = curr->next;
        }
        std::cout << '\n';
    }
    static ListNode<T>* array_2_LL(const std::vector<T> &v){
        if(v.empty()){
            return nullptr;
        }
        ListNode<T>* head = new ListNode<T>(v[0]);
        ListNode<T>* result = head;

        for(std::size_t i = 1; i < v.size(); ++i){
            result->next = new ListNode<T>(v[i]);
            result = result->next;
        }
        return head;
    }
};

#endif