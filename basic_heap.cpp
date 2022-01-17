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
myTree * getFirstNonChild(myTree * node);

//vector
void heapify(vector<int> &inpVec);
int findSibling(int cIndex, int vecSize);
void swapByIndex(int parentIndex, int maxChildIndex, vector<int> &inpVec);
int getLargerIndex(vector<int>  inpVec, int lChildIndex, int rChildIndex);
int findGreatestChild(vector<int> inpVec, int currentIndex);

void insertToHeap(int item, vector<int> &inpVec);

int main()
{
    //TREE
    myTree *heap = new myTree();
    vector<int> inp = {8, 2, 1, 6}; //{1, 4, 7, 2, 0, 3, 2, 9, 0, 3,0,12}; //
    // createHeap(inp, heap, heap, 0);
    // heapify(heap);

    ///vector
    heapify(inp);

    // insert:
    vector<int> x={5,8,3,10};
    for(int i=0; i<x.size(); i++)
    {
        insertToHeap(x[i], inp);
        cout<< "\n\r";        
    }
    cout<< "\n\r";
}

void insertToHeap(int item, vector<int> &inpVec)
{
    // insert to the right-most child, and heapify
    inpVec.push_back(item);
    heapify(inpVec);
}
///this section is with vector:
void heapify(vector<int> &inpVec)
{
        //find the last non-leaf
    int lastNonLeafIndex = inpVec.size()/2 -1;
    int gIndex;
    for(int i=lastNonLeafIndex; i>=0; i--)
    {
        int lChildIndex;
        int rChildIndex;
        2*i+1< inpVec.size() ?  lChildIndex = 2*i+1 : lChildIndex =-1;
        2*i+2< inpVec.size() ?  rChildIndex = 2*i+2 : rChildIndex =-1;

        int maxChildIndex  = getLargerIndex(inpVec, lChildIndex, rChildIndex);
        if(maxChildIndex != -1) 
        {
            if(inpVec[i] < inpVec[maxChildIndex])
            {
                gIndex = findGreatestChild(inpVec, i);

                swapByIndex(i, gIndex, inpVec);
                if(gIndex<=lastNonLeafIndex)
                    i =gIndex+1;
            }
        }
    }
}
int findGreatestChild(vector<int> inpVec, int currentIndex)
{
    int parent = inpVec[currentIndex];
    int maxIndex = -1, maxVal = parent;
    queue<int> indicesQ;

    indicesQ.push(currentIndex);
    while (!indicesQ.empty())
    {
        int tmp = indicesQ.front();
        if(inpVec[tmp] > maxVal)
        {
            maxIndex = tmp;
            maxVal = inpVec[tmp];
        }
            
        indicesQ.pop();

        if(2*tmp+1 < inpVec.size())  indicesQ.push(2* tmp+1);
        if(2*tmp+2 < inpVec.size())  indicesQ.push(2* tmp+2);
    }
    return maxIndex;
}

int getLargerIndex(vector<int>  inpVec, int lChildIndex, int rChildIndex)
{
    int gIndex;
    if(rChildIndex!=-1 && lChildIndex!=-1) 
    {
        inpVec[lChildIndex] > inpVec[rChildIndex] ? gIndex= lChildIndex : gIndex= rChildIndex;
    }
    else if(lChildIndex != -1)
    {
        gIndex= lChildIndex;
    }
    else
    {
        gIndex= rChildIndex;
    }
    return gIndex;
}
void heapifyNotCorrect(vector<int> &inpVec)
{
    //find the last non-leaf
    int lastNonLeafIndex = inpVec.size()/2 -1;

    for(int i=lastNonLeafIndex; i>=0; i--)
    {
        int parentIndex= (i-1)/2;
        int siblingIndex = findSibling(i, inpVec.size());
        int maxChild, maxChildIndex;
        if(siblingIndex!=-1) 
        {
            if(inpVec[siblingIndex] < inpVec[i])
            {
                maxChild = inpVec[i]; 
                maxChildIndex = i;
            }
            else
            {
                maxChild = inpVec[siblingIndex]; 
                maxChildIndex = siblingIndex;
            }
        }
        else
        {
            maxChild =  inpVec[i];
            maxChildIndex = i;
        } 

        if (inpVec[parentIndex] < maxChild) swapByIndex(parentIndex, maxChildIndex, inpVec);
    }
}

int findSibling(int cIndex, int vecSize)
{
    if(cIndex%2==0) // left
    {
        return cIndex-1;
    }
    else // right
    {
        if(cIndex+1 < vecSize)
            return cIndex+1;
        return -1;
    }
}

void swapByIndex(int parentIndex, int maxChildIndex, vector<int> &inpVec)
{
    int tmp = inpVec[parentIndex];
    inpVec[parentIndex] = inpVec[maxChildIndex];
    inpVec[maxChildIndex] = tmp;
}
/// this section is with list:
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
    heap = getFirstNonChild(heap);

    cout << heap->val<<"\r\n";
}

myTree * getFirstNonChild(myTree * node)
{
    queue<myTree*> myQue;
    myQue.push(node);

    while(!myQue.empty())
    {
        myTree* cNode = myQue.front();
        myQue.pop();
        if(cNode->left !=NULL and cNode->right!= NULL)
        {
            myQue.push(cNode->left);
            myQue.push(cNode->right);
        }
        else
        {
            return cNode;
        }
    }
}