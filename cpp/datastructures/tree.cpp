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
            left = NULL;
            right = NULL;
        }
};

// ############################################### -- Class Tree Start -- ############################################# //
class Tree {
    // Value of node_a > node_b -> right leaf
    // Else, left leaf
    
    private:
        int leaf_amount;
        
        bool compare (Node* comp_node, Node* input) {
    
            if ((input->value) > (comp_node->value)) {
                return true;
            }
            else { 
                return false; 
            }
            
        }        
        
        bool is_empty(Node* node_nm) {
            
            if (node_nm == nullptr || node_nm == NULL){
                return true;
            }
            else { return false; }
        }
        
    public:
        Node* head;
        
        Tree() {
            head = nullptr;
            leaf_amount = 0;
        }
        
        int count() {
            return leaf_amount;
        }
        
        int peek() {
            // Look at the head's value
            return head->value;
        }
        
        
        Node* root() {
            // Return the head (root) of tree
            return head;
        }
        
        
        void add(Node* node_nm) {
            if (!is_empty(node_nm)) {
                
                if (head == nullptr) {
                    head = node_nm;
                }
                
                else {
                    Node* next;
                    next = head; // Start as head

                    bool result; 

                    while (true) {
                        
                        if (is_empty(next)) {
                            // if next is a nullptr
                            *next = *node_nm;
                            break;
                        }
                        else {
                            Node* tmp;
                            if (!is_empty(next)) {
                                result = compare(next, node_nm);
                                
                                if (result) {
                                    tmp = next->right;
                                    *next = *tmp;
                                }
                                else {
                                    tmp = next->left;
                                    *next = *tmp;
                                }
                            }
                        }
                    }
                } 
                
                leaf_amount++;
            }
        }
    
        void search(Node* node_nm) {
        
        }
        
        
};  // ################################################# -- Class Tree End -- ############################################### // 

int main()
{
    Tree t1;
    
    Node* first = new Node(1);
    Node* sec = new Node(2);
    Node* tre = new Node(0);
    Node* four = new Node(3);

    t1.add(tre);
    //t1.add(four);
    cout << t1.count() << endl;
    cout << t1.root()->value << endl;
    //cout << t1.root()->right->value << endl;
    //t1.add(tre);

    return 0;
}
