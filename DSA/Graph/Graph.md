# Graph 图

[toc]

---

## 1. 图的定义

**图(graph)**是由**顶点(vertex)**和**边(edge)**构成的集合，用**G(V, E)**表示。

其中V是顶点的有限集合，记为**V(G)**；E是连接V中两个不同顶点(顶点对)的边的有限集合，记为**E(G)**

可以用<u>字母或自然数</u>来标识图中的顶点，约定用 i(0 $\leq$ i $\leq$ n-1) 表示第 i 个顶点的编号，其中 n 为图中顶点的个数。当E(G)为空集时，则图G只有顶点，没有边。

+ **有向图(digraph)**：在图G中，如果表示边的顶点对是有序的，则称G为有向图

+ **无向图(undirgraph)**：在图G中，若顶点对$<i,j> \in E(G)$必有$<j,i> \in E(G)$，即E(G)是对称的，则用$(i,j)$代替这两个顶点对$<i,j>$和$<j,i>$，表示顶点$i$ 与顶点$j$的一条无向边，则称G为无向图

  无向图可以看成有向图的特例。

---

## 2. 图的基本概念

+ 端点和邻接点：

  + 在一个无向图中，若存在一条边(i, j)，则称顶点i和顶点j为该边的两个**端点(endpoint)**，并称它们互为**邻接点(adjacent)**。

    即顶点i是顶点j的一个邻接点，顶点j也是顶点i的一个邻接点，边(i, j)和顶点i、j**关联**。

    关联于相同的两个端点的两条或者两条以上的边称为多重边。

  + 在一个有向图中，若存在一条有向边<i, j>，则称此边是顶点i的一条**出边**，同时也是顶点j的一条**入边**，i为此边的**起始端点**（简称为**起点**），j为此边的**终止端点**（简称为**终点**），顶点i是顶点j的**入边邻接点**，顶点j是顶点i的**出边邻接点**。

+ 顶点的度

  + 在无向图中，**一个顶点所关联的边的数目**称为该**顶点的度(degree)**

  + 在有向图中，顶点的度分为入度和出度，一个顶点入度和出度的和称为该顶点的度

    + **入度(indegree)**：**<u>以某个顶点为终点的边的数目</u>**，称为该顶点的入度
    + **出度(outdegree)**：**<u>以某个顶点为起点的边的数目</u>**，称为该顶点的出度

  + **握手定理**：若一个图有 n 个顶点和 e 条边，每个顶点的度为 d~i~（0 $\leq$ i $\leq$ n-1），则有
    $$
    \displaystyle \sum^{n-1}_{i=0}{d_i} = 2e
    $$
    也就是说：**一个图中所有顶点的度数之和等于边数的两倍**

+ 完全图

  **完全图(completed graph)**：对于无向图，若**<u>每两个顶点</u>**之间都存在一条边，对于有向图，若**<u>每两个顶点</u>**之间都存在方向相反的两条边，则称此无向图或有向图为完全图

  **若图的顶点为n，则无向完全图有$\displaystyle \frac{n(n-1)}{2}$条边，有向完全图有$n(n-1)$条边**

  无向完全图：$(n-1)+(n-2)+\cdots+1+0 = \frac{n[0+(n-1)]}{2} = \frac{n(n-1)}{2}$

  有向完全图：$2(n-1) + 2(n-2) + \cdots + 2 + 0 = \frac{n[0+2(n-1)]}{2} = n(n-1)$

+ 稠密图和稀疏图

  **稠密图(dense graph)**：当一个图接近完全图时，称为稠密图

  **稀疏图(sparse graph)**：当一个图含有较少的边数时，称为稀疏图

+ 子图

  设有两个图G=(V, E)和G^'^=(V^'^, E^'^)，若V^'^是V的子集且E^'^是E的子集，即$V^{'} \subset V$且$ E^{'} \subset E$，则称G^'^是G的**子图(subgraph)**

  **一个图的子图一定还是个图**，<u>并非V的任何子集V^'^和E的任何子集E^'^都能构成G的子图</u>，因为这样的(V^'^, E^'^)并不一定能构成一个图

+ 路径和路径长度

  + **路径(path)**：在一个图G(V, E)中，从顶点i到顶点j的一条路径是一个**<u>顶点序列</u>**$(i, k_1, k_2, \cdots, k_m, j)$

    + 若此图是无向图，则要求边$(i,k_1),(k_1,k_2),\cdots,(k_{m-1},k_{m}),(k_m,j)$都属于E(G)
    + 若此图是有向图，则要求边$<i,k_1>,<k_1,k_2>,\cdots,<k_{m-1},k_{m}>,<k_m,j>$都属于E(G)

    若一条路径上<u>除起点和终点可以相同外</u>，其余顶点均不相同，则称此路径为**简单路径(simple path)**

  + **路径长度(path length)**：**一条路径上经过的边的数目**

+ 回路或环

  **回路/环(cycle)**：若一条路径的起点和终点为同一个顶点，则称此路径为回路或环

  起点和终点相同的简单路径称为**简单回路或简单环(simple cycle)**

+ 连通、连通图和连通分量

  **连通(conneted)**：在一个图G中，**若从顶点i到顶点j有路径**，则称顶点i到顶点j是连通的

  **连通图(connected graph)**：在一个图G中，**若<u>任意两个顶点</u>都是连通的**，则称G为连通图，否则为非连通图

  **连通分量(connected component)**：一个图G的<u>**极大连通子图**</u>称为G的连通分量

+ 权和网

  **权(weight)**：图中的每条边都可以附有一个对应的数值，称为权。<u>**权可以表示从一个顶点到另一个顶点的距离或所花费的代价**</u>

  **带权图(weighted graph)**：边上有权的图称为带权图，也称为**网(net)**

---

## 3. 图的存储结构

### 3.1 邻接矩阵

图的**邻接矩阵(adjacency matrix)**是一种采用邻接矩阵数组表示顶点之间相邻关系的存储结构。

设G=(V, E)是含有n(n>0)个顶点的图，各顶点编号为0~(n-1)，则G的邻接矩阵数组A是**n阶方阵**：

+ 如果G是不带权无向图，则$\displaystyle \begin{equation} A[i][j]= \begin{cases} 1&\mbox{$if (i,j) \in E(G)$}\\ 0&\mbox{else} \end{cases} \end{equation}$

+ 如果G是带权无向图，则$\displaystyle \begin{equation} A[i][j]= \begin{cases} w_{ij}&\mbox{$if \ i \neq j \ and \ (i,j) \in E(G), w_{ij} \ is \ the \ weight \ of \ (i,j)$}\\ 0&\mbox{i = j} \\ \infty&\mbox{else} \end{cases} \end{equation}$

  这时邻接矩阵存储的是各个边的权值，若顶点i到顶点j没有有向边，认为它们之间的权值为无穷大，若顶点i到它本身有有向边，认为权值为0

+ 如果G是不带权有向图，则$\displaystyle \begin{equation} A[i][j]= \begin{cases} 1&\mbox{$if <i,j> \in E(G)$}\\ 0&\mbox{else} \end{cases} \end{equation}$

+ 如果G是带权有向图，则$\displaystyle \begin{equation} A[i][j]= \begin{cases} w_{ij}&\mbox{$if \ i \neq j \ and \ <i,j> \in E(G), w_{ij} \ is \ the \ weight \ of \ (i,j)$}\\ 0&\mbox{i = j} \\ \infty&\mbox{else} \end{cases} \end{equation}$

---

邻接矩阵的实现：

~~~C++
struct Vertex
{
    int num;	//顶点的编号
    //顶点的其他信息
};

struct MatGraph
{
    int n;	//顶点数
    int e;	//边数
    Vertex vertexes[n];		//顶点信息
    int AdjMatrix[n][n];	//邻接矩阵
}
~~~

---

邻接矩阵的特点：

+ **图的邻接矩阵表示是<u>唯一</u>的**
+ 无向图的邻接矩阵一定是一个对称矩阵，:star:因此可以采用**<u>压缩存储</u>**的思想，**在存放邻接矩阵数组时，只需要存放矩阵的上三角部分或下三角部分**
+ 对于无向图，其邻接矩阵数组的第i行或第i列非零元素、非无穷大元素的个数是顶点i的度
+ 对于有向图，其邻接矩阵数组的第i行非零元素、非无穷大元素的个数是顶点i的出度；第i列非零元素、非无穷大元素的个数是顶点i的入度
+ 对于含有n个顶点的图，当采用邻接矩阵存储时，无论是有向图还是无向图，也无论是带权图还是不带权图，其存储空间都是O(n^2^)，所以:star:**<u>邻接矩阵适合于存储边的数目较多的稠密图</u>**
+ 在邻接矩阵中，判断图中两个顶点之间是否有边或者求两个顶点之间边的权值的执行时间为O(1)。所以:star:**<u>在需要判断边的存在或者提取边的权值的算法中通常采用邻接矩阵存储结构</u>**

---

### 3.2 邻接表

图的**邻接表(adjacency list)**是一种顺序与链式存储相结合的存储结构。

+ 对于含有n个顶点的无向图，为每个顶点建立一个单链表，第i(0 $\leq$ i $\leq$ n-1)个单链表中的节点表示关联于顶点i的边，也就是将顶点i的所有邻接点链接起来，其中每个节点表示一条边的信息
+ 对于含有n个顶点的有向图，为每个顶点建立一个单链表，第i(0 $\leq$ i $\leq$ n-1)个单链表中的节点表示以顶点i为起点的边。由于在有向图的邻接表中，只存放了以一个顶点为起点的边，所以不易找到以该顶点为终点的边，为此可以建立有向图的**逆邻接表(inverse adjacency list)**，逆邻接表中的每个顶点对应的单链表链接的是指向该顶点的边

---

邻接表中有两种类型的节点：

+ 头节点：其个数为图顶点的个数
+ 边节点：即单链表中的节点

头结点由2个域组成，data存储顶点i的名称或其他信息，firstarc指向顶点i的邻接点链表的首结点

边结点由3个域组成，adjvex存储与顶点i邻接的顶点的编号，weight存储该边的权值，nextarc指向下一个边结点

邻接表的实现：

~~~C++
struct ArcNode	//边结点
{
    int adjvex;	//邻接点编号
    int weight;	//该边的权值
    ArcNode *nextarc;	//下一个边结点
};

struct VexNode	//头结点
{
    int data;	//结点信息
    ArcNode *firstarc;	//第一个边结点
};
    
struct AdjGraph	
{
    int n;	//顶点数
    int e;	//边数
    VexNode AdjList[n];	//图的邻接表
};
~~~

---

邻接表的特点：

+ **<u>邻接表的表示不唯一</u>**：因为在每个顶点对应的单链表中各边结点的链接次序可以是任意的，取决于建立邻接表的算法以及边的输入次序

+ 对于无向图，邻接表中顶点i对应的单链表的边结点数目是顶点i的度

+ 对于有向图，邻接表中顶点i对应的单链表的边结点数目是顶点i的出度，邻接表中所有adjvex为i的边结点数目是顶点i的入度

+ :star:**<u>对于边数目较少的稀疏图，邻接表比邻接矩阵更节省存储空间</u>**

  + 对于有n个节点和e条边的无向图，其邻接表有n个头结点和2e个边结点
  + 对于有n个节点和e条边的有向图，其邻接表有n个头结点和e个边结点

  可以看出，邻接矩阵需要n^2^的空间，而邻接表只需要n+e或n+2e的空间，当n较大、e较小，即对于稀疏图来说，邻接表相比临近矩阵节省了很多的空间

+ 在邻接表中，查找顶点i关联的所有边是很快速的，只需要遍历顶点i对应的单链表即可，所以:star:**<u>在需要提取某个顶点的所有连接点的算法中通常采用邻接表存储结构</u>**

---

## 4. 图的基本运算算法

~~~C++
struct ArcNode	//边结点
{
    int adjvex;	//邻接点编号
    int weight;	//该边的权值
    ArcNode *nextarc;	//下一个边结点
    ArcNode(int _adjvex = -1, int _weight = 0, ArcNode *_nextarc = NULL)
    {
        adjvex = _adjvex;
        weight = _weight;
        nextarc = _nextarc;
    }
};

struct VexNode	//头结点
{
    int vertex;	//结点信息，如编号
    ArcNode *firstarc;	//第一个边结点
    VexNode(int vertex = -1, ArcNode *_firstarc = NULL)
    {
        vertex = _vertex;
        firstarc = _firstarc;
    }
};
    
struct AdjGraph	
{
    int n;	//顶点数
    int e;	//边数
    VexNode AdjList[n];	//图的邻接表
    AdjGraph(int _n = 0, int _e = 0)
    {
        n = _n;
        e = _e;
        for(int i = 0; i < n; i++)
        	AdjList[i].vertex = i;
    }
};
~~~

### 4.1 图的创建

首先为邻接表分配图G的顶点数n个存储空间，根据邻接矩阵（一般来说图都是这么输入的）查找不为零或无穷大的元素，找到这样的元素A\[i][j]后，创建一个adjvex为j、weight为A\[i][j]的边结点，采用头插法将它插入到顶点i对应的单链表中。

Algorithm: Create a graph stored in adjacency list, and return it

Input: Adjacency matrix AdjMat, the number of vertexes n, and the number of edges e

Output: Nothing, just return the graph

~~~C++
AdjGraph *CreateAdjGraph(int AdjMat[n][n], int n, int e)
{
    AdjGraph *G = new AdjGraph(n, e);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(A[i][j] != 0 && A[i][j] != MAX)
            {
                ArcNode *temp1 = new ArcNode(j, A[i][j]);	//建立边结点
				ArcNode *temp2 = new ArcNode(i, A[i][j])
                    
                temp1->nextarc = (G->AdjList[i]).firstarc;	//头插法
                (G->AdjList[i]).firstarc = temp1;
                
                temp2->nextarc = (G->AdjList[j]).firstarc;
                (G->AdjList[i]).firstarc = temp2;
            }
        }
    }
    
    return G;
}
~~~

---

### 4.2 图的输出

~~~C++
void DisplayAdjGraph(AdjGraph *G)
{
	for(int i = 0; i < G->n; i++)
	{
		cout << (G->AdjList[i]);
		ArcNode *temp = (G->AdjList[i]).firstarc;
		while(temp != NULL)
		{
			cout << temp->vertex << " " << temp->weight;
            temp = temp->nextarc;
		}
        cout << endl;
	}
}
~~~

---

### 4.3 图的销毁

~~~C++
void DestroyAdjGraph(AdjGraph *G)
{
    for(int i = 0; i < G->n; i++)
    {
        ArcNode *curr = (G->AdjList[i]).firstarc;
		while(curr != NULL)
        {
            ArcNode *prev = curr;
            curr = curr->next;
            delete prev;
        }
    }
}
~~~

---









