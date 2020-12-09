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

class Stack {
 
    private:   
        Node* top;
        Node* bottom; // OBS
        int content_amount;
     
    public:
        Stack() {
          cout << "Created a Stack" << endl;
          content_amount = 0;
        
        }
        
        // Push
        void put_ontop(Node* new_node) {
            Node* temp = new_node;
            temp->next = top;
            top = temp;
            
            content_amount++;
        }
    
        // Pop
        Node* take_top() {
            if (content_amount > 0) {
                Node* temp = top;
                top = top->next;
                
                content_amount--;
                return temp;
            }
        }
        
        int count() { return content_amount; }
    
};

int main()
{
    Stack stack1;
    
    Node* first = new Node("one");
    Node* sec = new Node("two");
    
    stack1.put_ontop(first);
    cout << stack1.count() << endl;
    
    stack1.put_ontop(sec);
    cout << stack1.count() << endl;
    
    Node* top = stack1.take_top();
    cout << "The top's name is: "<< top->name << endl;
    
    top = stack1.take_top();
    cout << "The top's name is: "<< top->name << endl;
    
    first->next = sec;

    return 0;
}
