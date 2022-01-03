#include <iostream>
#include <vector>
#include <string>

using namespace std;

void setZeroes(vector<vector<int>> &matrix);

int main()
{
    
}

void setZeroes(vector<vector<int>> &matrix)
{
    vector<vector<int>> indices;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
                indices.push_back({i, j});
        }
    }
    //
    for (int k = 0; k < indices.size(); k++)
    {
        int i_index = indices[k][0];
        int j_index = indices[k][1];
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][j_index] = 0;
        }
        for (int i = 0; i < matrix[i].size(); i++)
        {
            matrix[i_index][i] = 0;
        }
    }