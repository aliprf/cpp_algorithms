#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums);
void getSubsets(vector<int> curVec, vector<int> curRem, vector<vector<int>> &ans);

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans = subsets(nums);

    // for(int i=0; i< ans.size(); i++)
    //     for(int j=0; j< ans[i].size(); j++)
    //         cout << ans[i][j] << ",";
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;

    getSubsets({}, nums, ans);
    return ans;
}

void getSubsets(vector<int> curVec, vector<int> remVec, vector<vector<int>> &ans)
{
    ans.push_back(curVec);
    ans.push_back(remVec);

    if (remVec.size() == 1)
        return;

    if (!curVec.empty())
    {
        for (int i = 0; i < remVec.size(); i++)
        {
            ans.push_back({curVec[0], remVec[i]});
        }
    }

    if (remVec.size() > 3)
    {
        for (int i = 0; i < remVec.size(); i++)
        {
            vector<int> tmp(remVec);
            tmp.erase(tmp.begin() + i);
            ans.push_back(tmp);
        }
    }

    curVec = {remVec[0]};
    remVec.erase(remVec.begin());
    getSubsets(curVec, remVec, ans);
}