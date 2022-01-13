#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string s);
void createcombinations(string inputStr, vector<string> ansVec, vector<vector<string>> &allComb);
bool isValidAll(vector<string> strVec);
bool isValid(string pattern);

int main()
{
    string s = "1261";
    cout << numDecodings(s) << "\n\r";
}

int numDecodings(string s)
{
    int validPatternsCount = 0;

    vector<vector<string>> allComb;
    vector<string> ansVec;
    createcombinations(s, ansVec, allComb);
    for(int i=0; i< allComb.size(); i++)
    {
        if(isValidAll(allComb[i]))
            validPatternsCount++;
    }
    return validPatternsCount;
}

void createcombinations(string inputStr, vector<string> ansVec, vector<vector<string>> &allComb)
{
    if (inputStr.size() == 0)
    {
        allComb.push_back(ansVec);
        return;
    }

    // 1 char
    string pre;
    pre.push_back(inputStr[0]);
    inputStr.erase(0, 1);
    vector<string> tmpAns (ansVec);
    tmpAns.push_back(pre);
    createcombinations(inputStr, tmpAns, allComb);

    // 2 chars
    if (inputStr.size() >= 1)
    {
        pre.push_back(inputStr[0]);
        inputStr.erase(0, 1);
        vector<string> tmpAns (ansVec);
        tmpAns.push_back(pre);
        createcombinations(inputStr, tmpAns, allComb);
    }
}

bool isValidAll(vector<string> strVec)
{
    for(int i=0; i< strVec.size(); i++)
    {
        if(!isValid(strVec[i])) return false;
    }
    return true;
}
bool isValid(string pattern)
{
    if (pattern.size() > 2)
        return false;
    if (!pattern.empty() && pattern[0] == '0')
        return false;

    int ipat = stoi(pattern);

    if (ipat > 26)
        return false;

    return true;
}