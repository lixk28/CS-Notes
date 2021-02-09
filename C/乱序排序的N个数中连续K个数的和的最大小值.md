# **乱序排序的N个数中连续K个数的和的最大/小值**

---

**题目描述**：给定一个整型序列 num ，求其子序列的和的最大值（子序列的最少包含一个元素）

**输入格式**：第一行为序列长度 n，第二行为序列的元素 num1，num2，...，numn

**输出格式**：子序列和的最大值

**示例**：

输入：

```C
9
-2 1 -3 4 -1 2 1 -5 4 
```

输出：

```C
6
```

模板：

~~~C
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    printf("%d\n", Max_SubArray(num, n));
    
    return 0;
}
~~~

只要实现 Max_SubArray 函数即可

Max_SubArray函数：

~~~C
Max_SubArray(int num[], int n);
~~~

---

## 方法一：暴力枚举

---

~~~C
Max_SubArray(int num[], int n)
{
    int max = num[0];
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        for(int j = i; j < n; j++)
        {
            tmp = tmp + num[j];
        	if(tmp > max)
                max = tmp;
        }
    }
    return max;
}
~~~

没什么好说的QAQ，时间复杂度O(n^2)



