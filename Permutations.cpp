#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> permute(vector<int>& nums);
void gen(vector<int> nums, vector<int> ans);

vector<vector<int>> answers;

int main ()
{   
    vector<int> nums = {1,2,3, 4};
    vector<vector<int>> tmpAll = permute(nums);

    for(int i=0; i<tmpAll.size();i++)
    {
        cout << i << "=> [";
        vector<int> tmp = tmpAll[i];
        for(int j=0; j<tmp.size();j++)
        {
            cout << tmp[j]<< " ";
        }
        cout << "] \n\r";
    }
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<int> tmp ={};
    gen(nums, tmp);

    return answers;
}

void gen(vector<int> nums, vector<int> ans)
{
    if (nums.size() ==1)
    {
        ans.push_back(nums[0]);
        answers.push_back(ans);
        return;
    }
    for(int i=0; i<nums.size();i++)
    {
        ans.push_back(nums[i]);

        vector<int> tmp = nums;
        tmp.erase(tmp.begin() + i); 

        gen(tmp, ans);

        ans.pop_back();
    }
}