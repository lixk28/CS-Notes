# Recursion 递归

An algorithm is **recursive（递归的）** if it calls itself (directly or indirectly) to do part of its work

逻辑结构是线性的可以用递归，比如阶乘factorial

递归的缺点是需要大量的空间消耗，而且不直观

递归必须要有两个部分：递归步和递归基

---

**汉诺塔可以用递归解决**（待完成）

斐波那契数列用递归方法解决的话，时间会很慢（因为有很多重复计算的地方），用迭代会更快

原则上所有的递归都可以用迭代来完成，两者可以相互转换，但这个转换需要用到栈

---

Design recursive algorithm:

1. Find the key step
2. Find a stopping rule
3. Outline your system
4. Check termination

---

Tree of fucntion call 函数调用树

A node（节点） denotes a function call with the function name

A function may invokes other functions, which are denoted as children

Different recursive calls appear as different vertices with the same name

---

