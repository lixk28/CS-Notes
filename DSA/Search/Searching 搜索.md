# Searching 搜索

Given a *pile* of records

The simplest way to do search: Sequential Search 顺序查找 

时间复杂度O(n)

~~~C++
Algorithm:

~~~

---

Binary Search 二分查找

需要序列预先排序，查找的是线性有序表

bottom <= mid < top 左闭右开

+ the forgetful version
+ the unforgetful version

~~~C++
Record data;
if(bottom < top)
    int mid = (bottom + top) / 2;
retrieve(mid, list, data)
    
    
~~~



---

STL中的binary search

---

w