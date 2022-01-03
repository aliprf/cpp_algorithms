#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) ;


int main()
{      
    vector<vector<int>> matrix ={{1,2,3},{5,6,7},{9,10,11}, {12,13,14}}; //{{1,2,3,4},{5,6,7,8},{9,10,11,12}} ;
    
    vector<int> result = spiralOrder(matrix);

    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";
    
    cout << " \n\r";
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;
    int w = matrix.size();
    int h = matrix[0].size();

    vector<int> topLeft ={0,0};
    vector<int> topRight ={0,h-1};
    vector<int> bottomRight ={w-1,h-1};
    vector<int> bottomLeft ={w-1,0};

    int i_index=0, j_index=0;
   
    int steps = w*h;

    while(steps>0)
    {
        if(i_index == topLeft[0] && j_index == topLeft[1])
        {
            do
            {
                steps--;
                result.push_back(matrix[i_index][j_index]);
                j_index++;
            } while (j_index <= topRight[1]);
            j_index --;
        }
        else if(i_index == topRight[0] && j_index == topRight[1])
        {
            i_index ++;
            do
            {
                steps--;
                result.push_back(matrix[i_index][j_index]);
                i_index++;
            }  while (i_index <= bottomRight[0]);
            i_index --;
        }
        else if(i_index == bottomRight[0] && j_index == bottomRight[1])
        {
            j_index --;
            do
            {
                steps--;
                result.push_back(matrix[i_index][j_index]);
                j_index--;
            }  while (j_index >= bottomLeft[1]);
            j_index ++;
            //update top-left and top-right
            topLeft[0] ++;
            topRight[0]++;

        }
        else if(i_index == bottomLeft[0] && j_index == bottomLeft[1])
        {
            i_index --;
            do
            {
                steps--;
                result.push_back(matrix[i_index][j_index]);
                i_index--;
            }  while (i_index >= bottomLeft[0]);
            i_index ++;

            topRight[1] --;
            bottomRight[1]--;
        }
    }

        

    return result;
}