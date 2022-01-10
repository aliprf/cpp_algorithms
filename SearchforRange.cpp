#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

vector<int> searchRange(const vector<int> &A, int B);
void search(vector<int> A, int num, int &startIndex, int &endIndex, int fromIndex, int toIndex);

int main()
{
    vector<int> A = {5, 7, 7, 8, 8, 10};
    vector<int> ans = searchRange(A, 8);
    return -1;
}

vector<int> searchRange(const vector<int> &A, int B)
{
    int startIndex =-1, endIndex=-1;

    search(A, B, startIndex, endIndex, 0, A.size()-1);
    return {startIndex, endIndex};
}

void search(vector<int> A, int num, int &startIndex, int &endIndex, int fromIndex, int toIndex)
{
    if(fromIndex<0 && toIndex >= A.size())
        return;

    int mid = (fromIndex+toIndex)/2;

    if(A[mid] == num)
    {
        if (startIndex != -1)
        {
            endIndex = mid;
            return;
        }
        startIndex = mid; // then, find end
        search(A, num, startIndex, endIndex, fromIndex, mid-1);
        search(A, num, startIndex, endIndex, mid+1, toIndex);
        return;
    }

    if(num < A[mid])
    {
        toIndex = mid -1;
        search(A, num, startIndex, endIndex, fromIndex, toIndex);
    }
    else if(num > A[mid])
    {
        fromIndex = mid +1;
        search(A, num, startIndex, endIndex, fromIndex, toIndex);
    }
}