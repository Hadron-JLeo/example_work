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
            
            if (!(is_empty(comp_node) | is_empty(comp_node))) {
                if (input->value > comp_node->value) {
                    return true;
                }
            }
            return false;
        }        
        
        bool is_empty(Node* node_nm) {
            if (node_nm == nullptr){
                return true;
            }
            
            return false;
        }
        
    public:
        Node* head;
        
        Tree() {
            head = nullptr;
        }
        
        void add(Node* node_nm) {
            

            
            if (leaf_amount == 0 || head == nullptr) {
                head = node_nm;
            }
            else {
                Node* cur_node;  // Node to iterate through tree
                cur_node = head; // Start as head
                
                while (cur_node->left != nullptr || cur_node->right != nullptr) 
                {
                    bool result = compare(cur_node, node_nm);
                    switch (result) 
                    {
                        case true: if (!is_empty(cur_node))  { cur_node = cur_node->right; }
                        case false: if (!is_empty(cur_node)) { cur_node = cur_node->left; }
                    }
                    
                }
            }
        }
    
        void search(Node* node_nm) {
        
        }
        
        
};

int main()
{
    
    Tree t1;
    
    Node* first = new Node(1);
    Node* sec = new Node(2);
    Node* tre = new Node(0);
    Node* four = new Node(3);

    t1.add(first);
    //t1.add(tre);

    return 0;
}
