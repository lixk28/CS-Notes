# Hash Table

[toc]

---

The implementation of hash tables is frequently called **hashing（哈希）**.

Hashing is a technique used for performing insertions, deletions, and finds in constant average time.

The ideal hash table data str	ucture is merely an array of some fixed size containing the items.

Refer to the table size as TableSize, each key is mapped into some number in the range 0 to TableSize − 1 and placed in the appropriate cell. The mapping is called a **hash function（哈希函数）**.

This is the basic idea of hashing. The only remaining problems deal with choosing a function, deciding what to do when two keys hash to the same value (this is known as a **collision（冲突）**), and deciding on the table size.

---

Hash function: h(K) = K mod TableSize

---

$\frac{Records \ 记录数}{Table \ Size \ 哈希表的大小}=load \ factor \ 装载因子$

---

## 1. Hash Table 哈希表

**哈希表(hash table)** 又称**散列表**。

其构造思路是：设要存储的元素个数为 n，设置一个长度为 m(m $\geq$ n) 的连续内存单元，以每个元素的关键字 k~i~(0 $\leq$ i $\leq$ n-1) 为自变量，通过一个称为**哈希函数(hash fuction)** 的函数 h(k~i~) 把 k~i~ 映射为内存单元的地址（或下标）h(k~i~)，并把该元素存储在这个内存单元中，h(k~i~) 也称为**哈希地址(hash address)**。

在构建哈希表的时候可能出现这样的问题，两个关键字 k~i~ 和 k~j~ (i $\neq$ j) 有 k~i~ $\neq$ j，但会出现 h(k~i~) = h(k~j~) 的情况，这种现象称为**哈希冲突(hash collisions)**。通常把这种具有不同关键字而具有相同哈希地址的元素称为**同义词(synonym)**，这种冲突也称为**同义词冲突**。

---

在哈希表存储结构中，哈希冲突是很难避免的，除非关键字的变化区间小于等于哈希地址的变化区间，而这种情况当关键字取值不连续时是非常浪费存储空间的。通常的实际情况是关键字的取值区间远大于哈希地址的变化区间。

哈希表的查找性能与以下几个因素有关：

+ 与装填因子 $\alpha$ 有关：**装填因子(load factor)**是指哈希表中已存入的元素数 n 与哈希地址空间大小 m 的比值，即$\displaystyle 装填因子 \ load \ factor = \frac{存入元素数 \ n}{哈希表的大小 \ m}$。$ \alpha $ 越小，空闲单元的比例越大，空间的利用率就越低，冲突的可能性就越小；$ \alpha $ 越大，空闲单元的比例越小，空间的利用率就越高，冲突的可能性就越大。考虑到减少冲突的发生和提高存储空间利用率两个方面，通常使最终的 $\alpha$ 控制在 0.6-0.9 的范围内。
+ 与哈希函数 $h(k_i)$ 有关：若哈希函数选择得当，就可以使哈希地址尽可能均匀地分布在哈希地址空间上，从而减少冲突的发生；若哈希函数选择不当，就可能使哈希地址集中于某些区域，从而加大冲突的发生。
+ 与哈希冲突的解决方法有关：当出现哈希冲突时需要采用解决冲突的方法，查找性能也与解决方法有关。

---

## 2. Hash Function 哈希函数

哈希函数的构造方法：

+ **直接定址法**：以关键字 k 本身或关键字加上某常量 c 作为哈希地址。
  + 哈希函数：$ h(k) = k + c $
  + 优点：哈希函数计算简单
  + 缺点：当关键字的分布连续时，可用直接定址法的哈希函数，否则，若关键字的分布不连续将造成内存单元的大量浪费
+ **除留余数法**：以关键字 k 除以某个<u>不大于哈希表长度 size</u> 的整数 p  所得的余数作为哈希地址。
  + 哈希函数：$ h(k) = k \ mod \ p \ (p \leq size)$ 
  + 优点：哈希函数计算简单，适用范围广，是最常用的一种哈希函数
  + 这种方法的关键是选择好 p，使得元素集合中的每一个关键字通过该函数转换后映射到哈希表范围内的任意地址上的概率相等，从而尽可能减少冲突发生的可能性。p 取奇数比 p 取偶数好。
  + 理论研究表明：**<u>p 取不大于 size 的素数时效果最好</u>**

---

## 3. Hash Collision 哈希冲突

哈希冲突的解决方法主要有：

+ 开放定址法
  + 线性探测法
  + 平方探测法
+ 拉链法

---

### 3.1 Open Addressing 开放定址法

**开放定址法(open addressing)**就是在出现哈希冲突时在哈希表中寻找一个新的空闲位置存放元素。

要存放关键字为 k~i~ 的元素，d = h(k~i~)，而地址为 d 的内存单元已经被其他的元素占用了，那么就在地址 d 的前后寻找空闲位置。

根据开放定址法寻找空闲单元的方式又分为线性探测法和平方探测法。

---

#### 3.1.1 Linear Probing 线性探测法

**线性探测法(linear probing)** 是从发生冲突的地址 d~0~ 开始，依次探测 d~0~ 的下一个地址（哈希表表尾 m-1 的下一个探测地址是表首 0），直到找到一个空闲单元为止（当 m $\geq$ n 时一定能找到一个空闲单元）。

线性探测法的数学递推公式为：
$$
\begin{aligned}
&d_0 = h(k) \\
&d_i = (d_{i-1} + 1) \ mod \ m \quad (1 \leq i \leq m-1)
\end{aligned}
$$
 其中，模 m 是为了保证找到的位置在 0~m-1 的有效空间中。

线性探测法的优点是解决冲突简单，一个重大的缺点是容易产生堆积问题。这是由于当<u>连续出现</u>若干个(n个)同义词时，设第一个同义词占用单元 d~0~，则这连续 n 个同义词将占用哈希表的 d~0~、d~1~、……、d~n-1~ 单元，随后任何哈希映射到 d~0~、d~1~、……、d~n-1~ 的关键字都会由于这些同义词的占用而产生冲突，尽管随后的这些关键字并没有同义词。这称为**非同义词冲突**，是哈希函数值不相同的两个元素争夺同一个后继哈希地址导致出现堆积（或聚集）现象。

eg: 哈希表的长度为13，用除留余数法和线性探测法构造关键字集合为 {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77} 的哈希表

取 p = 13（不大于hash table size的素数），构造的哈希表 hash[13]：

| **下标**   | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   | 12   |
| ---------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| **关键字** | 77   |      | 54   | 16   | 43   | 31   | 29   | 46   | 60   | 74   | 88   |      | 90   |

---

#### 3.1.2 Square Probing 平方探测法

平方探测法(square probing) 是从发生冲突的地址 d~0~ 开始，依次对探测序列 $d_0 \pm n^2$ ，即 d~0~ + 1^2^、d~0~ - 1^2^、d~0~ + 2^2^、d~0~ - 2^2^、…… 进行探测，直到找到一个空闲单元。

平方探测法的数学递推公式为：
$$
\begin{aligned}
&d_0 = h(k) \\
&d_i= (d_0 \pm i^2) \ mod \ m \quad (1 \leq i \leq m-1)
\end{aligned}
$$
平方探测法是一种较好地处理冲突的方法，可以避免出现堆积问题，其缺点是不一定能探测到哈希表上的所有单元，但最少能探测到一半单元。

---

#### 3.1.3 伪随机序列法

---

### 3. 2 Double Hashing 再哈希

---

### 3.3 Chaining 拉链法

拉链法(chaining) 是把所有的同义词用单链表链接起来的方法。

所有哈希地址为 d~i~ 的元素对应的节点构成一个单链表，**<u>这时哈希表的每个单元存放的不再是元素本身，而是相应同义词单链表的头结点指针值</u>**。由于在单链表中可以插入任意多个节点，因此此时装填因子既可以小于等于1，也可以以大于1。

拉链法有以下几个优点：

+ 拉链法处理冲突简单，**没有堆积现象**，即非同义词绝对不会发生冲突，因此平均查找长度较短
+ 拉链法更适用于建表前无法确定表长的情况，因为各单链表上的节点空间是动态申请的
+ 拉链法中装填因子可大于等于1，且当元素规模较大时，增加的指针域可以忽略不计，因此节省空间

拉链法有以下几个缺点：

+ 指针需要额外的空间，当元素规模较小时，开放定址法较为节省空间
+ 若将节省的指针空间用来扩大哈希表的规模，可使装填因子变小，这又减少了开放定址法中的冲突，从而提高了平均查找速度

eg: 哈希表的长度为 13，用除留余数法和拉链法构建关键字集合为 {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77} 的哈希表

取 p = 13，构造的哈希表 hash[12] 为：

<style type="text/css">
.tg  {border-collapse:collapse;border-color:#ccc;border-spacing:0;}
.tg td{background-color:#fff;border-color:#ccc;border-style:solid;border-width:1px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{background-color:#f0f0f0;border-color:#ccc;border-style:solid;border-width:1px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-c3ow{border-color:inherit;text-align:center;vertical-align:top}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
.tg .tg-0lax{text-align:left;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-0pky">下标</th>
    <th class="tg-0pky">哈希表(表头)</th>
    <th class="tg-c3ow" colspan="2">链表</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0pky">0</td>
    <td class="tg-0pky">NULL</td>
    <td class="tg-0pky"></td>
    <td class="tg-0pky"></td>
  </tr>
  <tr>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">NULL</td>
    <td class="tg-0pky"></td>
    <td class="tg-0pky"></td>
  </tr>
  <tr>
    <td class="tg-0pky">2</td>
    <td class="tg-0pky">d2</td>
    <td class="tg-0pky">54</td>
    <td class="tg-0pky"></td>
  </tr>
  <tr>
    <td class="tg-0lax">3</td>
    <td class="tg-0lax">d3</td>
    <td class="tg-0lax">29</td>
    <td class="tg-0lax">16</td>
  </tr>
  <tr>
    <td class="tg-0lax">4</td>
    <td class="tg-0lax">d4</td>
    <td class="tg-0lax">43</td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">5</td>
    <td class="tg-0lax">d5</td>
    <td class="tg-0lax">31</td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">6</td>
    <td class="tg-0lax">NULL</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">7</td>
    <td class="tg-0lax">d7</td>
    <td class="tg-0lax">46</td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">8</td>
    <td class="tg-0lax">d8</td>
    <td class="tg-0lax">60</td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">9</td>
    <td class="tg-0lax">d9</td>
    <td class="tg-0lax">74</td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">10</td>
    <td class="tg-0lax">d10</td>
    <td class="tg-0lax">88</td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">11</td>
    <td class="tg-0lax">NULL</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-0lax">12</td>
    <td class="tg-0lax">d12</td>
    <td class="tg-0lax">77</td>
    <td class="tg-0lax">90</td>
  </tr>
</tbody>
</table>

---

