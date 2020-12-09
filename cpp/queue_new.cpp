/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Node {
    // This class has a next and previous node.
    public:
        string name;
        
        Node* next;
        Node* prev;
        
        Node(string nm = "name") {
            name = nm;
            next = nullptr;
            prev = nullptr;
        }
};

class Queue {
    
    // first in first out,
    // enter from back, take out from front
    
    // next <- front -> prev -> back
    
    private:
        Node* front;
        Node* back;
        int content_amount;
    
    public:
        Queue() {
            front = nullptr;
            back = nullptr;
            content_amount = 0;
        }
        
        int count () { return content_amount; }
        
        // Add node to the back of queue
        void append(Node* new_node) {
            Node* temp;
            temp = new_node;
            temp->next = back;
            
            if (back != nullptr) { 
                // As long as 'back' exists
                back->prev = temp;
            }
            
            back = temp;
            
            content_amount++;
            
            if (content_amount == 1) {
                front = back;
            }
        }
        
        Node* pop() {
            // Take out the most-front element and return 
            if (content_amount > 0) {
                Node* old_front;
                Node* new_front;
                
                old_front = front;
                new_front = front->prev;
                
                content_amount--;
                
                front = new_front;
                
                return old_front;
            }
            
            else {
                front = nullptr;
                back = nullptr;
                
                return nullptr;
            }
        }
};


int main()
{
    Queue q1;
    
    Node* first = new Node("one");
    Node* sec = new Node("two");
    Node* tre = new Node("three");
    Node* four = new Node("four");

    q1.append(sec);
    q1.append(tre);
    cout << q1.pop()->name << endl;
    
    q1.append(first);
    q1.append(four);
    
    cout << q1.pop()->name << endl;
    cout << q1.pop()->name << endl;
    

    return 0;
}
