# Default Argument 默认实参or缺省值

---

## 1.默认参数的规则

- 默认值定义

C++支持函数参数带**默认参数(default argument)**

**默认参数**指的是**在调用函数时，可以不指定某些参数，编译器会自动把默认值传递到函数调用中**

- 默认值设置

默认值<u>可以在**函数声明**或**函数定义**中设置</u>，但要保证**<u>不出现参数重定义</u>**

+ 默认值位置

无论是设置一个还是多个默认参数，<u>**一旦某个参数被赋予了默认值，它后面的所有参数都必须有默认值**</u>

---

## 2.默认参数的设置和使用

---

### 2.1 默认参数的设置

- **在函数声明中设置默认值**

这是最常见的一种情形。主要有以下两种声明方式：

1. 声明中给参数赋默认值
2. 声明中用类型指定默认值

```C++
int sum1(int a = 1, int b = 2); // 在函数声明中给参数设置默认值（函数声明是全局的）
int sum2(int a, int b = 2);
int main()
{
  int s1 = sum1(); 	  // s1=3
  int s2 = sum2(3);   // s2=5

  return 0;
}


int get(int n);
{
    return n;
}
int main()
{
    int get(int n = 1);    // 在函数声明中给参数设置默认值（函数声明是局部的）
    
    int n1 = get();    // n1=1
    int n2 = get(3);   // n2=3
}
```

~~~C++
int sum1(int = 3, int = 5);  // 在函数声明中给类型指定默认值
int sum2(int, int = 5);
int main()
{
  int s1 = sum1();   // s1=8
  int s2 = sum2(1);  // s2=6

  return 0;
}
~~~

+ **在函数定义中设置默认值**

如果函数直接在调用前定义，此时不需要函数声明，则默认参数可以在函数定义中直接设置

```C++
int sum(int a = 1, int b = 2)  //在函数定义中设置
{
  return a + b;
}

int main()
{
  int s = sum(); 

  return 0;
}
```

---

### 2.2 默认参数的使用

**在调用含有默认参数的函数时，可以用实参覆盖默认值**

**但是如果要覆盖后面的默认实参，必须给前面的参数传递值，而不能跳过**

对于所有参数都带默认值的函数，可以不用给参数传递值

~~~C++
int sum1(int a = 1, int b = 2, int c = 3);
int sum2(int a, int b = 2, int c = 3);

sum1();  	   //result:6
sum2(10);      //result:15
sum2(10,5);    //result:18
sum2(8,9,6);   //result:23

sum1(,3,4);    //error
//要覆盖后面的默认实参，必须给前面的参数也提供值
~~~

---

## 3.注意事项

+ **不要重复设置默认值**：在函数声明时设置了默认值之后，在函数定义中不需要再设置，否则会报错

~~~C++
int sum(int a = 1, int b = 2);

int main()
{
    sum();
}
 
int sum(int a = 1, int b = 2)  // error
{
    return a + b;
}
~~~

- **默认值与函数重载**：函数默认值不能和函数重载形成二义性，否则编译器无法判断具体使用的是那个函数

```C++
float func1(float r1, float r2 = 5.0);
float func1(float r);

float func1(float r)
{
  return r * r * 3.14;
}

float func1(float r1, float r2)
{
  return r1 * r1 * 3.14;
}

int main()
{
  float s2 = func1(6.0);  //ambiguous call

  return 0;
}
```

- **默认值的类型**：**<u>局部变量不能作为默认实参</u>，除此之外，只要表达式的类型能转换成形参的类型，该表达式就能作						为默认实参**

  原因是函数参数默认值是在编译时确定的，而局部变量存在栈上，编译时不能确定

```C++
int a = 100;

int f1(int n)
{
    // code
}
int get(int n)
{
    return n;
}


int main()
{
  int f1(int n = a); //全局变量做默认值
  int f1(int n = get(2)); //函数表达式做默认值
    
  int val = 1;
  int f1(int n = val); //局部变量做默认值，编译不通过

  return 0;
}
```

+ **默认值可以添加**：可以多次声明同一个函数，但**后续声明只能给之前那些没有默认值的形参添加默认实参，而且							该形参的右侧的所有形参都必须有默认值**

  注意：**<u>不能修改一个已有的默认实参</u>**，这相当于犯参数重定义的错误

~~~C++
string func1(int n, double f, char c);
string func2(int n, double f, char c = 'A');

int main()
{
    string func1(int n, double f, char c = 'B');  //给形参c添加默认实参'B'
    string func2(int n, double f, char c = '*');  //错误：重定义
    string func1(int n, double f = 4.1, char c);  //错误：其后形参还必须有默认值
}
~~~

那么如何修改默认实参的值呢？可以这么做：

~~~C++
char c = '#';
string func(int = 100, char = c);

{
    c = '*';  //改变了c的值
	func();  //调用 func(100, '*')
}
~~~

