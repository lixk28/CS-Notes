# Tree 树

## 1. 树的定义

**树（tree）**是由 n (n $\geq$ 0) 个节点组成的有限集合，记为 **T**

+ 如果 n = 0，称为**空树（empty tree)**
+ 如果 n > 0，这 n 个节点中有且仅有一个节点作为树的**根节点（root node）**，简称为**根（root）**；其余节点可分为 m (m $\geq$ 0 ) 个互不相交的有限集 T~1~, T~2~, ... , T~m~，其中每个子集本身又都是一棵符合本定义的树，称为根节点的**子树（subtree）**

---

树的抽象数据类型描述：

~~~C++
ADT Tree
{
    数据对象：
        D = {ai}
}
~~~

---

## 2. 树的基本术语

+ **节点的度（degree of node）**：树中某个节点的子树的个数

+ **树的度（degree of tree）**：树中所有节点的度中的<u>最大值</u>

  通常将度为 m 的树称为 **m次树（m-tree)**

  

+ **分支节点/内部节点/非终端节点（branch node/internal node/non-terminal node）**：树中度不为 0 的节点称为内部节点，或分支节点，或非终端节点

+ **叶子节点/外部节点/终端节点（leaf node/external node/terminal node）**：树中度为 0 的节点称为叶子节点，或外部节点，或终端节点

+ **孩子节点/子节点（children）**：树中每个节点的后继节点（如果有的话）被称为该节点的孩子节点

+ **双亲节点/父节点（parents/father）**：孩子节点的前驱节点称为该孩子节点的双亲节点

+ **兄弟节点（sibling）**：具有同一双亲节点的孩子节点互为兄弟节点

+ **子孙节点（descendant）**：树中每个节点作为根节点的子树中的所有节点（除本身）称为该节点的子孙节点

+ **祖先节点（ancestor）**：从根节点到达某个节点的路径上经过的所有节点（除本身）称为该节点的祖先节点



+ **路径（path）**：对于树中的任意两个节点 k~i~ 和 k~j~，若树中存在一个节点序列 (k~i~, ..., k~j~)，使得序列中除 k~i~ 以外的任一节点都是其在序列中的前一个节点的后继节点，则称该节点序列为由 k~i~ 到 k~j~ 的一条路径

+ **路径长度（path length）**：某个路径的路径长度是该路径所通过的节点数目减1，即路径上的分支数目

  路径就是从 k~i~ 出发**自上而下**到达k~j~所通过的树中的节点序列



+ **节点层次/节点深度（level of node/depth of node）**：根节点到该节点的唯一路径长度为该节点的层次或深度，根节点的层次/深度定义为0
+ **树的高度/树的深度（height of tree/depth of tree）**：树中所有节点的深度的最大值称为树的高度或深度



+ **有序树（ordered tree）和无序树（unordered tree）**：若树中各节点的子树是按照一定次序从左向右安排的，且相对次序保持不变，则称为有序树，否则称为无序树
+ **森林（forest）**：n (n > 0) 个互不相交的树的集合称为森林

---

## 3. 树的性质

+ ***树的节点数 = 树所有节点的度数之和 + 1***

+ ***一棵 m 次树的第 i 层上最多有 m^i-1^ 个节点 (i $\geq$ 1)***

  若一棵 m 次树的第 i 层上有 m^i-1^ 个节点，则称该层是**满（full）的**

  若一棵 m 次树的所有叶子节点在同一层，且除该层以外的每一层都是满的，则称这棵树为**满 m 次树（full m-tree）**，显然，满 m 次树是所有相同高度的 m 次树中节点总数最多的树，也可以说，对于 n 个节点，构造的 m 次树为满 m 次树或接近满 m 次树时，这时树的高度最小

+ ***高度为 h 的 m 次树最多有 $\frac{m^h - 1}{m - 1}$ 个节点***

  **特别的，对于高度为 h 的二叉树，最多有 2^h^ - 1 个节点**

  高度为 h 的 m 次树是满 m 次树时，节点个数最多，因此

  最多节点数 = 每层的最多节点数之和 = m^0^ + m^1^ + ... + m^h-1^ =  $\frac{m^h - 1}{m - 1}$ （等比数列求和）

+ ***具有 n 个节点的 m 次树的最小高度为 $\lceil \log_m{(n(m-1)+1)} \rceil$***

  **特别的，对于 n 个节点的二叉树，最小高度为 $\lceil \log_2{(n+1)} \rceil$**

  设具有 n 个节点的 m 次树的高度为 h，若该树的前 h - 1 层都是满的，第 h 层的节点数可能满，也可能不满，但至少有一个节点，则该树具有最小的高度

  则有：$\frac{m^{h-1} - 1}{m - 1} + 1 \leq n \leq \frac{m^h - 1}{m - 1}$

  亦即：$\frac{m^{h-1} - 1}{m - 1} < n \leq \frac{m^h - 1}{m - 1}$

  同乘(m-1)后加1：$m^{h-1} < n(m-1)+1 \leq m^h$

  取以m为底的对数：$h - 1 < \log_m{(n(m-1)+1) \leq h}$

  即有：$\log_m{(n(m-1)+1) \leq h < \log_m{(n(m-1)+1) + 1}}$

  因为h是整数，所以：$h = \lceil \log_m{(n(m-1)+1)} \rceil$（向上取整）

---

## 4. 树的基本运算

+ **Search（查找）**：查找某个节点
+ **Insert（插入）**：插入某个节点
+ **Delete（删除）**：删除某个节点
+ **Traversal（遍历）**：遍历树中的所有节点
  + **Preorder traversal（先序遍历）**
  + **Postorder traversal（后序遍历）**
  + **Level traversal（层序遍历）**

---

## 5. 树的存储结构

+ 双亲存储结构（parent storage structure)

  双亲存储结构是一种顺序存储结构，用一组连续空间存储树的所有节点，同时在每个节点中设置一个伪指针指示其双亲节点的位置（根节点的双亲节点伪指针设置为 -1）

  在这种存储结构中，求某个节点的双亲节点非常容易，但求某个节点的孩子节点时需要遍历整个存储结构

  ~~~C++
  struct TreeNode
  {
      ElemType data;
      int parent;
  }
  ~~~

+ 孩子链存储结构（child chain storage structure)

  孩子链存储结构中，每个节点不仅包含关键字，还包括指向所有孩子节点的指针，由于树中每个节点的子树个数即度不同，因此可按树的度来设置节点的指针域个数

  ~~~C++
  struct TreeNode
  {
      ElemType data;
      TreeNode *children[MaxNum];	//MaxNum为树的度
  }
  ~~~

+ 孩子兄弟链存储结构（child brother chain storage structure)

  孩子兄弟链存储结构中，每个节点设置3个域，数据域、指向该节点的左边第一个孩子节点的指针域、指向该节点的下一个兄弟节点的指针域

  ~~~C++
  struct TreeNode
  {
      ElemType data;
      TreeNode *sibling;	//指向兄弟
      TreeNode *children;	//指向长子
  }
  ~~~

  
