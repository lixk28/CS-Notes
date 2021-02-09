# 命名空间简介和命名空间的using声明

---

## 1.命名空间简介

~~~C++
std::cin >> a >> b;
std::cout << a + b << std::endl;
~~~

这个程序段中使用的是std::cin、std::cout和std::endl而不是cin、cout、endl

前缀指出cin、cout、endl是定义在名为 **std** 的 **命名空间(namespace)** 中的

**::** 是**作用域运算符（域解析运算符）**

命名空间的存在可以避免不经意的名字定义冲突，以及使用库中相同名字导致的冲突，标准库定义的所有名字都在命名空间std中

但是命名空间的副作用是：当使用标准库中的一个名字时，**必须显式地写出我们要使用的名字来自的命名空间，即要写namespace:: 的前缀**

~~~C
#include <iostream>
int main()
{
    cout << "I am Groot" << endl; //报错
    return 0;
}
~~~

**解释**：经预处理器处理后，上面的代码扩展为

~~~C++
namespace std
{
    istream cin;
    ostream cout;
} 
// std是一个语句块，所以其外不能直接是用cin和cout
// 所以需要using语句解决这个问题

int main()
{
    cout << "I am Groot" << endl; 
    return 0;
}
~~~

---

## 2. 命名空间的using声明

使用 **using声明**(using declaration) 可以无需专门的前缀也能使用所需的名字

**using声明的一般形式为：**

~~~C++
using namespace::name;
~~~

一旦声明了上述语句，就可以直接访问命名空间中的名字

**三种使用命名空间中标识符的方法：**

1. use a qualified name consisting of the namespace, the scope resolution operator :: and the desired the identifier

   ~~~C++
   std::cin >> a;
   std::cout << "I am Grott" << std::endl;
   ~~~

2. write a using declaration

   ~~~C++
   using std::cin;
   using std::cout;
   using std::endl;
   
   cin >> a;
   cout << "I am Groot" << endl;
   ~~~

3. write a using directive locally or globally

   ~~~C++
   using namespace std;
   cin >> a;
   cout << "I am Groot" << endl;
   ~~~

可以自定义命名空间，例如：

~~~C++
namespace my_namespace
{
    int inflag;
    void foo(int n);
}
~~~

同样的，若没有对命名空间using声明，在使用该命名空间中的名字（成员）时，仍然必须写出前缀

~~~C++
using my_namespace::inflag;
inflag = 100; //正确
foo(8); //报错
my_namespcae::foo(8); //正确
~~~

~~~C++
using namespace my_namespace;
inflag = 100; //正确
foo(8); //正确
~~~

---

**注意**：**头文件不应包含using声明**

头文件内的代码一般来说不应该使用using声明

因为头文件会被其他文件使用，头文件的内容会被拷贝到引用它的文件中去，如果头文件中有某个using声明，那么每个使用了该头文件的文件就会都有这个声明

这样可能头文件中的一些名字可能会与程序中的名字冲突

---

## 3. 域解析运算符简介

**::** 称为 **作用域运算符** 或 **域解析运算符(scope resolution operator)**

对于作用域的嵌套，我们知道最内层语句块的变量会屏蔽外层的同名变量，外层的同名变量会被隐藏

**但是使用域解析运算符可以引用被隐藏的 <u>全局</u>变量**，但是，**没有方法可以引用被隐藏的 <u>局部</u>变量**

使用域解析运算符引用被隐藏的全局变量的一般形式为 **::global variable name**，即在该变量名前加上域解析运算符即可

~~~C
int x;
void foo()
{
    int x = 1; // hide global x
    ::x = 2; // assign to global x
    x = 2; // assign to local x
}
~~~

