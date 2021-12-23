#include <iostream>
#include <vector>
#include <string>

using namespace std;


int uniquePaths(int m, int n);
void findPath(vector<vector<int>> path, vector<vector<vector<int>>> &allPath, vector<vector<int>> &visited, int i_index, int j_index);
int actualPathLenght;
int i_goal, j_goal;
int _m, _n;

int main()
{   
    _m = 3;
    _n=7;
    uniquePaths(_m,_n);

}

int uniquePaths(int m, int n)
{
    i_goal = m-1;
    j_goal = n-1;

    vector<vector<int>>  visited( m , vector<int> (n, 0)); // m*n matrix used to see if we have already visited a node or no

    actualPathLenght = m+n-1;
    vector<vector<vector<int>>> allPath;
    vector<vector<int>> path;

    path.push_back({0,0});

    findPath(path, allPath, visited, 0,0);

    int ans = allPath.size();

    for(int i=0; i< allPath.size(); i++)
    {
        cout << "P-" << i+1<< "=> ";
        for(int j=0; j< allPath[i].size(); j++)
        {
            cout << "[";
            for(int k=0; k< allPath[i][j].size(); k++)
                cout << allPath[i][j][k];
            cout << "]";
        }
        cout << "\n\r-----------\n\r";
    }
    cout << ans << "\n\r";
    return ans;
}

void findPath(vector<vector<int>> path, vector<vector<vector<int>>> &allPath, vector<vector<int>> &visited, int i_index, int j_index)
{
    if(i_index==i_goal && j_index ==j_goal )
    {
        allPath.push_back(path);
        return;
    }
    
    if(i_index+1 <= _m-1 && visited[i_index+1][j_index]==0)
    {
        vector<vector<int>> _p = path;
        _p.push_back({i_index+1, j_index});

        // visited[i_index+1][j_index]=1;
        visited[i_goal][j_goal]=0;
        findPath(_p, allPath, visited, i_index+1,j_index);
    }
    if(j_index+1 <= _n-1 && visited[i_index][j_index+1]==0)
    {
        vector<vector<int>> _p = path;
        _p.push_back({i_index, j_index+1});

        // path.push_back({i_index, j_index+1});
        // visited[i_index][j_index+1]=1;
        visited[i_goal][j_goal]=0;
        findPath(_p, allPath, visited, i_index,j_index+1);
    }    
}