# **Class and Object(类和对象)**

---

**数据抽象(data abstraction)**是一种依赖**接口(interface)**和**实现(implementation)**分离的编程设计技术。

接口包括用户所能执行的操作；实现包括数据成员、负责接口实现的函数体等。

**封装(encapsulation)**是接口和实现的分离，封装的作用是隐藏实现部分，用户只能使用接口而不能访问实现部分。

**抽象数据类型(abstract data type)**是由程序员定义的实现数据抽象和封装的数据类型。（简称**ADT**）

在抽象数据类型中，程序员负责类的实现，用户只需要使用接口。

> 程序员们常把运行和使用其程序的人称为**用户(user)**。

---

## 1. 类的声明和定义

---

C++中使用关键字 **class** 来定义类，基本形式为：

~~~C++
class 类名
{
    private:
    	//私有成员（只允许类内成员函数访问，而类外函数不能访问）
    public:
    	//公有成员（类的外部接口）
    protected:
    	//保护成员（类似于private，差别表现在继承与派生时）
}; //注意分号
~~~

+ **类名**：遵循一般的命名规则，以字母、数字和下划线组合，不能以数字开头

+ **类成员**：类可以定义多个成员，也可以没有成员。没有成员的类是空类，但空类也占用空间

  ​			**成员可以是 <u>*数据*</u> 、*<u>函数</u>* 或 *<u>类型别名</u>*** ，**所有的成员都必须在类的内部声明**，但**<u>成员函数体可以定义在类内也			可以定义在类外</u>**

+ **构造函数**：构造函数是一个或多个特殊的成员函数，其作用是**初始化类对象的数据成员**

  ​				构造函数的特点：(1)**构造函数的函数名与类名相同**

  ​											 (2)**构造函数没有返回类型**

  ​											 (3)**构造函数的参数列表可能为空，函数体也可能为空**

  ​											 (4)**构造函数不能被声明成 const 的**

+ **成员函数**：**成员函数必须在类的内部声明，可以在类内部定义，也可以在类外部定义**

  ​				  如果成员函数在类内部定义，就**默认为内联函数**

+ **访问说明符(access specifiers)**：在C++中，访问说明符用于加强类的封装性

   	**public**：定义在public说明符后的成员在整个程序内可被访问，**public成员定义类的接口**

    **private**：定义在private说明符后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，**private封                  					装类的实现细节**

  一个类可以包含0个或多个访问说明符，而且对于某个访问说明符能出现的次数也没有严格限定

  每个访问说明符指定了接下来的成员的访问级别，其**有效范围直到出现下一个访问说明符或者到达类的结尾为止**

> 类的定义也可以使用 struct 关键字
>
> **struct 和 class 关键字定义类的唯一区别就是默认的访问权限**
>
> **对于 struct 关键字，定义在第一个访问说明符之前的成员都默认是 public 的**
>
> **对于 class 关键字，定义在第一个访问说明符之前的成员都默认是 private 的**

下面是定义简单的类的例子：

~~~C++
class Date //定义一个Date类
{
    private:
    	int year;  //年
    	int month; //月
    	int day;   //日
    public:
    	void setDate(int year, int month, int day);  //设置日期
    	int getYear() const;  //获得年
    	int getMonth() const; //获得月
    	int getDay() const;   //获得日
    	void print() const;   //打印日期
    	void increment();	  //增加日期
    	void decrement();	  //减少日期
};
~~~

~~~C++
class Point //定义一个Point类
{
    private:
    	double x;  //坐标x
    	double y;  //坐标y
    public:
    	void setPos(double x, double y);  //设置坐标
    	double distance(Point b);  //获得距离
    	void print(); //打印坐标
};
~~~

**注意**：在创建类的对象之前，必须完整的定义该类，而不只是声明类

​		   所以，**类不能具有自身类型的数据成员，但可以包含指向本类的指针或引用**

~~~C++
class foo
{
    private:
    	foo a;   //不可以！
    	foo *b;  //可以
    	foo &c;  //可以
};
~~~

可使用类型别名来增强类的可读性：

~~~C++
class People
{
    private:
    	typedef std::string people_name;
    	typedef int people_age;
    	
    	people_name name;
    	people_age age;
    public:
    	//
};
~~~

---

## 2. 类的成员函数

---

### 2.1 成员函数的定义

**所有的成员（数据成员、函数成员、类型别名成员）都必须在类的内部声明，但是成员函数体可以定义在类内，也可以定义在类外**

**如果成员函数定义在类内，默认为内联函数**

可以在类内实现成员函数体的定义：

~~~C++
class Box
{
    private:
    	double length;
    	double width;
    	double height;
   	public:
    	double getVolume()
        {
            return length * width * height;
        }
};
~~~

也可以类的外部实现成员函数体的定义，但是**<u>在类外定义成员函数必须要使用域解析运算符::</u>**，来**表明类作用域内的函数、返回类型、参数**，::前使用的是类名

~~~C++
class Box
{
    private:
    	double length;
    	double width;
    	double height;
   	public:
    	double getVolume();
};

double Box::getVolume()
{
    return length * width * height;
}
~~~

**有时候会在类内定义类型别名，这时类型别名也是类内成员，需要使用域解析运算符**

~~~C++
class My_Class
{
    private:
    	typedef int data_type;
    	data_type data;
    public:
    	data_type getData();
};

My_Class::data_type My_Class::getData()
{
    return data;
}
~~~

---

### 2.2 成员函数的调用

**成员函数的调用非常简单，只要使用 成员运算符 . 就可以了**

一般形式为：

~~~C++
类的对象.成员函数名(参数列表);
~~~

例如对上面的 Date 类，调用其中的 print 成员函数：

~~~C++
Date birthday;
birthday.print(); //注意括号不要丢
~~~

---

### 2.3 this 指针

考虑一个问题：当我们在调用成员函数时，实际上是在替类的某个对象在调用它，那么我们是通过什么来访问这个对象里						面的成员呢？

**隐含的 this 指针**： **<u>所有的成员函数都具有一个额外的隐式形参 this 指针</u>**，它由编译器隐含地定义

​							 **当我们调用一个成员函数时，编译器<u>用请求调用该函数的对象的地址初始化 this</u>**

​							 **成员函数的函数体可以显式使用 this 指针**，在成员函数内部，this 指向调用成员函数的对象

（**友元函数没有 this 指针**，因为友元函数不是类的成员，只有成员函数才有 this 指针）		

~~~C++
class My_Class
{
    private:
    	int data;
    public:
    	int getData();
};
~~~

对上面定义的类，如果我们调用：

~~~C++
x.getData(); //x是My_Class类的一个对象 
~~~

我们可以等价地认为编译器将该调用重写成了如下的形式：

~~~C++
My_Class::getData(&x); 
//调用时传入了对象x的地址
~~~

由于 this 总是指向调用成员函数的对象，所以 **this 默认是一个<u>指向非常量的常量指针</u>**，<u>**我们不允许修改 this 的值**</u>

进一步地，我们可以认为编译器将成员函数转换成下面的形式：

~~~C++
My_Class::getData(My_Class * const this) //在调用时把对象的地址传给this指针
{
    return this->data;
}
~~~

**任何自定义名为 this 的参数或变量的行为都是非法的**	

---

**在成员函数内部，我们<u>可以直接使用和调用该函数对象的成员</u>，而无须通过成员访问运算符**

**this 所指的正是这个对象，<u>任何对类成员的直接访问都被看作 this 的隐式引用</u>**

当然，**我们也可以显式地引用 this 指针**，这样也是合法的

~~~C++
int My_Class::getData()
{
    return Data; 
    //相当于 return this->Data;
    //或直接写成这样也是可以的
}
~~~

---

我们需要将调用成员函数的对象作为整体访问而不是访问对象的一个成员

**最常见的情况是在这样的函数中使用 this：返回 this 对象的成员函数**

~~~C++
class Complex //复数类
{
    private:
    	int r; //实部
    	int i; //虚部
    public:
    	Complex sum(const Complex& other)
        {
            r = r + other.r;
            i = i + other.i;
            return *this; //返回调用该函数的对象
       	}
    	//为什么不声明一个该类的对象，再把数据存进这个对象中，然后返回这个对象？
};
~~~

---

### 2.4 const 成员函数

前面说过，默认情况下 this 是指向非常量的常量指针，这意味着 this 不能指向一个常量对象（this指向的类型是非const，而常量对象是const）

那么我们就不能在一个常量对象上调用普通成员函数，因为常量对象的地址不能传给 this，所以我们需要将 this 设置为指向常量的指针

然而，this 是由编译器隐式定义的且不会出现在参数列表中，所以在哪里将 this 声明成指向常量的指针是面临的问题

**C++的做法是：允许把 const 关键字放在成员函数的参数列表之后，此时，紧跟在参数列表后面的 const 表示 this 是						一个指向常量的指针**

用 const 将 this 指针设置为指向常量的指针的成员函数称为**常量成员函数(const member function)**

**常量成员函数不能改变调用它的对象的内容**

~~~C++
int My_Class::getData() const  //const表示this指向的对象不能被改变
{
    return data;
}
~~~

**常量对象、常量对象的引用或指针都只能调用常量成员函数**

---

## 3. 类的作用域

类本身就是一个作用域，类的成员嵌套在类的作用域之内

编译器分两步处理类：**首先编译成员的声明，然后才轮到成员函数体**，因此成员函数体可以随意使用类中的其他成员而无须在意这些成员出现的次序

类的作用域包括：类的内部（花括号之内）

​							定义在类外部的成员函数的参数表(小括号之内)

​							函数体（花括号之内）

注意在类外部定义成员函数时，函数的返回类型是不是类内定义的，如果是则必须包含其所属的类名