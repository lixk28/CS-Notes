/*
 * @Author: Xuekun Li
 * @Date: 2020-11-28 20:28:53
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-29 01:25:44
 * @Description: Try to code your bug.
 */
#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#define M 10000
using namespace std;


int getMinDistIndex(vector<int> &dist, bool flag[]);
void Dijkstra(vector<vector<int>> Graph, int source, vector<int> &dist, vector<int> &path);
void printPath(vector<int> dist, vector<int> path, int source);


#endif