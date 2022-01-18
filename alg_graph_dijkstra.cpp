
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;


/*
find the shortest path from one index to others:
*/

void dijkstra(const vector<int> nodes, const vector<vector<int>> vMat, unordered_map<int, int> &costs, unordered_map<int, bool> &visited, int startNode);

int main()
{
    const vector<int> nodes = {0, 1, 2, 3, 4, 5};

    vector<vector<int>> vMat = {
        { 0,50,45,10,-1,-1},// 0
        {-1, 0,10,-1,-1,-1},// 1
        {-1,-1, 0,-1,30,-1},// 2
        {10,-1,-1, 0,15,-1},// 3
        {-1,20,35,-1, 0,-1},// 4
        {-1,-1,-1,-1, 3, 0},// 5
        //0  1  2  3  4  5
    };
    int startNode = 0;
    unordered_map<int, bool> visited;
    unordered_map<int, int> costs;
    
    for(int i=0; i< nodes.size(); i++)
    {
        if(i==startNode) continue;

        costs[i]=-1;
    }
    dijkstra(nodes, vMat, costs, visited, startNode);
    return -1;
}

void dijkstra(const vector<int> nodes, vector<vector<int>> vMat, unordered_map<int, int> &costs, unordered_map<int, bool> &visited, int startNode)
{
    int midNode =startNode;

    for(int k=0; k< nodes.size(); k++)
    {
        // update costs
        for(int i=0; i< nodes.size(); i++)
        {
            if(midNode==i || i==startNode) continue;
            
            int directCost = vMat[startNode][i];

            if(midNode==startNode)
            {
                costs[i] = directCost;
                continue;
            } 

            int s_m_Cost = vMat[midNode][i] ;
            int m_e_cost = costs[midNode];

            if(s_m_Cost==-1 || m_e_cost==-1) continue; //nothing to update
            else if(directCost==-1)
            {
                costs[i] = s_m_Cost+m_e_cost; // we found a new path
                vMat[startNode][i] = costs[i];
            }
            else
            {
                costs[i] = min(directCost, s_m_Cost+m_e_cost);
                vMat[startNode][i] = costs[i];
            }
        }
        // find min path + notVisited
        int minCost = -1;
        int minNode = -1;
        for(auto item: costs)
        {
            if(!visited[item.first])
            {
                if(minCost==-1 || item.second < minCost)
                {
                    minNode = item.first;
                    minCost = item.second;
                }
            }
        }
        // choose next
        visited[minNode] = true;
        midNode = minNode;
    }   
}