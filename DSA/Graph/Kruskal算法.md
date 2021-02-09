# Kruskal算法

**克鲁斯卡尔(Kruskal)算法**是一种按权值的递增次序选择合适的边来构造最小生成树的算法。

设$G=(V, E)$是一个具有n个顶点的带权连通图，$T=(U, A)$是G的最小生成树，其中U是T的顶点集，A是T的边集，则由G构造从起始点v出发的最小生成树T的Kruskal算法为：

---

:cyclone:`Kruskal Algorithm`

Input: A weighted directed graph G(带权有向图G) with vertex set V(顶点集V) and edge set E(边集E)

Output: the minimal spanning tree T(最小生成树T) of G with vertex set V~T~(顶点集V~T~) and edge set E~T~(边集E~T~)

Algorithm:

:one: 初始化：建立图$T$，$V_T = V, \ E_T = \{\}$

:two: 排序：将$E$中的边升序排序

:three: 选取：从排序后的$E$中依次升序选取边$e$，若选取的边$e$的两个邻接点不在当前图$T$的同一个连通分量（就是边$e$的加入不会使$T$形成回路），则将$e$加入$E_T$中，否则舍弃，直到$E_T$中包含(n-1)条边为止

---

