#ifndef MSTACK_H
#define MSTACK_H
#include <iostream>
#include<stdlib.h>
#include <assert.h>

using namespace std;

template <class T>
struct stNode
{
    T data;
    stNode<T>* next;
    stNode(T data1): data(data1), next(NULL){}
};

template <class T>
class mStack
{
    private:
        stNode<T>* topNode;
        stNode<T>* temp;
        int countElements;
    public:
        mStack():topNode(NULL), countElements(0){}
        void push(T data)
        {
            stNode<T>* node = new stNode<T>(data);
            if(topNode == NULL)
                topNode = node;
            else
            {
                temp = topNode;
                topNode = node;
                topNode->next = temp;
            }
            countElements++;
        }
        T pop()
        {
            if(topNode == NULL)
                return NULL;
            temp = topNode;
            topNode = temp->next;
            countElements--;
            return temp->data;
        }
        T getTop()
        {
            if(topNode == NULL)
                return NULL;
            return topNode->data;
        }
        void display()
        {
           assert(topNode != NULL);
           for(temp = topNode; temp !=NULL ;temp = temp->next)
                cout<<temp->data<<" ";
            cout<<endl;
        }
        int size()
        {
            return countElements;
        }
         bool isEmpty()
        {
            if(countElements)
                return false;
            return true;
        }
        ~mStack(){};

};

#endif // MBST_H
