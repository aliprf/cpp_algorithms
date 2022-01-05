#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string s);
int decode(string pattern, int currentIndex, int &validPatternsCount, string &subPat);
bool isValid(string pattern);

int main()
{
    string s = "12";
    cout << numDecodings(s) << "\n\r";
}

int numDecodings(string s)
{
    int validPatternsCount =0;

    
    for(int i=0; i< s.size(); i++)
    {
        string subPat = s[i];
        decode(s, i, validPatternsCount, subPat);
    }
    return validPatternsCount;
}


bool isValid(string pattern)
{
    if(pattern.size()>2) return false;
    if(!pattern.empty() && pattern[0] == '0') return false;
    
    int ipat = stoi(pattern);

    if (ipat>26) return false;

    return true;    
}

int decode(string pattern, int currentIndex, int &validPatternsCount, string &subPat)
{
    subPat += pattern[currentIndex];
    if(isValid(subPat))
    {
        validPatternsCount ++;
        if(currentIndex+1 < pattern.size()) 
            decode(pattern, currentIndex+1, validPatternsCount, subPat);
    }
    return validPatternsCount;
}