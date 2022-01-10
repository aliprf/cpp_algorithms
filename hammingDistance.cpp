
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int hammingDistance(const vector<int> &A);
int main()
{
    cout << hammingDistance({96, 96, 7, 81, 2, 13  }) << "\n\r";
}

int hammingDistance(const vector<int> &A) {
    int sum=0;
    vector<int> B;

    map<int, int> numMap;
    for(int i=0; i< A.size();i++)
    {
        if(numMap[A[i]]==0)
        {
            numMap[A[i]] = 1;
            
        }
        else
        {
            numMap[A[i]] += 1;
        }
    }
   for(const auto & v : numMap){
       if(v.second ==1)
           B.push_back(v.first);
   } 

    for(int i=0; i< B.size();i++)
        for(int j=i+1;j< B.size();j++)
        {
            sum += abs(B[i]-B[j]);
        }
            
    return sum;
}
