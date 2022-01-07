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
void createAllsubStrings(string str, vector<string> &subStrings);

int main()
{
//    cout << minCut("aabcdba") << "\n\r";
//    cout << numDistinct("abbccaa", "bcaa") << "\n\r";
    vector<string> subStrings;
    createAllsubStrings("abc", subStrings);
    cout << "\n\r";
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
    //sort them by size of the furthest and see if you can merge them with smaller one.
    
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

void createAllsubStrings(string str, vector<string> &subStrings)
{
    if(str.length() == 1)
    {
        subStrings.push_back(str);
        return;
    }
    
    string prefixStr;
    prefixStr.push_back(str[0]);
    str.erase(0,1);
    createAllsubStrings(str, subStrings);

    int strL = subStrings.size();
    for(int i=0; i< strL; i++)
        subStrings.push_back(prefixStr+subStrings[i]);
    subStrings.push_back(prefixStr);

}