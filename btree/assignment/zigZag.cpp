/*
ZigZag tree
Send Feedback
Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/

#include "../BinaryTreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    while(s1.size() != 0 || s2.size() != 0){
        while(s1.size() != 0){
            BinaryTreeNode<int>* n = s1.top();
            s1.pop();
            cout<<n->data<<" ";
            
            if(n->left)
                s2.push(n->left);
            
            if(n->right)
                s2.push(n->right);
        }
        cout<<endl;
        while(s2.size() != 0){
            BinaryTreeNode<int>* n = s2.top();
            s2.pop();
            cout<<n->data<<" ";
            
            if(n->right)
                s1.push(n->right);
            
            if(n->left)
                s1.push(n->left);
        }
        cout<<endl;
    }
}


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
