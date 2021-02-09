/*
 * @Author: Xuekun Li
 * @Date: 2020-11-21 10:33:21
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-21 14:08:15
 * @Description: Try to code your bug.
 */
#include "ALGraph.h"

void ALGraph::CreateGraph()
{
    int _n, _e;
    cout << "Please enter the number of vertexes:" << endl;
    cin >> _n;
    cout << "Please enter the number of edges:" << endl;
    cin >> _e;

    G.n = _n;
    G.e = _e;
    for (int i = 0; i < G.n; i++)
    {
        VexNode curr(i);
        G.AdjList.push_back(curr);
    }

    cout << "Please enter the information of each edge:" << endl;
    for (int i = 0; i < G.e; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;

        ArcNode curr1(vertex2, 0);
        ArcNode curr2(vertex1, 0);

        (G.AdjList)[vertex1].AdjArcs.push_back(curr1);
        (G.AdjList)[vertex2].AdjArcs.push_back(curr2);
    }

    visited = new bool[G.n];
    memset(visited, false, sizeof(bool) * G.n);
}

void ALGraph::DestroyGraph()
{
    delete[] visited;
}

void ALGraph::DFS(int v)
{
    cout << v << " ";
    visited[v] = true;

    for(auto curr: (G.AdjList)[v].AdjArcs)
    {
        int w = curr.adjvex;
        if(visited[w] == false)
            DFS(w);
    }
}

void ALGraph::BFS(int v)
{
    queue<size_t> q;
    cout << v << " ";
    visited[v] = true;
    q.push(v);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto curr: (G.AdjList)[u].AdjArcs)
        {
            int w = curr.adjvex;
            if(visited[w] == false)
            {
                cout << w << " ";
                visited[w] = true;
                q.push(w);
            }
        }
    }
}

void ALGraph::ResetVisited()
{
    memset(visited, false, sizeof(bool) * G.n);
}

ALGraph::ALGraph()
{
    CreateGraph();
}

ALGraph::~ALGraph()
{
    DestroyGraph();
}

void ALGraph::Display_AdjList()
{
    cout << endl << "The AdjList of the Graph:" << endl;
    for(auto curr: G.AdjList)
    {
        cout << curr.vertex << ": ";
        for(auto temp: curr.AdjArcs)
        {
            cout << temp.adjvex << " ";
        }
        cout << endl;
    }
}

void ALGraph::Display_Visited()
{
    cout << endl << "visited: " << endl;
    for (int i = 0; i < G.n; i++)
        cout << visited[i] << " ";
    cout << endl << endl;
}

void ALGraph::DepthFirstTraverse(int v)
{
    ResetVisited();
    cout << "The Depth First Traverse Sequence:" << endl;
    DFS(v);
    ResetVisited();
}

void ALGraph::BreadthFirstTraverse(int v)
{
    ResetVisited();
    cout << "The Breadth First Traverse Sequence:" << endl;
    BFS(v);
    ResetVisited();
}

bool ALGraph::ExistPath(int v, int w)
{   
    queue<size_t> q;
    visited[v] = true;
    q.push(v);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto curr: (G.AdjList)[u].AdjArcs)
        {
            int r = curr.adjvex;
            if(visited[r] == false)
            {
                visited[r] = true;
                q.push(r);
            }
        }
    }

    if(visited[w] == true)
    {
        ResetVisited();
        return true;
    }
    else
    {
        ResetVisited();
        return false;
    }
}

