#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<string> generateAllCombinations(string word);
void gen(string inputStr, string outStr, vector<string> &combStr);


int main()
{
    vector<string> strs = {"eat","tan"};
    vector<vector<string>> answers = groupAnagrams(strs);
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> answers;

    for (int i=0; i< strs.size(); i++)
    {
        string word = strs[i];
        vector<string> wordAllComb = generateAllCombinations(word);
        // search and add to  answers

    }
    return answers;
}
vector<string> generateAllCombinations(string word)
{
    vector<string> combStr;
    gen(word, "", combStr);

    cout << "word: " << "\n\r";

     for (int i=0; i< combStr.size(); i++)
     {
         cout << combStr[i]<< " ";
     }
    cout << "\n\r======================="<<" \n\r";
    return combStr;
}
void gen(string inputStr, string outStr, vector<string> &combStr)
{
    if(inputStr.size()==1)
    {
        outStr+= inputStr[0];
        combStr.push_back(outStr);
    }

    for(int i=0; i< inputStr.size(); i++)
    {
        string tmp = inputStr;
        tmp.erase(i, 1);
        gen(tmp, inputStr[i]+outStr, combStr);
    }
}