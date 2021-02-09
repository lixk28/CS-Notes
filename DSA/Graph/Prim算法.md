# Prim算法

**普利姆(Prim)算法**是一种构造性算法。

设$G=(V, E)$是一个具有n个顶点的带权连通图，$T=(U, A)$是G的最小生成树，其中U是T的顶点集，A是T的边集，则由G构造从起始点v出发的最小生成树T的Prim算法为：

---

:cyclone:`Prim Algorithm`

Input: A weighted directed graph G(带权有向图G) with vertex set V(顶点集V) and edge set E(边集E)

Output: the minimal spanning tree T(最小生成树T) of G with vertex set V~T~(顶点集V~T~) and edge set E~T~(边集E~T~)

Algorithm:

:one: 初始化：$V_T = \{x\}, \ E_T = \{\}$，其中x为顶点集V中的任一顶点

:two: 选取：重复下列操作，直到$V_T = V$

1. 在集合$E$中选取权值最小的边$(v, w)$，其中$v \in V_T, \ w \in V - V_T$
2. 将$w$加入到集合$V_T$中，将$(v, w)$加入到集合$E_T$中

---

