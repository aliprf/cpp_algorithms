#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int majorityElement(const vector<int> &A);

int main()
{
    const vector<int> A = {2, 1, 2};
    cout << majorityElement(A) << "\n\r";
}

int majorityElement(const vector<int> &A)
{
    map<int, int> points;

    for (int i = 0; i < A.size(); i++)
    {
        if (points.find(A[i]) != points.end())
        {
            points[A[i]]++;
        }
        else
        {
            points[A[i]] = 1;
        }
    }
    int N = A.size()/2;

    for (auto const &x : points)
    {
        if(x.second > N) return x.first;
    }
}