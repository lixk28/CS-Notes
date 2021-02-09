# Binary Search 二分查找

二分查找是一种效率较高的查找方法。

**<u>二分查找要求线性表是有序表</u>**，即表中的元素按关键字有序。

---

:star:**二分查找的算法**（有序表是递增的）：

二分查找的基本思路是 $A[low,  high]$ 是当前查找的区间，首先确定该区间的中间位置 $mid = \lfloor \frac{low + high}{2} \rfloor$，然后将待查值 $key$ 与 $A[mid].key$ 进行比较：

+ 若 $key = A[mid].key$，则查找成功，返回该元素的序号
+ 若 $key < A[mid].key$，则由表的有序性可知右子表 $A[mid,high].key$ 均大于 $key$，因此新的查找区间是左子表 $A[low,mid-1]$
+ 若 $key > A[mid].key$，则由表的有序性可知左子表 $A[low,mid].key$ 均大于 $key$，因此新的查找区间是右子表 $A[mid+1,high]$

---

非递归：

~~~C++
int BinarySearch(int a[], int begin, int end, int key)
{
    int low = begin, high = end;
    int mid;
    while(low <= high)	//注意是小于等于!
    {
        mid = (low + high) / 2;
        if(key == a[mid])
            return mid;
       	else if(key < a[mid])
            high = mid - 1;
        else if(key > a[mid])
            low = mid + 1;
    }
    return -1;
}
~~~

如果 while 循环条件写成 `while(low < high)`，那么循环将会在 `low == high` 时终止，查找算法将会漏掉[low,high]这个区间，或者说会漏掉一个数，这个数没有被搜索到。

而循环条件 `while(low <= high)`  会使 while 循环在 `low == high + 1` 时终止，不会漏掉任何区间。

计算 mid 时为了防止溢出，最好写成：`mid = low + (low + high) / 2`

---

递归：

~~~C++
int BinarySearch(int a[], int begin, int end, int key)
{
    int mid = (begin + end) / 2;
    if(begin <= end)
    {
    	if(key == a[mid])
            return mid;
        else if(key > a[mid])
            return BinarySearch(a, mid + 1, end, key);
        else if(key < a[mid])
            return BinarySearch(a, begin, mid - 1, key);   
    }
    else
        return -1;
}
~~~



