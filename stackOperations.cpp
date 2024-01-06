//This is all the general operations of Stack data structure using Array.
//Any updation/suggestion is welcomed.
//Author : Nitya Dhagat


#include<iostream>

using namespace std;

#define MAX 1000;           //Variable maximum size for the stack 

class Stack{
    int top;    
    public:
        Stack(){
            top=-1;
        }
        int arr[MAX];       //Declare a maximum array of 1000 for stack
        bool push(int x);   //push() operation declaration
        int pop();          //pop() operation declaration
        int peek();         //peek() operation declaration
        bool isEmpty();     //isEmpty() operation declaration
};

bool Stack::push(int element){
    if(top>=(MAX-1)){
        cout<<"Stack overflow"<<endl;
        return false;
    }
    else{
        arr[++top]=element;
        cout<<"Element pushed successfully"<<endl;
        return true;
    }
}

int Stack::pop(){
    if(top==-1){
        cout<<"No element to print"<<endl;
        return -1;
    }
    else{
        int deleted_element = arr[top--];
        cout<<"Element deleted"<<endl;
        return deleted_element;
    }
}

int Stack::peek(){
    if(isEmpty()){
        cout<<"Empty element"<<endl;
        return -1;
    }
    else{
        return arr[top];
    }
}

bool Stack::isEmpty(){
    if(!top)
        return true;
    return false;
}