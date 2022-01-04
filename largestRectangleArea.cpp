#include <iostream>
#include <vector>
#include <string>

using namespace std;

int largestRectangleArea(vector<int>& heights);
vector<int> findMinIndiceas(vector<int> inputVector);
int findmim(vector<int> inputVector);
int calculateArea(vector<int>& inputVector);
int findmaximArea(vector<int> inputVector, int &maxim);
vector<int> splitArray(vector<int> inputVector,int from, int to);

int main()
{
    vector<int> height = {2,4,5};//{2,1,5,6,2,3};
    int maxim = largestRectangleArea(height);

    cout <<"maxim => "<< maxim << "\n\r";
}

vector<int> findMinIndiceas(vector<int> inputVector)
{
    vector<int> indices;
    indices.push_back(0);

    int min = inputVector[0];
    for(int i=1; i< inputVector.size(); i++)
        if(min>inputVector[i]) min = inputVector[i];

    for(int i=0; i< inputVector.size(); i++)
        if(inputVector[i] == min) indices.push_back(i);

    indices.push_back(inputVector.size()-1);

    return indices;
}

int findmim(vector<int> inputVector)
{
    int min = inputVector[0];
    for(int i=1; i< inputVector.size(); i++)
        if(min>inputVector[i]) min = inputVector[i];
    return min;
}

int calculateArea(vector<int>& inputVector)
{
    return inputVector.size() * findmim(inputVector);
}

int largestRectangleArea(vector<int>& heights)
{   
    int maxim =0;
    return findmaximArea(heights, maxim);

}

vector<int> splitArray(vector<int> inputVector,int from, int to)
{
    vector<int> vec;

    for(int i=from; i< to; i++)
        vec.push_back(inputVector[i]);
    
    return vec;
}


int findmaximArea(vector<int> inputVector, int &maxim)
{
    if(inputVector.empty())
        return 0;

    if(inputVector.size()==1)
        return calculateArea(inputVector);

    int _m = calculateArea(inputVector);
    maxim = max(maxim, _m);

    vector<int> minIndices = findMinIndiceas(inputVector);

    for(int i=0; i<minIndices.size()-1; i++)
    {   
        int from = minIndices[i];
        int to = minIndices[i+1];

        vector<int> vec = splitArray(inputVector, from, to);
        int h = findmaximArea(vec, maxim);
        if(h > maxim) maxim = h;
    }

    return maxim;
}
