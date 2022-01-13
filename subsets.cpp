#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums);
void createSubsets(vector<int> vec, vector<vector<int>> &solution, vector<int> subset);

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);

    // for(int i=0; i< ans.size(); i++)
    //     for(int j=0; j< ans[i].size(); j++)
    //         cout << ans[i][j] << ",";
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;

    createSubsets(nums, ans, {});
    return ans;
}

void createSubsets(vector<int> vec, vector<vector<int>> &solution, vector<int> subset)
{
    if(vec.size() == 0)
    {
        solution.push_back(subset);
        return;
    }

    int item = vec[0];
    vec.erase(vec.begin());


    createSubsets(vec, solution, subset);    
    //
    subset.push_back(item);
    createSubsets(vec, solution, subset);
}
