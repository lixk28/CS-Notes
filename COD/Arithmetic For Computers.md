# Arithmetic For Computers

[toc]

## 1. Addition and Subtraction

+ 加法：当两个相加的源操作数符号相异时，一定不会溢出，原因是和必然不会大于其中一个操作数
+ 减法：当两个相减的源操作数符号相同时，一定不会溢出，原因是可以将减法作成加法，同上

---

加减法溢出的检测：

+ 加法：如果两个正数相加结果却为负，或者两个负数相加结果却为正，说明发生了溢出（这也说明了计算过程中发生了向符号位的进位操作）
+ 减法：如果用一个正数减去一个负数得到一个负的结果，或者用一个负数减去一个正数得到一个正的结果，说明发生了溢出（这说明计算过程中借位占用了符号位）

<img src="E:\image\image-20201022213426167.png" alt="image-20201022213426167" style="zoom:60%;" />

**溢出(Overflow)**可以用以下方法检测：

输入到最高位的进位 != 从最高位输出的进位

Carry into MSB ! = Carry out of MSB (use a XOR Gate)



下溢：运算结果小于能表示的最小的数

上溢：运算结果大于能表示的最大的数



---

## 2. Multiplication

加法中第一个源操作数称为**被乘数(multiplicand)**，第二个源操作数称为**乘数(multiplier)**，最终的结果称为**积(product)**

如果忽略符号位，积的位数是被乘数和乘数位数之和，m位 x n位 = m + n 位

二进制使得乘法更容易实现：

+ 0 x 被乘数 = 0
+ 1 x 被乘数 = 被乘数

---

First version of the multiplication hardware:

<img src="E:\image\image-20201022220657078.png" alt="image-20201022220657078" style="zoom: 50%;" />

Refined version of the multiplication hardware:

<img src="E:\image\image-20201022221016549.png" alt="image-20201022221016549" style="zoom: 50%;" />

---

## 3. Division

除法中第一个源操作数称为**被除数(dividend)**，第二个源操作数称为**除数(divisor)**，运算的第一结果称为**商(quotient)**，第二结果称为**余数(remainder)**，余数要小于除数

被除数 = 商 x 除数 + 余数





