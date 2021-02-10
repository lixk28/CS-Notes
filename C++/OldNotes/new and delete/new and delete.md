# **new** and **delete**

---

## 1. new 和 delete 运算符

C++直接定义了两个运算符来分配和释放动态内存

运算符 **new** 分配内存，运算符 **delete** 释放 new 分配的内存

以下是内存空间：

分为**代码区**、**静态区**、**动态区**，其中动态区包括堆空间和栈空间

代码区存储源代码，静态区存储静态变量和全局变量，动态区存储局部变量和参数

<img src="C:\Users\Lenovo\Desktop\Note\C++\images\Memory Space.png" style="zoom: 50%;" />

**Heap(堆)**是可供程序员使用的动态内存，**Stack(栈)**是系统调用分配的动态内存

The new and delete operator are available to manipulate free store(heap). new 和 delete 运算符是用来操纵heap的内存

Free store is a system-provided memory pool for objects whose lifetime is directly managed by the programmer. heap中存储的内容生命期由程序员决定

---

## 2. new 和 delete 的用法

---

### 2.1 new 的用法

#### 2.1.1 开辟单变量地址空间

使用new运算符时**必须已知数据类型**，new运算符会向系统堆区申请足够的存储空间

**若申请成功，就返回该内存块的<u>首地址</u>，若申请不成功，则返回零值**

new无法为其分配的对象命名，而是返回一个指向该对象的指针

**new 开辟单变量空间的一般使用格式：**

    格式1：指针变量名 = new 类型标识符;
    格式2：指针变量名 = new 类型标识符(初始值);
**说明**：**格式1和格式2都是申请分配某一数据类型所占字节数的内存空间**

​		   **但格式2在内存分配成功后，同时将一初值存放到该内存单元中**

~~~C++
int *p1 = new int; //申请一个sizeof(int)内存单元，并将地址返回
int *p2 = new int(1); //在申请的同时赋初值为1
int *p3 = new int();  //在申请的同时赋初值为0
~~~

#### 2.1.2 开辟数组空间

**new 开辟数组空间的一般使用格式：**

~~~C++
指针变量名 = new 类型标识符[内存单元个数];
~~~

**说明**：**申请sizeof(data type)的若干个连续内存单元，并返回该内存段的首地址**

​		   **相当于申请了一个动态数组**

~~~C++
int *p1 = new int[10];                //申请一维数组
int (*p2)[5] = new int[5][5];         //申请二维数组
int (*p3)[5][5] = new int[5][5][5];   //申请三维数组
//多维数组依次类推

/*
注意： int (*p)[n] 是定义一个数组指针（指向一维数组的指针），基类型为 int(*)[n]
	  int (*p)[m][n] 是定义一个数组指针（指向二维数组的指针）,基类型为 int(*)[m][n]
	  不要写成 int *p[n]，这样就是定义了一个指针数组
*/
~~~

---

### 2.2 delete 的用法

#### 2.2.1 删除单变量地址空间

**<u>delete 的作用不是删除指针，而是释放该指针指向的内存</u>**

**delete 某个指针后，该指针仍然存在，只是它指向的内存已经被回收，不能使用了**

**一般形式为：**

~~~C++
指针变量名 = new 类型标识符;
delete 指针变量名;
~~~

~~~C++
int *p = new int;
delete p;  //释放p指向的内存空间
~~~

#### 2.2.2 删除数组空间

**一般形式为：**

~~~C++
指针变量名 = new 类型标识符[内存单元个数];
delete[] 指针变量名;
//delete的方括号中不需要填数组元素个数，系统会自动检测，即使写了编译器也会忽略
~~~

~~~C++
int *p1 = new int[10];
delete[] p1;  //释放p1指向的数组空间
~~~

---

## 3. 用 new 和 delete 创建动态数组

### 3.1 创建并释放动态一维数组

~~~C++
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n]; //创建动态一维数组 
    
    for(int i = 0; i < n; i++)
    	cin >> arr[i];
    for(int i = 0; i < n; i++)
    	cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
~~~

### 3.2 创建并释放动态二维数组

~~~C++
#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cin >> row >> col; //输入数组的行数和列数 
    
    int **arr = new int *[row]; //为行指针分配空间
    for(int i = 0; i < row; i++)
         arr[i] = new int[col]; //为每行分配空间（每行中有col个元素） 
    
    for(int i = 0; i < row; i++)  //输入维数组中的数  
        for(int j = 0; j < col; j++) 
        	cin >> arr[i][j];

    for(int i = 0; i < row; i++)  //输出二维数组中的数  
        for(int j = 0; j < col; j++) 
          cout << arr[i][j] << " ";
    cout << endl;
    
    for(int i = 0; i < row; i++) //释放二维数组（反过来） 
        delete[] arr[i]; 
    delete[] arr; //注意：arr是一个指针数组(int*)[row]空间的首地址
    
    return 0;
}
~~~

<img src="C:\Users\Lenovo\Desktop\Note\C++\images\动态二维数组.png" style="zoom:67%;" />

**注意**：**是先为二级指针 arr 分配了一段一级指针数组，再为该指针数组中的每个一级指针分配一个数组**

​		   **即我们用 new 申请了一段内存以存放数组指针，再为每个数组指针申请一段内存**

​		   **所以要依次 delete，先 delete 各个数组，再 delete 指向这些数组的指针数组**

​		**<u>千万不要忘记 delete[] arr !!!</u>**

---

## 4. 使用 new 和 delete 管理动态内存的注意事项

+ **不要忘记 delete 内存**

  若忘记 delete 用 new 申请的内存，会出现**内存泄漏(memory leak)**的问题，**内存泄漏指的是分配出去的堆空间内存无法回收**

+ **不要重复释放一块内存**

  当有两个指针指向同一个动态内存分配对象时，可能会出现这个问题

  若对 delete 其中一个指针，随后又对另一个指针 delete，就会造成**重复释放(double free)**

+ **不要使用和解引用空悬指针**

  **空悬指针(dangling pointer)**是指被 delete 后的指针

  当我们 delete 一个指针后，指针值就无效了，虽然指针已经无效，但指针依然保存着已经释放了的动态内存的地址

  **可以通过在 delete 某个指针后，将该指针置为nullptr，有时可以检测出这种错误**