#ifndef MBST_H
#define MBST_H
#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct bstNode{
        T data;
        bstNode *left;
        bstNode *right;
        bstNode(T data1): data(data1), left(NULL), right(NULL) {}
        };

template <class T>
class mBST
{
private:
    bstNode<T>* root;
    void insert(bstNode<T>* treeNode, T data)
    {
        if(treeNode == NULL)
        {
            treeNode = new bstNode<T>(data);
            root = treeNode;
        }
        else
        {
            if(data <= treeNode->data)
            {
                if(treeNode->left == NULL)
                    treeNode->left = new bstNode<T>(data);
                else
                    insert(treeNode->left,data);
            }
            else if(data > treeNode->data)
            {
                if(treeNode->right == NULL)
                    treeNode->right = new bstNode<T>(data);
                else
                    insert(treeNode->right, data);
            }
        }
    }
    void inOrderPrint(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return;
        inOrderPrint(treeNode->left);
        cout<<treeNode->data<<endl;
        inOrderPrint(treeNode->right);
    }
    void preOrderPrint(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return;
        cout<<treeNode->data<<endl;
        preOrderPrint(treeNode->left);
        preOrderPrint(treeNode->right);
    }
    void postOrderPrint(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return;
        postOrderPrint(treeNode->left);
        postOrderPrint(treeNode->right);
        cout<<treeNode->data<<endl;
    }
    void decOrderPrint(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return;
        decOrderPrint(treeNode->right);
        cout<<treeNode->data<<endl;
        decOrderPrint(treeNode->left);
    }
    T mnN(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return NULL;
        else if(treeNode->left == NULL)
            return treeNode->data;
        return mnN(treeNode->left);
    }
    T mxN(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return NULL;
        else if(treeNode->right == NULL)
            return treeNode->data;
        return mxN(treeNode->right);
    }
    int mxHeight(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return -1; //return 0->means count nodes ; return -1->means count edges;
        return max(mxHeight(treeNode->left), mxHeight(treeNode->right)) + 1;
    }
    bstNode<T>* deleteNode(bstNode<T>* treeNode, T data)
    {
        if(treeNode == NULL)    return treeNode;
        else if(data < treeNode->data) treeNode->left = deleteNode(treeNode->left, data);
        else if(data > treeNode->data) treeNode->right = deleteNode(treeNode->right, data);
        else if(data == treeNode->data)
        {
            if(treeNode->left == NULL && treeNode->right) //case : has n't any child
            {
                delete treeNode->left;
                treeNode->left = NULL;
            }
            else if(treeNode->left == NULL) //case2 : has right child only
            {
                bstNode<T>* temp = treeNode;
                treeNode = treeNode->right;
                delete temp;
                temp = NULL;
            }
            else if(treeNode->right == NULL) //case2 : has left child only
            {
                bstNode<T>* temp = treeNode;
                treeNode = treeNode->left;
                delete temp;
                temp = NULL;
            }
            else //case3 : has 2 children
            {
                bstNode<T>* temp = treeNode->right;
                while(temp->left != NULL) //get min node in right side
                    temp = temp->left;
                treeNode->data = temp->data;
                treeNode->right = deleteNode(treeNode->right, temp->data);
            }
        }
        return treeNode;
    }
    bstNode<T>* findNode(bstNode<T>* treeNode,T data)
    {
        if(treeNode == NULL)
            return NULL;
        if(data < treeNode->data)
            return findNode(treeNode->left, data);
        else if(data > treeNode->data)
            return findNode(treeNode->right, data);
        return treeNode;
    }
    T findLowestCommonAncestor(bstNode<T>* treeNode, T data1, T data2)
    {
        if(treeNode == NULL)
            return NULL;
        else if(data1 == treeNode->data || data2 == treeNode->data)
            return treeNode->data;
        else if((data1 <= treeNode->data && data2 > treeNode->data)
                  || (data2 <= treeNode->data && data1 > treeNode->data))
            return treeNode->data;
        else if(treeNode->data > data1 && treeNode->data > data2)
            return findLowestCommonAncestor(treeNode->left, data1, data2);
        return findLowestCommonAncestor(treeNode->right, data1, data2);
    }
    bool isBalanced(bstNode<T>* treeNode)
    {
        if(treeNode == NULL)
            return true;
        int leftHeight = mxHeight(treeNode->left);
        int rightHeight = mxHeight(treeNode->right);
        if(leftHeight == rightHeight)
            return true;
        return false;
    }
public:
    int countElements;
    mBST():root(NULL),countElements(0){}
    void insert(T data){countElements++;insert(root, data);};
    void inOrderPrint(){inOrderPrint(root);};
    void preOrderPrint(){preOrderPrint(root);};
    void postOrderPrint(){postOrderPrint(root);};
    void decOrderPrint(){decOrderPrint(root);};
    void levelOrderPrint()
    {
        if(root == NULL)
            return;
        queue<bstNode<T>*> qN;
        bstNode<T>* treeNode;
        qN.push(root);
        while(!qN.empty())
        {
            treeNode = qN.front();
            cout<<treeNode->data<<endl;
            if(treeNode->left)
                qN.push(treeNode->left);
            if(treeNode->right)
                qN.push(treeNode->right);
            qN.pop();
        }
    }
    T mnN(){return mnN(root);};
    T mxN(){return mxN(root);};
    int mxHeight(){return mxHeight(root);};
    void deleteNode(T data){deleteNode(root,data);};
    void printInorderSuccessor(T data)
    {
        bstNode<T>* temp = findNode(root, data);
        if(temp == NULL)
            return;
        inOrderPrint(temp);
    }
    bool searchNode(T data)
    {
        bstNode<T>* temp = findNode(root, data);
        if(temp == NULL)
                return false;
        return true;
    }
    T findLowestCommonAncestor(T data1, T data2)
    {
        if(findNode(root, data1) != NULL && findNode(root, data2) != NULL)
             return findLowestCommonAncestor(root, data1,data2);
        return NULL;
    }
    bool isBlanced(){return isBalanced(root);};
    T getRoot()
    {
        return root->data;
    }
    bool isEmpty()
    {
        if(countElements)
            return false;
        return true;
    }
    int size()
    {
        return countElements;
    }

    ~mBST(){};

};

#endif // MBST_H
