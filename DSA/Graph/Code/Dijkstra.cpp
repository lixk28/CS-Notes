/*
 * @Author: Xuekun Li
 * @Date: 2020-11-28 20:31:32
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-29 01:24:02
 * @Description: Try to code your bug.
 */
#include "Dijkstra.h"

int getMinDistIndex(vector<int> &dist, bool flag[])
{
    int index = 0;
    int min = M;
    
    int size = dist.size();
    for (int i = 0; i < size; i++)
    {
        if(flag[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }
    
    return index;
}

void Dijkstra(vector<vector<int> > Graph, int source, vector<int> &dist, vector<int> &path)
{
    int size = Graph.size();
    bool flag[size];

    //Initial
    for (int i = 0; i < size; i++)
    {
        dist.push_back(M);      //the shortest distance from source to i
        path.push_back(-1);     //path[i] is the second last vertex pf the shortest path from source to i
        flag[i] = false;        //no vertex is included
    }
    dist[source] = 0;

    for (int i = 0; i < size; i++)
    {
        int u = getMinDistIndex(dist, flag);  
        flag[u] = true; //vertex u is included

        for (int v = 0; v < size; v++)
        {
            if(!flag[v] && Graph[u][v] > 0 && Graph[u][v] < M && dist[v] > dist[u] + Graph[u][v])
            {
                dist[v] = dist[u] + Graph[u][v];
                path[v] = u;
            }
        }
    }
}

void printPath(vector<int> dist, vector<int> path, int source)
{
    int size = dist.size();
    for (int i = 0; i < size; i++)
    {
        if(i == source)
            continue;
            
        cout << "The shortest path from " << source << " to " << i << " is: ";

        int vertex = i;
        vector<int> p;
        while(vertex != -1)
        {
            p.push_back(vertex);
            vertex = path[vertex];
        }

        for (int i = p.size() - 1; i >= 0; i--)
        {
            if(i == 0)
                cout << p[i] << endl;
            else 
                cout << p[i] << "=>";
        }

        cout << "The length is: " << dist[i] << endl << endl;
    }
}