
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> createInterval();
vector<Interval> merge(vector<Interval> &A);
void mergeIntervals(vector<Interval> &A, int current);

int main()
{
    vector<Interval> A = createInterval();
    vector<Interval> mergedA = merge(A);
}

vector<Interval> merge(vector<Interval> &A)
{
    mergeIntervals(A, 0);
    return A;
}

void mergeIntervals(vector<Interval> &A, int current)
{
    if (current >= A.size())
        return;

    if (current + 1 < A.size() && A[current + 1].start <= A[current].end )
    {
        int end = max(A[current].end, A[current + 1].end);
        int start = min(A[current].start, A[current+1].start);
        Interval tmp = Interval(start, end);
        A.erase(A.begin() + current);
        A[current] = tmp;

        current =0; //if sorted, we dont need it
        mergeIntervals(A, current);

    }
    else
    {
        current++;
        mergeIntervals(A, current);
    }
}

vector<Interval> createInterval()
{
    vector<Interval> intervals;
    //[1,3],[2,6],[8,10],[15,18]

    // Interval interval = Interval(1, 3);
    // intervals.push_back(interval);
    // intervals.push_back(Interval(2, 6));
    // intervals.push_back(Interval(8, 10));
    // intervals.push_back(Interval(15, 18));

    //(1, 10), (2, 9), (3, 8), (4, 7), (5, 6), (6, 6)
    intervals.push_back(Interval(1, 10));
    intervals.push_back(Interval(2, 9));
    intervals.push_back(Interval(3, 8));
    intervals.push_back(Interval(4, 7));
    intervals.push_back(Interval(5, 6));
    intervals.push_back(Interval(6, 6));
    //
    return intervals;
}
