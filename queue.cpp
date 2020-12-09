/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Node {
    
    public:
        bool last, first;
        string name;
        Node* next;
        
        
        Node(string nm = "name") {
            
            name = nm;
            
            if (this->next == nullptr) {
                // If we have no next, this is the last one
                last = true;
            }
        }
};

class Queue {
    
    // first in first out,
    // enter from back, take out from front
    
    private:
        Node* front;
        Node* back;
        int content_amount;
    
    public:
        Queue() {
            content_amount = 0;
        }
        
        // Add node to the back of queue
        void append(Node* new_node) {
            Node* temp = new_node;
            temp->next = back; // The next node of new is the back node
            back = temp;       // The new back node is now new
            
        }
        
        Node* pop() {
            // Take out the front, set the next node as front
            Node* cur_node;
            Node* old_front; // The front that is being ejected
            Node* new_front; // The front after the ejection
            
            while (back->next->next != nullptr) {
                // Iterate until we get
                cur_node = back->next;
            }
            old_front = cur_node->next;
            new_front = cur_node;
            
            
            return old_front;
        }
    
};


int main()
{
    
    
    Node* first = new Node("one");
    Node* sec = new Node("two");

    return 0;
}
