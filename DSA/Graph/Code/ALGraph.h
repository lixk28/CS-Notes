/*
 * @Author: Xuekun Li
 * @Date: 2020-11-21 10:33:13
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-21 14:08:01
 * @Description: Try to code your bug.
 */
#ifndef ALGRAPH_H_
#define ALGRAPH_H_

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


struct ArcNode
{
    int adjvex;
    int weight;
    ArcNode(int _adjvex, int _weight)
    {
        adjvex = _adjvex;
        weight = _weight;
    }
};


struct VexNode
{
    int vertex;
    vector<ArcNode> AdjArcs;
    VexNode(int _vertex): vertex(_vertex) {}
};


class ALGraph
{
    private:
        struct Graph
        {
            int n;
            int e;
            vector<VexNode> AdjList;
            Graph(int _n = 0, int _e = 0)
            {
                n = _n;
                e = _e;
            }
        };

        Graph G;
        bool *visited;    

        void CreateGraph();
        void DestroyGraph();

        void DFS(int v);
        void BFS(int v);
        void ResetVisited();

    public:
        ALGraph();
        ~ALGraph();

        void Display_AdjList();    //Dispaly the AdjList
        void Display_Visited();    //Display the visited

        void DepthFirstTraverse(int v);
        void BreadthFirstTraverse(int v);

        bool ExistPath(int v, int w);

        // //THIS IS FOR DEBUGGING
        // void DEBUG1();
        // void DEBUG2();
};



#endif