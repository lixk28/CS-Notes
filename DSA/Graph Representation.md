Adjacency List of a Graph:

Implementation 1:

~~~C++
typedef int Vertex;
typedef vector<list<Vertex> > ALGraph;
~~~

Implementation 2:

~~~C++
template <typename V, typename E>
struct Vertex
{
	V info;				//informantion about the vertex
    Edge<E> *firstedge;	//start of the adjacency list
};

template <typename T>
struct Edge
{
    T info;			//information about the edge
    int endpoint;
    Edge *nextedge;	//next edge of the adjacency list
};

template <typename V, typename E>
struct Graph
{
    int count;	//numbers of vertices
    Vertex<V, E> neighbors[MAXSIZE];
};
~~~

---

Implementation of Topological Sort Algorithm:

~~~C++
typedef int Vertex;
typedef vector<vector<Vertex> > ALGraph;
~~~

~~~C++
vector<Vertex> TopSort(const ALGraph &G)
{
    map<Vertex, int> deg = indegree(g);
    queue<Vertex> q;
    vector<Vertex> res;
    
    map<Vertex, int>::iterator it = deg.begin();
    while(it != deg.end())
    {
        if(it->second == 0)	//遍历得到所有入度为0的节点，放进队列中
        	q.push(it->first);
        it++;
    }
    
    while(!q.empty())	//当队列非空
    {
        Vertex v = q.front();
        res.push_back(v);
        q.pop();
    
    	for(size_t i = 0; i < G.; i++)
        {
            Vertex v = G.adj[u][i];
            deg[v]--;
            if(deg[v] == 0)
                q.push(v);
        }
    }
    
    return res;
}
~~~

