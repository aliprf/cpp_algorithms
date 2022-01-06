#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;
int minCut(string A);
vector<vector<int>> createIndices(string str);
vector<char> findDistinctChars(string str);
int findMaxPalindromic(vector<vector<int>> treeIndices);
int main()
{
   cout << minCut("aabcdba") << "\n\r";
//    cout << numDistinct("abbccaa", "bcaa") << "\n\r";
}

int minCut(string A)
{
    vector<vector<int>> treeIndices = createIndices(A);
    int maxPalindStr = findMaxPalindromic(treeIndices);

    return A.size()-maxPalindStr;
}


int findMaxPalindromic(vector<vector<int>> treeIndices)
{
    //for each char, we have found the indices which make the tree palindromic 
    // now we want to merge these chars:
    
}
vector<vector<int>> createIndices(string str)
{
    vector<vector<int>> treeIndices;
    vector<char> seen = findDistinctChars(str);
    for(int i=0; i< seen.size();i++)
    {
        vector<int> rowIndices;
        for(int j=0; j< str.size();j++)
        {
            if(seen[i] == str[j])           
            {
                rowIndices.push_back(j);
            }
        }
        treeIndices.push_back(rowIndices);
    }
    return treeIndices; 
}

vector<char> findDistinctChars(string str)
{
    vector<char> seen;
    map<char, int> charMap;
    for(int i=0; i< str.size();i++)
    {
        cout << charMap[str[i]] << " \n\r";
        if(!charMap[str[i]])
        {
            seen.push_back(str[i]);
            charMap[str[i]] = charMap[str[i]]+1;
        }
            
    }
    return seen;
}