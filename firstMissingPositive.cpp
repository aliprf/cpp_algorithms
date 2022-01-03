#include <iostream>
#include <vector>
#include <string>

using namespace std;

int firstMissingPositive(vector<int>& nums);


int main ()
{       
    vector<int> nums = {2,1,3,0};
    cout << firstMissingPositive(nums)<<"\n\r";
}

int firstMissingPositive(vector<int>& nums)
{
    int miss =1;

    for(int i=0; i<nums.size();i++)
    {
        if(nums[i]<=0) continue;
        if(nums[i]==miss) miss++;
    }
    return miss;
}