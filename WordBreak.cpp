// https://www.interviewbit.com/problems/word-break/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int wordBreak(string A, vector<string> &B);
vector<string> createAllcombinations(vector<string> input);
int checkExistance(vector<string> input, string patStr);

int main()
{
    vector<string> B = {"trainer", "my", "interview"};
    string A = "myinterviewtrainer";

    cout << wordBreak(A, B) << "\n\r";
}

int wordBreak(string A, vector<string> &B)
{
    int vecStrSize = 0;
    for (int i = 0; i < B.size(); i++)
        vecStrSize += B[i].size();

    if (A.size() != vecStrSize)
        return 0;

    vector<string> results = createAllcombinations(B);

    return checkExistance(results, A);
}

int checkExistance(vector<string> input, string patStr)
{
    int found = 0;

    int mid = patStr.size() / 2;
    int left = mid - 1;
    int right = mid + 1;

    for (int i = 0; i < input.size(); i++)
    {
        string str = input[i];

        if (patStr[mid] == str[mid])
        {
            int l = left;
            int r = right;
            while (l >= 0 && r < patStr.size() && patStr[l] == str[l] && patStr[r] == str[r])
            {
                l--;
                r++;
            }
            if(l==0) return 1;
        }
    }
    return found;
}

vector<string> createAllcombinations(vector<string> input)
{
    vector<string> result;
    if (input.size() == 1)
    {
        result.push_back(input[0]);
        return result;
    }

    for (int i = 0; i < input.size(); i++)
    {
        string prefix = input[i];
        vector<string> tmpInp = input;
        tmpInp.erase(tmpInp.begin() + i);

        vector<string> tmpOut = createAllcombinations(tmpInp);
        for (int i = 0; i < tmpOut.size(); i++)
        {
            result.push_back(prefix + tmpOut[i]);
        }
    }
    return result;
}