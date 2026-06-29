#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createnode (int  data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = nullptr;
    return newnode;
}
int count(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
};
int countleafnode(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        return 1;
    } 
    return countleafnode(root->left) + countleafnode(root->right);
    
};


int main ()
{
        int choice;
        cout << "BINARY SEARCH TREE" << endl;
        cout << "[1] | Sample of tree implementation\n";
        cout << "[2] | Count number of nodes\n";
        cout << "[3] | Count leaf node\n";
        cout << "[0]| EXIT" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            
            case 1:
            {
                cout << "Sample of tree implementation\n";
                Node* root=createnode(10);

                root->left=createnode(7);
                root->right=createnode(15);

                root->left->left=createnode(8);
                root->left->right=createnode(14);

                root->right->right=createnode(17);
                root->right->left=createnode(9);

                cout << "Root: " << root->data << endl;
                cout << "Left subtree: " << root->left->data << endl;
                cout << "Right subtree: " << root->right->data << endl;
                    cout << "   \n";
                cout << "PARENT LEFT" << endl;
                cout << "Level 3 of left subtree: " << root->left->left->data << endl;
                cout << "Level 3 of right subtree: " << root->left->right->data << endl;
                    cout << "   \n";
                cout << "PARENT RIGHT" << endl;
                cout << "Level 3 of left subtree: " << root->right->left->data << endl;
                cout << "Level 3 of right subtree: " << root->right->right->data << endl; 
                break;
            }
            case 2:
            {
                cout << "Count nodes" << endl;
                Node *root=createnode(1);
                root->left=createnode(2);
                root->right=createnode(3);
                root->left->left=createnode(4);
                root->right->right=createnode(5);

                cout << "Number of nodes: " << count(root) << endl;
                break;
            }
            case 3:
            {
                cout << "Count leaf node" << endl;
                Node* root=createnode(5);
                root->left=createnode(3);
                root->right=createnode(6);
                
                root->left->left=createnode(4);

                cout << "Number of leaf node: " << countleafnode(root) << endl;

                break;
            }
            default:
            {
                cout << "INVALID CHOICE" << endl;
            }
            
        }
    
    return 0;
}