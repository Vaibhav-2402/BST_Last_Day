// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<queue>

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* createBST(Node* root, int d) {
    if(root == NULL) {
        root = new Node(d);
        return root;
    }
    
    if(d > root -> data) {
        root -> right = createBST(root -> right, d);
    }
    
    if(d < root -> data) {
        root -> left = createBST(root -> left, d);
    }
    
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    
    while(data != -1){
        root = createBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        
        
        if(temp == NULL) {
            //ek level traverse ho chuka hai
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << "  ";
            
            if(temp -> left)
                q.push(temp -> left);
            
            if(temp -> right) 
                q.push(temp -> right);
        }
    }
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root -> left);
    cout << root -> data << "  ";
    inorder(root -> right);
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << "  ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << "  ";
}

Node* minValue(Node* root) {
    Node* temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node* maxValue(Node* root) {
    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp;
}

int main() {
    Node* root = NULL;
    takeInput(root);
    
    levelOrderTraversal(root);
    
    cout << " printing inorder " << endl;
    inorder(root);
    cout << endl;
    
    cout << " printing preorder " << endl;
    preorder(root);
    cout << endl;
    
    cout << " printing postorder " << endl;
    postorder(root);
    cout << endl;

    cout << " minimum value in the tree is : " << minValue(root) -> data << endl;
    cout << " maximum value in the tree is : " << maxValue(root) -> data << endl;

    return 0;
}