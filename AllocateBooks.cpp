// https://www.interviewbit.com/problems/allocate-books/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;
int books(vector<int> &A, int B);
int maxCom(vector<int> A, int numLeft, int maxAlloc);
int calcSum(vector<int> A, int fromIndex, int toIndex);

int main()
{
    vector<int> A = {73, 58, 30, 72, 44, 78, 23, 9 }; //{3, 4, 5, 6, 7,8};
    int B = 5;
    int ans = books(A, B);
    return ans;
}

int books(vector<int> &A, int B)
{
    vector<vector<vector<int>>> allCombinations;

    int maxAlloc = A.size() - B+1; //(A.size() + B - 1) / B; // 1 + A.size() / B;

    int maxim = maxCom(A, B, maxAlloc);
    cout << maxim << "\n\r";
    return maxim;
}

int maxCom(vector<int> A, int numLeft, int maxAlloc)
{
    if (numLeft == 1)
        return calcSum(A, 0, A.size());

    vector<int> sumations;
    vector<int> tmpVec = A;
    for (int i = 1; i <= maxAlloc; i++)
    {
        tmpVec.erase(tmpVec.begin());
        int t1 = calcSum(A, 0, i);
        int t2 = maxCom(tmpVec, numLeft-1, maxAlloc - i);
        sumations.push_back(max(t1, t2));
    }
    if(sumations.empty()) return 0;
    int minim = sumations[0];
    for (int i = 1; i < sumations.size(); i++)
        if (sumations[i] < minim)
            minim = sumations[i];
    return minim;
}

int calcSum(vector<int> A, int fromIndex, int toIndex)
{
    int sum = 0;
    for (int i = fromIndex; i < toIndex; i++)
        sum += A[i];
    return sum;
}