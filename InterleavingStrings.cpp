
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int isInterleave(string A, string B, string C);
int match(string A, string B, string C);

int main()
{

    // cout << isInterleave("aabcc", "dbbca","aadbbcbcac") << "\n\r";
    cout << isInterleave("aabcc", "dbbca","aadbbbaccc") << "\n\r";
}


int isInterleave(string A, string B, string C)
{
    int result = match(A,B,C);
    return result;
}

int match(string A, string B, string C)
{
    if (C.size()<=0)
        return 1;
    int cSize = C.size();
    if(A.size()>0 && B.size()>0 && C[cSize-1] == B[B.size()-1] && C[cSize-1] == A[A.size()-1])
    {
        C = C.erase(C.size()-1,1);
        string aTmp =A;
        aTmp.erase(aTmp.size()-1,1);
        string bTmp = B;
        bTmp.erase(bTmp.size()-1,1);

        return max(match(aTmp, B, C) , match(A, bTmp, C));
    }
    else if(B.size()>0 && C[cSize-1] == B[B.size()-1])
    {
        C = C.erase(C.size()-1,1);
        B = B.erase(B.size()-1,1);
        return match(A, B, C);
    }
    else if(A.size()>0 && C[cSize-1] == A[A.size()-1])
    {
        C = C.erase(C.size()-1,1);
        A = A.erase(A.size()-1,1);
        return match(A, B, C);
    }
    return 0;
}