# **Function Overloading 函数重载**

---

## 1.函数重载

如果一个作用域内的多个**<u>函数名字相同</u>**但**<u>形参列表不同</u>**，称为**重载函数(overloaded function)**

**重载(overload)**就是装载多种东西的意思，即同一个事物能完成不同功能

这些函数接受的形参类型不同，但执行的操作类似

在调用这些函数时，编译器会根据传递的实参类型和个数来推断是在调用那个函数

**注意**：**main函数不能重载**

例如：

~~~C++
int sum(int a, int b);
double sum(double x, double y);
std::string sum(std::string s1, std::string s2);
//而在C中函数名字不能重复，必须命名成例如sum1、sum2、sum3

int sum(int a, int b)
{
    return a + b; 
}

double sum(double x, double y)
{
    return x + y;
}

std::string sum(std::string s1, std::string s2)
{
    return s1 + s2;  //将两个string连接
}

~~~

~~~C++
cout << sum(10, 10) << endl; 	 		//output:20
cout << sum(10.5, 9.8) << endl;  		//output:20.3
cout << sum(10.5, 10.5) << endl;         //output:21
cout << sum("I am", " Groot") << endl;   //output:I am Groot
~~~

函数重载在一定程度上减轻了程序员起名字、记名字的负担

---

## 2.定义重载函数

函数重载的规则：

- **函数名称必须相同**

- **参数列表必须不同**（包括个数不同、类型不同、参数排列顺序不同）

  注意：**仅仅参数名称不同不行**

- **函数的返回类型可以相同也可以不相同**

  注意：**仅仅返回类型不同不能成为函数的重载**（返回类型不能作为重载的依据），<u>而是函数的重复定义</u>

也就是说，**<u>重载的函数函数名必须相同，参数列表必须不同</u>**，而函数返回类型没有限制

~~~C++
int sum(int a, int b); 

int SUM(int a, int b); //no
int sum(int a, int b, int c); //yes
double sum(double a, double b); //yes
int sum(int x, int y); //no
char sum(char a, char b); //yes
char sum(int a, int b); //no
~~~

有时候两个形参列表看起来不一样，但实际上是相同的：

~~~C++
int sum(int a, int b); 
int sum(int, int); //no
//只是省略了形参的名字，但形参的名字对参数列表毫无影响

int sum(int a, int b); 
typedef int _int;
int sum(_int, _int); //no
//只是创建了一个类型别名，并没创建新类型，本质上没有不同
~~~

顶层const不影响传入函数的对象，一个拥有顶层的const形参无法和另一个没有顶层const的形参区分开来：

~~~C++
int sum(int a, int b);
int sum(const int a, const int b); // no

int sum(int *a, int *b);
int sum(int *const a, int *const b); //no
~~~

但是如果形参是某种类型的指针或引用，则通过区分其指向的是常量对象还是非常量对象可以实现函数重载（这时的const的是底层的）：

~~~C++
int sum(int &a, int &b);
int sum(const int &a, const int &b);  //作用于常量引用

int sum(int *a, int *b);
int sum(const int *a, const int *b);  //作用于指向常量的指针
~~~

---

## 3.调用重载函数

**函数匹配(function matching)**是指编译器把调用重载函数与一组重载函数中的某一个关联起来，函数匹配也称为**重载确定**或**重载决策(overload resolution)**

调用重载函数可能会出现三种结果：

+ **最佳匹配(best match)**：编译器找到一个与实参最佳匹配的函数，并生成调用该函数的代码

+ **无匹配(no match)**：编译器找不到任何一个与实参匹配的函数，此时编译器会发出no match的错误信息

+ **二义性调用(ambiguous call)**：编译器找到多个函数可以与实参匹配，但都不是最佳匹配，此时编译器会发出

  ​												  **error: call of overloaded 'XXX' is ambiguous** 的错误信息

几种常见的二义性调用情况：

+ **类型的转换导致的二义性**

  ~~~C++
  int sum(int a, int b) // 1
  {
      return a + b;
  } 
  double sum(double a, double b) // 2
  {
      return a + b;
  }
  
  sum(10, 10.5); //ambiguous call
  ~~~

+ **函数的默认参数导致的二义性**

  ~~~C++
  int sum(int a, int b, int c = 0)
  {
      return a + b + c;
  }
  int sum(int a, int b)
  {
      return a + b;
  }
  
  sum(1, 2); //ambiguous call
  ~~~

+ **传引用参数导致的二义性**

  ~~~C++
  int get(int n)
  {
      return n;
  }
  
  int get(int &refn)
  {
      return refn;
  }
  
  int m = 10;
  get(m); //ambiguous call
  ~~~

**C++ 是如何做到函数重载的**
C++代码在编译时会对函数名进行重命名，例如：

void swap(int a, int b)会被重命名为 \_swap_int_int
void swap(float x, float y)会被重命名为 \_swap_float_float 

不同的编译器有不同的重命名方式，这里仅仅举例说明，实际情况可能并非如此

**从这个角度讲，函数重载仅仅是语法层面的，本质上它们还是不同的函数，占用不同的内存，入口地址也不一样**

---

