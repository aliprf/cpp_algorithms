#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct myTree
{
    int val;
    myTree *left;
    myTree *right;
};

void createHeap(vector<int> inp, myTree *heap, myTree *curentParent, int paprentIndex);
void heapify(myTree *unsortedHeap);

int main()
{
    //
    myTree *heap = new myTree();
    vector<int> inp ={12, 4, 7, 2, 0, 3, 2, 9, 0, 3};
    createHeap(inp, heap, heap, 0);
    
    heapify(heap);

    cout<< "\n\r";
}

void createHeap(vector<int> inp, myTree *heap, myTree *curentParent, int paprentIndex)
{
    curentParent->val = inp[paprentIndex];

    int leftIndex = 2*paprentIndex+1;
    int rightIndex = 2*paprentIndex+2;

    if(leftIndex<inp.size())
    {
        curentParent->left = new myTree();
        createHeap(inp, heap, curentParent->left, leftIndex);
    }
    if(rightIndex<inp.size())
    {
        curentParent->right = new myTree();
        createHeap(inp, heap, curentParent->right, rightIndex);
    }
}
void heapify(myTree *unsortedHeap)
{
    // int nonLeafIndex = heapSize/2 -1;
    myTree *heap = unsortedHeap;
    

}

myTree * getFirstNonChild(myTree * node)
{
    queue<myTree*> myQue;
    myQue.push(node);

    while(!myQue.empty())
    {
        myTree* cNode = myQue.front();
        myQue.pop();
        if()
    }
    // while(heap->left || heap->right != )
    // {

    // }
}