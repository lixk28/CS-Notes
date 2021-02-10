/*
 * @Author: Xuekun Li
 * @Date: 2020-11-28 20:31:40
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-29 01:26:06
 * @Description: Try to code your bug.
 */
#include "Dijkstra.h"

int main()
{
    vector<vector<int>> Graph = {{0, 2, 2, M, M, M, M, M},
                                 {M, 0, M, M, M, M, 9, M},
                                 {M, M, 0, M, M, M, 3, M},
                                 {M, M, M, 0, M, M, M, M},
                                 {M, M, 6, M, 0, M, M, M},
                                 {M, 5, M, 1, M, 0, M, 9},
                                 {M, M, M, M, 7, 1, 0, 9},
                                 {M, M, M, M, M, M, M, 0}};
    vector<int> dist;
    vector<int> path;
    
    Dijkstra(Graph, 0, dist, path);
    printPath(dist, path, 0);

    return 0;
}