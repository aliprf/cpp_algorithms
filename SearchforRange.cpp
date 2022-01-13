// https://www.interviewbit.com/problems/search-for-a-range/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

vector<int> searchRange(const vector<int> &A, int B);
void search(vector<int> A, int num, int fromIndex, int toIndex);
int startIndex=-1, endIndex=-1;

int main()
{
    vector<int> A = {5, 7, 4, 7, 8, 8, 10};
    vector<int> ans = searchRange(A, 7);
    return -1;
}

vector<int> searchRange(const vector<int> &A, int B)
{
    search(A, B, 0, A.size() - 1);
    return {startIndex, endIndex};
}

void search(vector<int> A, int num, int fromIndex, int toIndex)
{
    if (fromIndex > toIndex )
        return;

    int mid = (fromIndex + toIndex) / 2;

    if (A[mid] == num)
    {
        if (startIndex != -1)
        {
            endIndex = mid;
            return;
        }
        startIndex = mid; // then, find end
        search(A, num, fromIndex, mid - 1);
        search(A, num, mid + 1, toIndex);
        return;
    }

    if (num < A[mid])
    {
        toIndex = mid - 1;
        search(A, num, fromIndex, toIndex);
    }
    else if (num > A[mid])
    {
        fromIndex = mid + 1;
        search(A, num, fromIndex, toIndex);
    }
}