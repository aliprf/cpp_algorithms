#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sortColors(vector<int> &nums);

int main()
{
    
}

void sortColors(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
    }
}