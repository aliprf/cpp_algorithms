#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int jump(vector<int> &A);
int minJump(vector<int> &A, int current, vector<int> &jumpHistory);

int main()
{
    vector<int> A = {2, 4, 1, 2, 2, 1, 1}; // {2,3,1,1,4,0}; //{2, 1, 1};//
    cout << jump(A) << "\n\r";
}

int jump(vector<int> &A)
{
    if(A.empty()) return -1;
    if(A.size()==1) return 0;

    vector<int> jumpHistory(A.size());
    for(int i=0; i < jumpHistory.size(); i++) jumpHistory[i]=-2;
    int mJump =minJump(A, 0, jumpHistory);
    return mJump;
}

int minJump(vector<int> &A, int current, vector<int> &jumpHistory)
{
    if(A[current]==0)
    {
        jumpHistory[current] = -1;
        return -1;
    }
    if(current==A.size()) 
    {
        jumpHistory[current] = 0;
        return 0;
    }


    if(A[current]+current >= A.size()-1)
    {
        jumpHistory[current] = 1;
        return 1;
    }
    if(jumpHistory[current] != -2) return jumpHistory[current];
    
    int mJump = 1+minJump(A, current+1, jumpHistory);

    for(int i=2; i<= A[current]; i++)
    {
        int jump = 1 + minJump(A, current+i, jumpHistory);
        
        if (jump<mJump)
            mJump = jump;
        
    }
    jumpHistory[current] = mJump;
    return mJump;
}