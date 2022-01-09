// https://www.interviewbit.com/problems/edit-distance/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int minDistance(string A, string B);
int calculateReplaceCost(string A, string B);
int maxCommonSubstring(string A, string B);

int main()
{
    // cout << minDistance("bbbaabaa", "aababbabb") << "\n\r";
    cout << minDistance("Anshuman", "Antihuman") << "\n\r";
}


int minDistance(string A, string B)
{
    if (A==B) return 0;
    if(A.size()==B.size()) return calculateReplaceCost(A, B);
    int maxCommen = maxCommonSubstring(A, B);
    return max(A.size(), B.size())- maxCommen;
}

int maxCommonSubstring(string mainStr, string patStr)
{
    vector<vector<int>> tbl(patStr.size()+1, vector<int>(mainStr.size()+1));
   
    for(int i=1; i <= patStr.size(); i++)
    {
        for(int j=1; j <= mainStr.size(); j++)
        {
            if(patStr[i] == mainStr[j])
            {
                tbl[i][j] = 1+ tbl[i-1][j-1];
            }
            else
            {
                tbl[i][j] = max(tbl[i-1][j], tbl[i][j-1]);
            }
        }
    }
    return tbl[patStr.size()][mainStr.size()];
}

int calculateReplaceCost(string A, string B)
{
    int cost =0;
    for(int i=0; i< A.size(); i++)
    {
        if(A[i] != B[i]) cost++;
    }
    return cost;
}