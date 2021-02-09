/*
 * @Author: Xuekun Li
 * @Date: 2020-11-21 10:33:40
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-21 14:06:32
 * @Description: Try to code your bug.
 */
#include "ALGraph.h"

int main()
{
    ALGraph G;
    G.Display_AdjList();
    G.Display_Visited();
    while(true) {
        int mode;

        cout << "Please choose mode 1/2/3:" << endl;
        cin >> mode;
        if(mode == 1)
        {
            int v;
            cout << "Please enter the begin vertex for Depth First Traverse:" << endl;
            cin >> v;
            G.DepthFirstTraverse(v);
            G.Display_Visited();
        }
        else if(mode == 2)
        {
            int v;
            cout << "Please enter the begin vertex for Breadth First Traverse:" << endl;
            cin >> v;
            G.BreadthFirstTraverse(v);
            G.Display_Visited();
        }
        else if(mode == 3)
        {
            int v, w;
            cout << "Please enter two vertexes:" << endl;
            cin >> v >> w;
            if(G.ExistPath(v, w) == true)
                cout << "There is simple path between " << v << " and " << w << "." << endl;
            else
                cout << "There is no simple path between " << v << " and " << w << "." << endl;
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }
    }

    return 0;
}