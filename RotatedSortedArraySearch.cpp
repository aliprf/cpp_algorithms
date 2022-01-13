// https://www.interviewbit.com/problems/rotated-sorted-array-search/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int search(const vector<int> &A, int B);
int findPivot(const vector<int> &A, int fromIndex, int toIndex);
int biSearch(const vector<int> A, int fromIndex, int toIndex, int num);

int main()
{
    vector<int> A = {101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100};//{3, 4, 5, 6, 7,8};
    int ans = search(A, 202);
    return ans;
}

int search(const vector<int> &A, int B)
{
    int result = -1;
    int pivot = findPivot(A, 0, A.size() - 1);
    if(pivot == -1)
    {
        return biSearch(A, 0, A.size() - 1, B);;
    }
    else
    {
        if(A[pivot] == B) return pivot;

        //
        vector<int> leftVect(A.begin(), A.begin()+pivot);
        result = biSearch(leftVect, 0, leftVect.size()-1, B);
        
        //
        if(result == -1)
        {
             vector<int> rightVect(A.begin()+pivot, A.begin()+A.size());
             result = biSearch(rightVect, 0, rightVect.size()-1, B);
             if(result != -1) result+=pivot;
        }
            
    }
    return result;
}

int biSearch(const vector<int> A, int fromIndex, int toIndex, int num)
{
    if(fromIndex > toIndex) return -1;

    int mid = (toIndex-fromIndex+1)/2 + fromIndex;
    if(A[mid] == num) return mid;

    if(fromIndex == toIndex) return -1;

    return max(biSearch(A, fromIndex, mid-1, num), biSearch(A, mid, toIndex, num));
}

int findPivot(const vector<int> &A, int fromIndex, int toIndex)
{
    int mid = (fromIndex + toIndex) / 2;

    if (A[mid] > A[fromIndex] && A[mid] < A[toIndex])
    {
        return -1;
    }

    if (toIndex - fromIndex == 0)
    {
        return -1;
    }
    if (toIndex - fromIndex  == 1)
    {
        if (A[toIndex] < A[fromIndex])
            return toIndex;
        return fromIndex;
    }

    if (A[mid] < A[fromIndex] || A[mid] > A[toIndex])
    {

        int lp = findPivot(A, fromIndex, mid);
        int rp = findPivot(A, mid, toIndex);
        return max(lp, rp);
    }
}