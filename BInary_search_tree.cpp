#include <iostream>
using namespace std;

class IntBinaryTree {
private:
    struct TreeNode {
        int value;
        TreeNode *left;
        TreeNode *right;
    };  

    TreeNode *root;
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *);
    void displayPreOrder(TreeNode *);
    void displayPostOrder(TreeNode *);

public:
    IntBinaryTree(){
        root = NULL; 
    }

    void insertNode(int num);
    bool searchNode(int num);
    bool remove(int num);
    void showNodesInOrder(){
        displayInOrder(root);
    }
    void showNodesPreOrder(){
        displayPreOrder(root);
    }
    void showNodesPostOrder(){
        displayPostOrder(root);
    }
};

void IntBinaryTree::insertNode(int num){

    TreeNode *newNode;
    TreeNode *nodePtr;

    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if(root == nullptr){
        root = newNode;
    }
    else{
        nodePtr = root;
       

        while(nodePtr != nullptr){
         
            if(num < nodePtr->value)
            {
                if(nodePtr->left){
                    nodePtr = nodePtr->left;
                }
                else{
                    nodePtr->left = newNode;
                    break;
                }
            }
            else if(num > nodePtr->value)
            {
                if(nodePtr->right)
                {
                    nodePtr = nodePtr->right;
                }
                else
                {
                    nodePtr->right = newNode;
                    break;
                }
            }
            else
            {
                cout << "Duplicate value. No duplicates allowed." << endl;
                break;
            }
        }
    }
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr)
{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr)
{
    if(nodePtr){
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr)
{
    if(nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}
bool IntBinaryTree::searchNode(int num)
{
    TreeNode *nodePtr = root;

    while(nodePtr){
        if(num == nodePtr->value){
            return true;
        }
        else if(num < nodePtr->value){
            nodePtr = nodePtr->left;
        }
        else{
            nodePtr = nodePtr->right;
        }
    }
    return false;
}

bool IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
    return true;
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if(num < nodePtr->value){
        deleteNode(num, nodePtr->left);
    }
    else if(num > nodePtr->value){
        deleteNode(num, nodePtr->right);
    }
    else{
        makeDeletion(nodePtr);
    }
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr;

    if(nodePtr == NULL)
    {
        cout << "Cannot delete empty node." << endl;
    }
    else if(nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if(nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    else
    {
        tempNodePtr = nodePtr->right;

        while(tempNodePtr->left)
        {
            tempNodePtr = tempNodePtr->left;
        }

        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;

        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

int main(){

    IntBinaryTree tree;
    cout << "Inserting nodes. . ." << endl;
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);      
    tree.insertNode(12);
    tree.insertNode(9);
    cout << "Done. . ." << endl;

    cout << "In-order traversal. . ." << endl;
    tree.showNodesInOrder();
    cout << "Pre-order traversal. . ." << endl;
    tree.showNodesPreOrder();
    cout << "Post-order traversal. . ." << endl;
    tree.showNodesPostOrder();
    
    if(tree.searchNode(3)){
        cout << "Node found." << endl;
    }
    else{
        cout << "Node not found." << endl;
    }

    tree.remove(8);
    tree.remove(12);

    cout << "Now, here are the nodes" << endl;
    tree.showNodesInOrder();

    return 0;
}