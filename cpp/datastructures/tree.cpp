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
            return false; 
        }        
        
        void change_node_content(Node* a, Node* b) {
            Node old_a = *a;
            *a = *b;
            *b = old_a;
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
                int cur_depth = 0;
            
                if (head == nullptr) {
                    head = node_nm;
                }
                
                else {
                    Node* cur_node;
                    Node* next;
                    cur_node = head; // Start as head
                    
                    bool result; 

                    
                    while (true) {
                        result = compare (cur_node, node_nm);
                        cur_depth++;
                        if (result) {
                            // if bigger
                            next = cur_node->right;
                            //cur_depth++;
                            if (is_empty(next)) {
                                cur_node->right = node_nm;
                                cur_node->right->depth = cur_depth;
                                break;
                            }
                        }
                        else {
                            next = cur_node->left;
                            //cur_depth++;
                            if (is_empty(next)) {
                                cur_node->left = node_nm;
                                cur_node->left->depth = cur_depth;
                                break;
                            }
                        }
                        
                        cur_node = next;
                        continue;
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
    
    Node* n0 = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    t1.add(n2);
    t1.add(n1);
    t1.add(n3);
    t1.add(n0);
    cout << "Leaf Amount: " << t1.count() << endl;
    cout << t1.root()->depth << endl;
    cout << t1.root()->right->depth << endl;
    cout << t1.root()->left->left->depth << endl;
    //t1.add(tre);

    return 0;
}
