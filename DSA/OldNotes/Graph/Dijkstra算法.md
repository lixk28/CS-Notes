# Dijkstra算法

+ 在一个不带权图中，若从一个顶点到另一个顶点存在着一条路径，则称该路径长度为该路径上所经过的边的数目，它等于该路径上的顶点数减1。

+ 在一个带权图中，若从一个顶点到另一个顶点存在着一条路径，则称该路径长度为该路径上所经过的边的权值之和。

由于从一个顶点到另一个顶点可能存在多条路径，每条路径上所经过的边数可能不同，即路径长度不同，把路径长度最短（即经过的边数最少）的那条路径称为**最短路径(shortest path)**，其长度称为**最短路径长度(shortest path length)**。

求图的最短路径有两个方面的问题：

+ 单源最短路径：Dijkstra算法
+ 顶点之间最短路径：Floyd算法

---

## 单源最短路径

Problem: 给定一个带权有向图G与源点v，求从源点v到G中其余顶点的最短路径，并限定各边上的权值大于0

:cyclone:`Dijkstra Algorithm`

Input:  A weighted directed graph G(带权有向图G) with vertex set V(顶点集V) and edge set E(边集E)

Output: dist[] and path[] represent the minimal distance of source vertex s to each vertex and the responding path

Algorithm:

给定一个源点$v$，算法维护两个顶点集合$S$和$V - S$，以及两个数组$dist$和$path$。
其中，集合$S$保存所有<u>**已知**</u>$v$到$w$最短路径的顶点$w$，集合$V-S$则保留其他所有顶点。
$dist$数组存放的是$v$到其余各顶点的最短路径长度，即$dist[w]$存放$v$到$w$的最短路径长度。
$path$数组存放的是$v$到其余各顶点的最短路径，$path[w]$存放$v$到$w$最短路径上顶点$w$的前一个顶点，可以根据$path$倒推出源点到各点的最短路径。（可以这么做的原因见后面的证明）

---

:one: 初始化：$S = \emptyset, \ V-S = V \\ dist: 源点为0，其余全部为\infty \\  path: 全部为-1$

:two: 选取：选取$V-S$中$dist$值最小的顶点$u$，将$u$加入$S$中，将$u$从$V-S$中去掉

:three: 松弛操作：考察顶点$u$的**<u>所有以其为起点</u>**的<u>**且属于$V-S$**</u>的邻接点$w_i$，若$dist[u] + weight(u, w_i)$的值小于$dist[w_i]$，则更新$dist[w_i]$的值为$dist[u] + weight(u, w_i)$，并将$path[w_i]$的值修改为$u$，否则不进行任何修改

一直进行操作:two:和操作:three:，**直到$S = V$**，最后$dist$数组中就存放了源点$v$到其余所有点的最短路径长度，而$path$数组中存放了源点$v$到其余所有点的最短路径上该点的前一个顶点，根据这个可以倒推出最短路径。

---

Example: 

对于下面的带权有向图G，求源点为0的单源最短路径及路径长度
<img src="E:\image\image-20201128191231458.png" alt="image-20201128191231458" style="zoom:60%;" /><img src="E:\image\image-20201128191520123.png" alt="image-20201128191520123" style="zoom: 67%;" />

:new: $S = \emptyset, \ V-S = \{0,1,2,3,4,5,6,7\} \\ dist = \{0,\infty,\infty,\infty,\infty,\infty,\infty,\infty \} \\ path = \{-1,-1,-1,-1,-1,-1,-1,-1\} $

:one:$V-S$中$dist$值最小的是0，将0加入$S$，将0从$V-S$中去掉

​	考察以顶点0为起点的所有邻接点，有顶点1和顶点2，则修改：
​	$dist[1] = min(dist[1], \ dist[0] + weight(0,1)) = min(\infty,2) = 2 \\ dist[2] = min(dist[2], \ dist[2]+weight(0,2)) = min(\infty,2) = 2$

​	$dist[1]$和$dist[2]$的值都发生改变，修改$path[1]$和$path[2]$的值:
​	$path[1] = 0 \\ path[2] = 0$

​	$S = \{0\}, V-S = \{1,2,3,4,5,6,7\} \\dist = \{0,2,2,\infty,\infty,\infty,\infty,\infty\} \\ path = \{-1,0,0,-1,-1,-1,-1,-1\}$

:two:$V-S$中$dist$值最小的是1，将1加入$S$，将1从$V-S$中去掉

​	考察以顶点1为起点的所有邻接点，有顶点6，则修改：
​	$dist[6] = min(dist[6], \ dist[1]+weight(1,6)) = min(\infty,11) = 11$

​	$dist[6]$的值发生改变，修改$path[6]$的值：
​	$path[6] = 1$

​	$S = \{0,1\}, V-S = \{2,3,4,5,6,7\} \\dist = \{0,2,2,\infty,\infty,\infty,11,\infty\} \\ path = \{-1,0,0,-1,-1,-1,1,-1\}$

:three:$V-S$中$dist$值最小的是2，将2加入$S$，将2从$V-S$中去掉

​	考察以顶点2为起点的所有邻接点，有顶点6，则修改：
​	$dist[6] = min(dist[6], \ dist[2] + weight(2,6)) = min(11,5) = 5$

​	$dist[6]$的值发生改变，修改$path[6]$的值：
​	$path[6] = 2$

​	$S = \{0,1,2\}, V-S = \{3,4,5,6,7\} \\dist = \{0,2,2,\infty,\infty,\infty,5,\infty\} \\ path = \{-1,0,0,-1,-1,-1,2,-1\}$

:four:$V-S$中$dist$值最小的是6，将6加入$S$，将6从$V-S$中去掉

​	考察以顶点6为起点的所有邻接点，有顶点4、顶点5和顶点7，则修改：
​	$dist[4] = min(dist[4], \ dist[6] + weight(6,7)) = min(\infty, 12) = 12$
​	$dist[5] = min(dist[5], \ dist[6]+weight(6,5)) = min(\infty,6) = 6$
​	$dist[7] = min(dist[7], \ dist[6] + weight(6,7)) = min(\infty,14) = 14$

​	$dist[4],dist[5],dist[7]$的值都发生改变，修改：
​	$path[4] = 6 \\ path[5] = 6 \\ path[7] = 6$

​	$S = \{0,1,2,6\}, V-S = \{3,4,5,7\} \\dist = \{0,2,2,\infty,12,6,5,14\} \\ path = \{-1,0,0,-1,6,6,2,6\}$

:five:$V-S$中$dist$最小的是5，将5加入$S$，将5从$V-S$中去掉

​	考察以顶点5为起点的所有邻接点，有顶点1、顶点3和顶点7，则修改：
​	$dist[1] = min(dist[1], \ dist[5] + weight(5,1)) = min(2,11) = 2$
​	$dist[3] = min(dist[3], \ dist[5] + weight(5,3)) = min(\infty, 7) = 7$
​	$dist[7] = min(dist[7], dist[5]+weight(5,7)) = min(14,15) = 14$

​	只有$dist[3]$的值发生改变，修改：
​	$path[3] = 5$

​	$S = \{0,1,2,6,5\}, V-S = \{3,4,7\} \\dist = \{0,2,2,7,12,6,5,14\} \\ path = \{-1,0,0,5,6,6,2,6\}$

:six:$V-S$中$dist$最小的是3，将3加入$S$，将3从$V-S$中去掉

​	考察以顶点3为起点的所有邻接点，没有任何邻接点，不进行任何操作

​	$S = \{0,1,2,6,5,3\}, V-S = \{4,7\} \\dist = \{0,2,2,7,12,6,5,14\} \\ path = \{-1,0,0,5,6,6,2,6\}$

:seven:$V-S$中$dist$最小的是4，将4加入$S$，将4从$V-S$中去掉

​	考察以顶点4为起点的所有邻接点，有顶点2，则修改：
​	$dist[2] = min(dist[2], \ dist[4] + weight(4,2)) = min(2,18) = 2$

​	$dist[2]$的值没有发生改变，不修改$path[2]$的值

​	$S = \{0,1,2,6,5,3,4\}, V-S = \{7\} \\dist = \{0,2,2,7,12,6,5,14\} \\ path = \{-1,0,0,5,6,6,2,6\}$

:eight:$V-S$中$dist$最小的是7，将7加入$S$，将7从$V-S$中去掉

​	考察以顶点7为起点的所有邻接点，没有任何邻接点，不进行任何操作

​	$S = \{0,1,2,6,5,3,4,7\}, V-S = \emptyset \\dist = \{0,2,2,7,12,6,5,14\} \\ path = \{-1,0,0,5,6,6,2,6\}$

$V-S$为空集，结束，最后得到的结果就是$dist$和$path$

---

伪代码：

~~~C++
function Dijkstra(Graph, source):
	
	create vertex set Q
    
    // Initial
   	for each vertex v in Graph:           
    	dist[v] ← INFINITY                 
        prev[v] ← UNDEFINED                
        add v to Q                     
    dist[source] ← 0                       
    
    while Q is not empty:
    	u ← vertex in Q with min dist[u]  	// Choose
        remove u from Q
         
       	for each neighbor v of u:           // only v that are still in Q
        	alt ← dist[u] + length(u, v)	// Relax
            if alt < dist[v]:              
            	dist[v] ← alt
                prev[v] ← u

    return dist[], prev[]
~~~









