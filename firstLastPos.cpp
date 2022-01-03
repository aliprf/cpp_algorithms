#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> allAnswers;


vector<int> searchRange(vector<int>& nums, int target);
int recSearch(int index, int target, vector<int> nums);

int main ()
{   
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> vecAns = searchRange(nums, 10);

    cout << "answer: " << "\n\r";
    for (int i=0; i< vecAns.size(); i++)
    {
        cout << vecAns[i] << ",";
    }
    cout << "\n\r";
}

vector<int> searchRange(vector<int>& nums, int target)
{
    recSearch(0, target, nums);

    vector<int> answers;

    if (allAnswers.size()==0)
    {
        answers.push_back(-1);
        answers.push_back(-1);
    }
    else if (allAnswers.size()==1)
    {
        answers.push_back(allAnswers[0]);
        answers.push_back(allAnswers[0]);
    }
    else
    {
        answers.push_back(allAnswers[0]);
        answers.push_back(allAnswers[allAnswers.size()-1]);
    }
        
    return answers;
}


int recSearch(int index, int target, vector<int> nums)
{
    if (nums.size()==0)
    {
        return -1;
    }
    if (nums.size()==1)
    {
        if (nums[0] == target)
        {
            allAnswers.push_back(index);
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (target > nums[nums.size()-1]) return -1;

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
