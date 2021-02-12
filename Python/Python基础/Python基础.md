Table of Contents：
1. [基础语法](#基础语法)
   1. [文件编码](#文件编码)
   2. [标识符和关键字](#标识符和关键字)
      1. [标识符](#标识符)
      2. [关键字](#关键字)
   3. [注释](#注释)
      1. [单行注释](#单行注释)
      2. [多行注释](#多行注释)
   4. [行，语句与缩进](#行语句与缩进)
2. [模块简介](#模块简介)


# 基础语法

## 文件编码

默认情况下，python3源文件以UTF-8编码，所有的字符串都是unicode字符串。

你可以为源文件指定不同的编码：
```python
# -*- coding: UTF-8 -*-
```
或更简单的写法：
```python
# coding=UTF-8
```

## 标识符和关键字

### 标识符
标识符用于命名变量或函数。

python标识符命名规则：
- 第一个字符必须是字母表中字母`a-z`或下划线`_`，不能是数字`0-9`
- 标识符的其他部分由字母，数字和下划线组成
- 标识符对大小写敏感

在python3中，可以用中文作为变量名，非ASCII标识符也是允许的。

### 关键字

关键字（或保留字），我们不能将它们用作任何标识符名称。Python的标准库提供了一个keyword模块，可以输出当前版本的所有关键字。
<img src=image/2021-02-11_13-47.png>

## 注释

### 单行注释

Python中单行注释以`#`开头：
```python
#this is a comment
#this is another comment
```
<img src=image/2021-02-11_13-51.png>

### 多行注释

Python中多行注释可以用多行`#`，还有`'''`和`"""`：
```python
#comment1
#comment2

'''
coment1
coment2
coment3
'''

"""
comment1
comment2
comment3
"""
```

## 行，语句与缩进

python每条语句的末尾不需要加分号，一般每一行一条语句。

python中通常是一行写一条语句，但如果语句很长，我们可以使用`\`来将一条语句在多行书写：
```python
total = item_one + \
        item_two + \
        item_three
```
而在`()` `[]` `{}`中，不需要使用`\`：
```python
total = ['item_one', 'item_two', 
        'item_three']
```

python也可以在一行中写多条语句，这时语句之间需要用`;`分隔：
```python
print("clause1"); print("clause2")
```

python最有特色的就是**使用缩进来表示代码块**，不需要使用大括号`{}`。
注意到，缩进的空格数是可变的，但是**同一个代码块必须保证相同的缩进空格数**，否则会造成运行错误。

缩进相同的一组语句构成一个代码块，称为代码组。我们将首行及后面的代码称为一个子句。

**函数之间或类的方法之间，以及类和函数的入口之间，一般用空行分隔，表示一段新代码的开始**。空行并不是python语法的一部分，代码没有空行，解释器在运行时也不会出错。但是空行的作用在于分隔两段不同功能或含义的代码，便于日后代码的维护或重构。

# 模块简介

python使用`import`或`from...import`来导入相应模块。
python本身自带很多有用的标准库，你也可以安装一些第三方库，然后在你的程序中导入。

安装第三方库需要用到python模块包管理pip:
```
python3 install pip3
pip3 install <modulename> #你需要安装的模块
```

一些常用的python模块：
- numpy
- matplotlib
- pandas
- sklearn
- scrapy












