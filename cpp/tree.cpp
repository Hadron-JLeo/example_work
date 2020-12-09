/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Node {
    // This class has right and left leaves
    public:
        // string name; // Name/Info 
        int depth;   // Depth of the tree
        int value;
        
        Node* left;  // Smaller
        Node* right; // Bigger
        
        Node(int val = 0) {
            value = val;
            left = nullptr;
            right = nullptr;
        }
};

class Tree {
    // Value of node_a > node_b -> right leaf
    // Else, left leaf
    
    private:
        int leaf_amount;
        
        bool compare (Node* comp_node, Node* input) {
            
            if (input.value > comp_node.value) {
                return true;
            }
            
            return false;
        }        
        
    public:
        Node* head;
        
        void add(Node* node_nm) {
            Node* cur_node;  // Node to iterate through tree
            cur_node = head; // Start as head
            
            while ((cur_node->left != nullptr || cur_node->right != nullptr) 
                    && cur_node != nullptr) 
            {
                bool result = compare(cur_node, node_nm)
                switch (result) {
                    case true: cur_node = cur_node->right;
                    case false: cur_node = cur_node->left;
                }
                
                cur_node = cur_node->next;
            }
            
        }
    
        void search(Node* node_nm) {
        
        }
        
        
}

int main()
{

    
    Node* first = new Node("one");
    Node* sec = new Node("two");
    Node* tre = new Node("three");
    Node* four = new Node("four");

    q1.append(sec);

    
    cout << q1.pop()->name << endl;
    cout << q1.pop()->name << endl;
    

    return 0;
}
