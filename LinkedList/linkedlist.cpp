//This contains all the basic operations that can performed on linkedList
//Linked List is better than using array becuse it utilises storing memory at available place rather then storing in a continous memory block
// Author : Nitya Dhagat

#include <iostream>

using namespace std;

class node
{
    int data;
    node *link;

public:
    node(int value)
    {
        data = value;
        link = nullptr;
    }
    friend class implementation;
};

class implementation
{
private:
    node *first;

public:
    implementation()
        first = nullptr;

    void insert(int d){
        node *n1 = new node(d);
        if (first == nullptr)
            first = n1;

        else{
            node *temp=first;
            while (temp->link != nullptr)
            {
                temp = temp->link;
            }
            temp->link = n1;
        }
    }

    void insertafter(int key, int value){
        node *temp = first;
        node *n1 = new node(value);
        while (temp->data != key)
            temp = temp->link;
        
        n1->link = temp->link;
        temp->link = n1;
    }

    void deletelink(int e){

        node *temp = first;
        while (temp->link != nullptr && temp->link->data != e)
            temp = temp->link;

        temp->link = temp->link->link;
    }
    void insertbefore(int key, int value){
        node *temp = first;

        node *n1 = new node(value);

        if (temp->data == key){
            n1->link = first;
            first = n1;
        }
        else{
            while (temp->link->data != key)
            {
                temp = temp->link;
            }
            n1->link = temp->link;
            temp->link = n1;
        }
    }

    void swap()
    {
        node *temp = first;

        while (temp->link != nullptr)
        {
            node *temp1 = temp;
            while (temp1->link != nullptr)
            {
                if (temp1->data < temp->data)
                {
                    cout << "inside temp1 " << temp1->data << "  this is temp=  " << temp->data << endl;
                    int e = temp1->data;
                    deletelink(e);
                    insertbefore(temp->data, e);

                    // break;
                }
                temp1 = temp1->link;
            }
            temp = temp->link;
        }
    }

    void display()
    {
        node *temp1 = first;
        cout << "hello"<<endl;
        while (temp1->link != nullptr)
        {
            cout << "Data " << temp1->data << "   Address " << temp1 << endl;
            temp1 = temp1->link;
        }
        cout << "Data " << temp1->data << "   Address " << temp1 << endl;
    }
};

int main()
{
    node *first = nullptr;
    implementation o;

    o.insert(10);
    o.insert(20);
    o.insert(30);
    o.insert(40);
    o.insert(50);
    o.insert(60);
    o.insert(70);
    o.insert(80);
    o.insert(90);
    o.insertbefore(50, 15);
    o.insertbefore(60, 7);
    cout << endl;
    o.display();
    cout << "this is start of swap funciton";
    o.swap();
    o.display();
}