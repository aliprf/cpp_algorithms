#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int maximalRectangle(vector<vector<int> > &A) ;
int calculateRowMax(vector<int> rowIndices, vector<vector<int>> A, int minRow);
int calculateMin(vector<int> maxOfEachRow, vector<int> rowIndices);

int main()
{
    vector<vector<int>> A = {{0,0,0,1},
                             {0,1,0,0},
                             {1,0,0,1},
                             {0,0,1,0}
                             };
    cout << maximalRectangle(A)<< "\n\r";
}

int maximalRectangle(vector<vector<int>> &A) 
{
    vector<int> maxOfEachRow;
    for(int i=0; i< A.size(); i++)
    {
        maxOfEachRow.push_back(calculateRowMax({i}, A, 0));
    }
    int totalMax=maxOfEachRow[0];
    for(int i=0; i< A.size(); i++)
    {
        vector<int> rowIndices={i};
        for(int j=i+1; j< A.size(); j++)
        {
            rowIndices.push_back(j);
            int minRow = calculateMin(maxOfEachRow, rowIndices);
            int tmpM = calculateRowMax(rowIndices, A, minRow);
            if(tmpM >= totalMax)
            {
                totalMax = tmpM;
            }
            else
            {
                break;
            }
        }
    }
    return totalMax;
}

int calculateRowMax(vector<int> rowIndices, vector<vector<int>> A, int minRow)
{
    int total =0;

    if(rowIndices.size()==1)
    {
        for(int i=0; i< A[0].size(); i++)
        {
            int tmpSum =0;
            for(int j=i; j< A[0].size(); j++)
            {
                if(A[rowIndices[0]][i] * A[rowIndices[0]][j] ==1)
                {
                    tmpSum++; //= (j-i+1);
                    if (tmpSum>total) total=tmpSum;
                }
                else
                {
                    if (tmpSum>total) total=tmpSum;
                    break;
                }
            }
        }
        return total;
    }
    else
    {
        for(int i=0; i< A[0].size(); i++)
        {
            int rowSum=1;
            for(int j=0; j< rowIndices.size(); j++)
            {
                rowSum *= A[rowIndices[j]][i];
            }
            total+=rowSum;
        }
        return rowIndices.size()*min(minRow, total);
    }
}

int calculateMin(vector<int> maxOfEachRow, vector<int> rowIndices)
{
    int min=maxOfEachRow[rowIndices[0]];
    for(int i=1; i< rowIndices.size(); i++)
    {
        if(maxOfEachRow[rowIndices[i]]< min)
            min = maxOfEachRow[rowIndices[i]];
    }
    return min;
}