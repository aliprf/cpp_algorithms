#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<string> generateAllCombinations(string word);
void gen(string inputStr, string outStr, vector<string> &combStr);


int main()
{
    vector<string> strs = {"",""};//{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> answers = groupAnagrams(strs);

    for (int i=0; i< answers.size(); i++)
    {
         vector<string> combs = answers[i];
         cout << "[" ;
         for (int j=0; j< combs.size(); j++)
         {
             cout <<combs[j] << " ";
         }
         cout << "] \n\r" ;
    }
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> answers;

    for (int i=0; i< strs.size(); i++)
    {
        vector<string> matchedCombinations;
        string word = strs[i];
        vector<string> wordAllComb = generateAllCombinations(word);

        matchedCombinations.push_back(strs[i]);
        for(int j=i+1; j<strs.size(); j++)
        {
            for(int k=0; k<wordAllComb.size(); k++) 
            {
                if(wordAllComb[k] == strs[j])
                {
                    matchedCombinations.push_back(strs[j]);
                    strs.erase(strs.begin()+j);
                }
            }
        }
        // matchedCombinations.push_back(strs[i]);
        // search and add to  answersanswers
        answers.push_back(matchedCombinations);

    }
    return answers;
}
vector<string> generateAllCombinations(string word)
{
    vector<string> combStr;
    gen(word, "", combStr);

    // cout << "word: " << "\n\r";

    //  for (int i=0; i< combStr.size(); i++)
    //  {
    //      cout << combStr[i]<< " ";
    //  }
    // cout << "\n\r======================="<<" \n\r";
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