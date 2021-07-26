#include <iostream>
#include "mBST.h"
#include "mDequeue.h"
#include "mLL.h"
#include "mStack.h"

using namespace std;

int main()
{
    //Bst Test
    mBST<int> mb;
    for(int i=0;i<10 ;i++)
        mb.insert(i);
    mb.inOrderPrint();
    cout<<"************\n";
    mb.preOrderPrint();
    cout<<"************\n";
    mb.postOrderPrint();
    cout<<"************\n";
    mb.decOrderPrint();
    cout<<"************\n";
    mb.levelOrderPrint();
    cout<<"************\n";
    mb.printInorderSuccessor(5);
    cout<<"************\n";
    cout<<mb.mnN();
    cout<<"\n************\n";
    cout<<mb.mxN();
    cout<<"\n************\n";
    cout<<mb.mxHeight();
    cout<<"\n************\n";

  return 0;
}
