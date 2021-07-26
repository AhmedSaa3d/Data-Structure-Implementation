#ifndef MLL_H
#define MLL_H
#include <iostream>
#include<stdlib.h>

using namespace std;

template <class T>
struct llNode
{
    T data;
    llNode<T>* next;
    llNode(T data1): data(data1), next(NULL){}
};

template <class T>
class mLL
{
    private:
        llNode<T>* first;
        llNode<T>* last;
        llNode<T>* temp;
        int countElements;
        void displayRev(llNode<T>* node)
        {
            if(node == NULL)
                return;
            displayRev(node->next);
            cout<<(node->data)<<endl;
        }
        void mReverse(llNode<T>* node)
        {
           if(first == last)
                return;
           llNode<T> *current,*prev, *next;
           current = first;
           prev = NULL;
           while(current != NULL)
           {
               next = current->next;
               current->next = prev;
               prev = current;
               current = next;
           }
           temp = first;
           first = last;
           last = temp;
        }
    public:
        mLL():first(NULL),last(NULL), countElements(0){}
        void insert(T data)
        {
            llNode<T>* node = new llNode<T>(data);
            if(first == last && first == NULL)
                {
                    first = node;
                    last = node;
                }
            else if(first == last)
            {
                last = node;
                first->next = last;
            }
            else
            {
                temp = last;
                last = node;
                temp->next = last;
            }
            countElements++;
        }
        void insertAt(T data, int indx)
        {
            if(indx > countElements)
                return;
            else if(countElements == 0 || indx == countElements)
                {
                    insert(data);
                    return;
                }
            llNode<T>* node = new llNode<T>(data);
            if(indx == 0)
            {
                node->next = first;
                first = node;
            }
            else
            {
                temp = first;
                for(int i = 0 ; i<indx - 1 ; i++)
                    temp = temp->next;
                node->next = temp->next;
                temp->next = node;
            }
            countElements++;
        }
        void insertFirst(T data)
        {
            insertAt(data,0);
        }
        void display()
        {
           for(temp = first; temp !=NULL ;temp = temp->next)
                cout<<temp->data<<" ";
            cout<<endl;
        }
        void deleteAt(int indx)
        {
            if(indx > countElements)
                return;
            else if(first == last && indx == 0)
                first = last = NULL;
            else if(indx == 0)
            {
                temp = first;
                first = first->next;
                free(temp);
            }
            else
            {
                temp = first;
                for(int i=0;i<indx - 1;i++)
                    temp = temp->next;
                llNode<T>* temp2 = temp->next;
                temp->next = temp2->next;
                if(countElements == indx+1)
                    last = temp;
                free(temp2);
            }
            countElements--;
        }

        void displayReverse()
        {
            displayRev(first);
        }
        void reverse()
        {
            mReverse(first);
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
        ~mLL(){};

};

#endif // MBST_H
