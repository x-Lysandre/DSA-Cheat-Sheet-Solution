#include "bits/stdc++.h"
using namespace std;
/*
<root> left right - Pre order
left <root> right - In order
left right <root> - Post order
*/

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildBinaryTree(node* root){
    cout<<"Enter the data for "<< root<<": "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    //base case
    if(data == -1){
        return NULL;
    }

    cout<<"For Left node: "<<endl;
    root->left = buildBinaryTree(root->left);
    cout<<"For Right node: "<<endl;
    root->right = buildBinaryTree(root->right);
    return root;

}

//level order traversal 
void Levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        if(q.front() == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            q.pop();
        }
    }
}

void Preorder(node* root){
    //root left right

    node* temp = root;
    //base case
    if( temp == NULL){
        return;
    }

    cout<< temp->data<<" ";
    Preorder(temp->left);
    Preorder(temp->right);
}

void Inorder(node* root){
    // left root right

    node* temp = root;
    //base case
    if(temp == NULL){
        return;
    }
    Inorder(temp->left);
    cout<<temp->data<<' ';
    Inorder(temp->right);
}

void Postorder(node* root){
    //left right root

    node* temp = root;
    //base case
    if(temp == NULL){
        return;
    }
    Postorder(temp->left);
    Postorder(temp->right);
    cout<<temp->data<<' ';
}


int main(){

    node* root = NULL;

    // 5 3 1 -1 -1 2 -1 -1 7 9 -1 -1 8 -1 -1

    //Creating the binary tree
    root = buildBinaryTree(root);

    cout<<"Level order traversal: "<< endl;
    Levelorder(root);
    cout<<endl;

    cout<<"Pre order traversal: "<< endl;
    Preorder(root);
    cout<<endl;

    cout<<"In order traversal: "<< endl;
    Inorder(root);
    cout<<endl;

    cout<<"Post order traversal: "<< endl;
    Postorder(root);
    cout<<endl;

    return 0;
}