#include <iostream>
#include <vector>
#include <string>

using namespace std;

int search(vector<int> &nums, int target);
int recSearch(int index, int target, vector<int> nums);

int main ()
{   
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << search(nums, 0) << "\n\r";

    nums = {4,5,6,7,0,1,2};
    cout << search(nums, 2) << "\n\r";
}

int search(vector<int> &nums, int target)
{
    int answer =-1;

    answer= recSearch(0, target, nums);
    return answer;
}

int recSearch(int index, int target, vector<int> nums)
{
    if (nums.size()==1)
    {
        if (nums[0] == target)
        {
            return index;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int l = 0; 
        int r = nums.size();
        int m = int((r-l)/2);

        vector<int> l_vec(nums.begin(), nums.begin()+m);
        vector<int> r_vec(nums.begin()+m, nums.begin()+nums.size());

        int lAns = recSearch(index, target, l_vec);
        int rAns = recSearch(index+m, target, r_vec);

        return max(lAns, rAns);
    }

}
