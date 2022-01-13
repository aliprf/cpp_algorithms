#include <iostream>
#include <vector>
#include <string>

using namespace std;

// merge sort
vector<int> mergeSort(vector<int> inputVec);
vector<int> combine(vector<int> lVec, vector<int> rVec);

///
void quieckSort(vector<int> &inputVec, int left, int right);
int reshapeVector(vector<int> &inputVec, int left, int right);

int main()
{
    vector<int> sorted0 = mergeSort({12, 4, 7, 2, 0, 3, 2, 9});

    //
    vector<int> inp ={12, 4, 7, 2, 0, 3, 2, 9, 0, 3};
    quieckSort(inp, 0, inp.size()-1);
    cout<< "\n\r";
}

//////////////////////////////////////////////////////////////////
///////////////////////  quieckSort   ////////////////////////////
//////////////////////////////////////////////////////////////////

int reshapeVector(vector<int> &inputVec, int left, int right)
{
    // reshape the inputVector and return pivot index
    int pivotValue = inputVec[right];
    
    vector<int> reshaped(inputVec);

    int lIndex=left, rIndex= right;
    for(int i=left; i< right; i++)
    {
        if(inputVec[i] < pivotValue)
        {
            reshaped[lIndex] = inputVec[i];
            lIndex++;
        }
        else
        {
            reshaped[rIndex] = inputVec[i];
            rIndex--;
        }
    }
    reshaped[lIndex] = pivotValue;
    inputVec = reshaped;
    return lIndex;
}

void quieckSort(vector<int> &inputVec, int left, int right)
{
    if(left >= right)
        return;
    
    int pivotIndex = reshapeVector(inputVec, left, right);
    quieckSort(inputVec, left, pivotIndex-1);
    quieckSort(inputVec, pivotIndex+1, right);
}

//////////////////////////////////////////////////////////////////
///////////////////////  mergeSort      ////////////////////////////
//////////////////////////////////////////////////////////////////
vector<int> mergeSort(vector<int> inputVec)
{
    if(inputVec.size()<=1)
        return inputVec;

    int mid = (0+ inputVec.size()) /2;

    vector<int> lVec(inputVec.begin(), inputVec.begin()+ mid);
    vector<int> rVec(inputVec.begin() + mid, inputVec.begin()+inputVec.size());

    vector<int> lSorted = mergeSort(lVec);
    vector<int> rSorted = mergeSort(rVec);

    vector<int> sorted = combine(lSorted, rSorted);
    return sorted;
}
vector<int> combine(vector<int> lVec, vector<int> rVec)
{
    /* combine two sorted vectors*/
    int rSize = rVec.size();
    int lSize = lVec.size();
    vector<int> sorted;

    int lIndex=0, rIndex =0;
    while(lIndex < lSize || rIndex < rSize)
    {
        if(lIndex< lSize && rIndex<rSize)
        {
            if(rVec[rIndex] < lVec[lIndex])
            {
                sorted.push_back(rVec[rIndex]);
                rIndex++;
            }
            else if(rVec[rIndex] > lVec[lIndex])
            {
                sorted.push_back(lVec[lIndex]);
                lIndex++;
            }
            else
            {
                sorted.push_back(rVec[rIndex]);
                rIndex++;
                sorted.push_back(lVec[lIndex]);
                lIndex++;
            }
        }
        else if(rIndex< rVec.size())
        {
            sorted.push_back(rVec[rIndex]);
            rIndex++;
        }
        else if(lIndex< lVec.size())
        {
            sorted.push_back(lVec[lIndex]);
            lIndex++;
        }
    }
    return sorted;
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////