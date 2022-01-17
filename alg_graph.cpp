#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct Graph
{
    int data;
    vector<Graph> *neibors;
};

void createGraph(Graph *myGraph);

void createMimCostSpanningTree(vector<int> nodes, vector<vector<int>> vMat, vector<int> &resultTree);

int main()
{   

    // Graph *myGraph = new Graph();
    // createGraph(myGraph);

    // we create graph using nodes and the vicinityMatrix
    vector<int> nodes = {1,2,3,4, 5, 6, 7, 8};
                             //1  2  3  4   5  6  7
    vector<vector<int>> vMat={{ 0,28, 0, 0, 0,10, 0},//1
                              {28, 0,10, 0, 0, 0,14},//2
                              { 0,10, 0,12, 0, 0, 0},//3
                              { 0, 0,12, 0,22, 0,18},//4
                              { 0, 0,12,22, 0,25,24},//5
                              {10, 0, 0, 0,25, 0, 0},//6
                              { 0,14, 0,18,24, 0, 0} //7
                                    };
    createMimCostSpanningTree(nodes, vMat);
    
    return -1;
}

void createMimCostSpanningTree(vector<int> nodes, vector<vector<int>> vMat, vector<int> &resultTree)
{
    // find the lowest cost edge: if no circle, add it to the visited
    
}
////////////////
void createGraph(Graph *myGraph)
{
    myGraph->data = 1;

}