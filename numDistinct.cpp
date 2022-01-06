#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int numDistinct(string A, string B);
vector<vector<int>> generateTable(string mainStr, string patStr);
int calculateCombination(vector<vector<int>> tbl, string patStr);
int fact(int n);

int main()
{
//    cout << numDistinct("abarabbbit", "rabbit") << "\n\r";
//    cout << numDistinct("abbccaa", "bcaa") << "\n\r";
   cout << numDistinct("aaaababbababbaabbaaababaaabbbaaabbb", "bbababa") << "\n\r";
}


int numDistinct(string A, string B)
{
    if(A == B) return 1;
    if(A.size() < B.size()) return 0;
    vector<vector<int>> tbl = generateTable(A, B);

    return calculateCombination(tbl, B);
}

vector<vector<int>> generateTable(string mainStr, string patStr)
{
    // vector<vector<int>> tbl(patStr.size(), vector<int>(mainStr.size()));
    vector<vector<int>> indicesTbl;
    int firstOccurance = -1;
    for(int i=0; i<patStr.size(); i++) // row
    {
        vector<int> rowInd;
        bool first=true;
        for(int j=0; j<mainStr.size(); j++) // col
        {
            if(patStr[i]==mainStr[j] && j>=firstOccurance)
            {
                // tbl[i][j] =1;
                rowInd.push_back(j);
                if(first)
                {
                    first=false;
                    firstOccurance = j;
                }
            }
            // else
            // {
            //     tbl[i][j] =0;
            // }
        }
        indicesTbl.push_back(rowInd);
    }
    return indicesTbl;
}
int calculateCombination(vector<vector<int>> tbl, string patStr)
{
    int cnt=1;
    for(int i=0; i<patStr.size();i++)
    {
        if( i+1 < patStr.size() && patStr[i]==patStr[i+1])
        {
            int r = 1;
            int j= i+1;
            while (j>=i+1 && patStr[i]==patStr[j])
            {
                r++;
                j++;
            }
            int com = fact(tbl[i].size()) / (fact(r)*fact(tbl[i].size()-r));
            cnt*=com;
            i=j;
        }
        else
            cnt*= tbl[i].size() ;
    }
    return cnt;
}

int fact(int n){

     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}