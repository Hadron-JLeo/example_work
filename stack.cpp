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
    
    
    
}

int main()
{
    Node* first = new Node("one");
    Node* sec;
    
    first->next = sec;
    
    
    cout<<first->name;

    return 0;
}
