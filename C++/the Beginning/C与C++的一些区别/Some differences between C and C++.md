# Some differences between C and C++

---

## 1. Constants

In C++, unlike in C, a const identifier can be used anywhere a constant can appear.

~~~C++
const int size = 100;
double a[size];
// illegal in C but legal in C++
~~~

---

## 2. Declaring Variables

In a C function, variable declarations must occur at the beginning of a block.

In C++, variable declarations may occur anywhere in a block.

---

## 3. structures

struct need not be included as part of the variable declaration.

In C++, a struct can contain functions, but in C it is not allowed.

~~~C++
struct Point{
    double x;
    double y;
    
    void setVal(double, double); //set the value for x and y (not allowed in C)
}

Point p; //not allowed in C
// struct Point p
// or use typedef
p.x = 1.0;
p.y = 2.0;
p.setVal(4.11, 3.29);
~~~

