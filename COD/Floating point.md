科学计数法：十进制小数点左边只有一位整数的计数法

**规格化(normalized)**数：没有前导零且小数点左边只有一位整数的浮点计数法

---

浮点数表示

![image-20201016105354421](E:\.workspace\Note\Images for Note\image-20201016105354421.png)

MIPS中的浮点数表示：

+ s 为浮点数的符号（0表示正数、1表示负数）
+ 指数域为 8 位宽（包含指数的符号位）
+ 尾数域为 23 位宽

---

IEEE 754 浮点数编码：

![image-20201016105859393](E:\.workspace\Note\Images for Note\image-20201016105859393.png)

NaN(Not a Number)表示无效的操作结果

---

Floating point addition

1. Alignment（对阶）：使两数的指数相等，即对齐小数点，原则是小指数向大指数看齐
2. Addition of significands：尾数相加减
3. Normalisation of the result：对结果进行规格化
4. Rounding：舍入处理
5. Whether overflow/underflow：检查是否溢出

---

+ **Guard Digits(保护位)**：在浮点数中间计算中，在尾数中右边多保留两位，第一位为保护位，第二位为舍入位

+ **Round Digits(舍入位)**：规格化后有效尾数大小的右边还 有一些非零数字，这个数据就需要舍入。一个舍入数字必须被进位到保护位的右边，因而在规格化左 移之后，根据舍入位的数值，可以对该结果进行舍入处理。

+ **Sticky Bit(粘贴位)**：为进一步改进舍入处理的结果，在舍入数字右边的附加位。 为了更高的准确性，当舍入数字为 B/2 时，需要一个粘位， 即如果有在舍入数字的尾部有任何1位丢失，则置为1。



四舍五入方法中的偶数法则：标准的方法是 **四舍六入,五看奇偶**。如果是5 的话，就看5后面还有没有数，有数就入，如果5后面都是0了，则看前面一 位，是偶数就舍，是奇数就入。

---

Parallelism and Computer Arithmetic: Associativity

