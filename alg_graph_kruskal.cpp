#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;


int createMimCostSpanningTree(vector<int> nodes, vector<vector<int>> vMat, map<string, int> &resultMap);
void createNodeEdgeMap(map<vector<int>, int> &neMap, vector<int> nodes, vector<vector<int>> vMat);
int findMin(map<vector<int>, int> &tmpNeMap, int *fromNode, int *toNode, vector<unordered_map<int, int>> &visited);
void addToVisited(int fromNode, int toNode, vector<unordered_map<int, int>> &visited);
bool circleExist(int fromNode, int toNode, vector<unordered_map<int, int>> &visited);


int main()
{

    // we create graph using nodes and the vicinityMatrix
    vector<int> nodes = {0, 1, 2, 3, 4, 5, 6};

    vector<vector<int>> vMat = {
        {0, 28, 0, 0, 0, 10, 0},   // 0
        {28, 0, 10, 0, 0, 0, 14},  // 1
        {0, 10, 0, 12, 0, 0, 0},   // 2
        {0, 0, 12, 0, 22, 0, 18},  // 3
        {0, 0, 12, 22, 0, 25, 24}, // 4
        {10, 0, 0, 0, 25, 0, 0},   // 5
        {0, 14, 0, 18, 24, 0, 0}   // 6
        // 0  1  2  3   4  5  6
    };
    map<string, int> resultMap;
    int mincost = createMimCostSpanningTree(nodes, vMat, resultMap);
    
    cout<< "mincost=> "<<mincost<< "\n\r";

    return -1;
}
// kruskal Algorithm: find next lowest cost edge, and check no circle
int createMimCostSpanningTree(vector<int> nodes, vector<vector<int>> vMat, map<string, int> &resultMap)
{
    int cost = 0;

    map<vector<int>, int> neMap;
    createNodeEdgeMap(neMap, nodes, vMat);
    // find the lowest cost edge: if no circle, add it to the visited

    int numEdges = neMap.size();
    int foundEdge = 0;

    map<vector<int>, int> tmpNeMap(neMap);
    vector<string> path;
    vector<unordered_map<int, int>> visited;
    while (foundEdge != nodes.size() - 1)
    {
        int fromNode=-1, toNode=-1;
        int c = findMin(tmpNeMap, &fromNode, &toNode, visited);
        resultMap[to_string(fromNode) + "->" + to_string(toNode)] = c;
        cost +=c;
        foundEdge++;
    }
    return cost;
}
int findMin(map<vector<int>, int> &tmpNeMap, int *fromNode, int *toNode, vector<unordered_map<int, int>> &visited)
{
    int minCost = 10000;
    for (auto i : tmpNeMap)
    {
        vector<int> nodes = i.first;
        int cost = i.second;

        if (cost < minCost)
        {
            if(circleExist(nodes[0], nodes[1], visited))// circle
                continue;

            minCost = cost;
            *fromNode = nodes[0];
            *toNode = nodes[1];
        }
    }

    // visited[*fromNode] = 1;
    // visited[*toNode] = 1;
    addToVisited(*fromNode, *toNode, visited);

    tmpNeMap.erase({*fromNode, *toNode});

    return minCost;

}

void addToVisited(int fromNode, int toNode, vector<unordered_map<int, int>> &visited)
{
    int fromIndex=-1, toIndex=-1;
    for(int i=0; i< visited.size(); i++)
    {
        unordered_map<int, int> tmpMap = visited[i];
        if(tmpMap[fromNode]>0)
        {
            fromIndex = i;
        }
        if(tmpMap[toNode]>0)
        {
            toIndex = i;
        }
    }
    if(fromIndex != -1 && toIndex != -1) //both exist: merge two
    {
        unordered_map<int, int> tm0 = visited[fromIndex];
        unordered_map<int, int> tm1 = visited[toIndex];
        
        //add second to the first 
        for(auto item: tm1)
        {
            tm0[item.first] = item.second;
        }
        //remove second and update first
        visited[fromIndex] = tm0;
        visited.erase(visited.begin()+toIndex);
    }
    else if(fromIndex == -1 && toIndex== -1) //none exist: add new entry
    {
        unordered_map<int, int> tmpMap;
        tmpMap[fromNode] = 1;
        tmpMap[toNode] = 1;
        visited.push_back(tmpMap);
    }
    else if(fromIndex != -1) // fromNode exist
    {
        unordered_map<int, int> tm = visited[fromIndex];
        tm[toNode] = 1;
         visited[fromIndex] = tm;
    }
    else if(toIndex != -1) // toNode exist
    {
        unordered_map<int, int> tm = visited[toIndex];
        tm[fromNode] = 1;
         visited[toIndex] = tm;
    }
    int a=0;
}
bool circleExist(int fromNode, int toNode, vector<unordered_map<int, int>> &visited)
{
    if(visited.empty()) return false;

    //if fromNode && toNode are from the same set, then we have circle
    int fromIndex=-1, toIndex=-1;
    for(int i=0; i< visited.size(); i++)
    {
        unordered_map<int, int> tmpMap = visited[i];
        if(tmpMap[fromNode]>0 && tmpMap[toNode]>0)
        {
            return true;
        }
    }
    return false;
}

void createNodeEdgeMap(map<vector<int>, int> &neMap, vector<int> nodes, vector<vector<int>> vMat)
{

    for (int i = 0; i < nodes.size(); i++)
    {
        for (int j = i + 1; j < nodes.size(); j++)
        {
            if (vMat[i][j] != 0)
            {
                neMap.insert(pair<vector<int>, int>({i, j}, vMat[i][j]));
                // neMap.insert(pair<vector<int>, int>({j, i}, vMat[j][i]));
                //  because this is undiricted. Else, we need to traverse all nodes
            }
        }
    }
}
////////////////
void createGraph(Graph *myGraph)
{
    myGraph->data = 1;
}