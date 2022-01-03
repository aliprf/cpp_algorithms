#include <iostream>
#include <vector>
#include <string>

using namespace std;

string minWindow(string s, string t);

int main()
{
    cout << minWindow("ali", "a");
}

string minWindow(string s, string t)
{
    string result = "";

    for (int i = 0; i < s.size(); i++)
    {
        int left = i;
        string tmpPat = t;
        string tmpRes = "";

        int chInd = tmpPat.find(s[i]);
        if (chInd >= 0)
        {
            tmpPat.erase(chInd);
            tmpRes += s[i];

            for (int j = i + 1; j < s.size(); j++)
            {
                int chInd1 = tmpPat.find(s[j]);
                tmpRes += s[j];

                if (chInd1 == -1)
                    continue;

                tmpPat.erase(chInd1);
                // if(tmpPat.size()<=0) break;
            }
            //cout << tmpPat << "---";

            if (tmpPat.size() == 0)
                if (result.size() <= 0 || result.size() >= tmpRes.size())
                    result = tmpRes;
        }
    }
    return result;
}