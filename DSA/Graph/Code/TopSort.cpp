/*
 * @Author: Xuekun Li
 * @Date: 2021-01-19 11:40:50
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2021-01-19 11:46:28
 * @Description: Try to code your bug.
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void getInDegree(vector<vector<int>> Graph)
{
    
}

void TopSort(vector<vector<int>> Graph)
{

}


int main()
{
    vector<vector<int>> Graph;
    int n, m;
    cin >> n >> m;  //#vertices #edges
    for (int i = 0; i < n; i++) {
        Graph[i] = vector<int>();
    }
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        Graph[v].push_back(w);
    }

    return 0;
}