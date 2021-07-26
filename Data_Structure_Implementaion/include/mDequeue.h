#ifndef MDEQUEUE_H
#define MDEQUEUE_H

#include <iostream>
#include<stdlib.h>

using namespace std;

template <class T>
struct deNode
{
    T data;
    deNode<T>* next;
    deNode(T data1): data(data1), next(NULL){}
};

template <class T>
class mDequeue
{
    private:
        deNode<T>* first;
        deNode<T>* last;
        deNode<T>* temp;
        T var;
        int countElements;
        T deleteAt(int indx)
        {
           if(first == last && indx == 0)
                first = last = NULL;
            else if(indx == 0)
            {
                temp = first;
                first = temp->next;
                var = temp->data;
                free(temp);
            }
            else
            {
                temp = first;
                for(int i=0;i<indx - 1;i++)
                    temp = temp->next;
                deNode<T>* temp2 = temp->next;
                temp->next = temp2->next;
                if(countElements == indx+1)
                    last = temp;
                var = temp2->data;
                free(temp2);
            }
            countElements--;
            return var;
        }
    public:
        mDequeue():first(NULL),last(NULL), countElements(0){}
        void push_front(T data)
        {
            deNode<T>* node = new deNode<T>(data);
            if(first == last && first == NULL)
            {
                first = node;
                last = node;
            }
            else
            {
                node->next = first;
                first = node;
            }
            countElements++;
        }
        void push_back(T data)
        {
            deNode<T>* node = new deNode<T>(data);
            if(first == last && first == NULL)
            {
                first = node;
                last = node;
            }
            else
            {
                last->next = node;
                last = node;
            }
            countElements++;
        }
        T getFront()
        {
            return first->data;
        }
        T getTail()
        {
            return last->data;
        }
        void display()
        {
           for(temp = first; temp !=NULL ;temp = temp->next)
                cout<<temp->data<<" ";
            cout<<endl;
        }
        T pop_front()
        {
            if(countElements == 0)
                return NULL;
            return deleteAt(0);
        }
        T pop_back()
        {
            if(countElements == 0)
                return NULL;
            return deleteAt(countElements-1);
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
        ~mDequeue(){};

};

#endif // MBST_H
