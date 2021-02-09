# Instruction1 指令1

[toc]

---

The words of a computer’s language are called **instructions**, and its vocabulary is called an **instruction set**

计算机语言中的基本单词称为**指令**，一台计算机的全部之灵称为该计算机的**指令集**

**Instruction Set（指令集）：**The vocabulary of commands understood by a given architecture.

​													一个给定的计算机体系结构所包含的指令集合

---

## 1. MIPS ISA MIPS 指令集

MIPS Operands（MIPS 操作数）

![MIS Operands](E:\image\MIS Operands.png)

MIS Assembly Language（MIPS汇编语言）

![MIPS Assembly Language](E:\image\MIPS Assembly Language.png)

---

## 2. MIPS Operands MIPS 操作数

Assembly Variables: Registers 

Unlike programs in high-level languages, the operands of arithmetic instructions are restricted; they must be from a limited number of special locations built directly in hardware called **<u>registers</u>**. 与高级程序语言不同，MIPS算术运算指令的操作数是很严格的，<u>*它们必须来自于寄存器，寄存器由硬件直接构建且数量有限*</u>。

Assembly operands are objects called **<u>resgisters</u>**, operations can only be performed on these 汇编语言的操作数/变量是寄存器，汇编语言的操作和指令都是在寄存器上进行的！

One major difference between the variables of a programming language and registers is the limited number of registers, typically 32 on current computers, like MIPS. 高级语言的变量与寄存器的一个主要区别在于寄存器的数量有限，MIS一类的典型的现代计算机中有32个寄存器。

Since registers are directly in hardware, they are very fast! 由于寄存器就是硬件构建的，所以它们非常快

---

位、字节、字：

+ **位（bit）**：数据存储的最小单位。在计算机中的二进制数系统中，位也称为比特，每个0或1就是一个(bit)。计算机中的CPU位数指的是CPU一次能处理的最大位数。例如32位计算机的CPU一个机器周期内可以处理32位二进制数据的计算机。

+ **字节（byte）**：8个二进制数即8位为一个字节

+ **字（word）**：自然的存储单位。通常一个字分为若干个字节。在MIPS体系结构中4个字节是一个字。在计算机中，一串数码作为一个整体来处理或运算的，称为一个计算机字，简称字。在存储器中，通常每个单元存储一个字，因此每个字都是可以寻址的。字的长度用位数来表示。在计算机的运算器、控制器中，通常都是以字为单位进行传送的。字出现在不同的地址其含义是不相同。例如，送往控制器去的字是指令，而送往运算器去的字就是一个数。

---

1字节（byte）= 8位（bit）
在16位系统中，1字（word）= 2字节（byte）= 16位（bit）
在32位系统中，1字（word）= 4字节（byte）= 32位（bit）
在64位系统中，1字（word）= 8字节（byte）= 64位（bit）

---

### 2.1 Register Operands 寄存器操作数 

![MIS Register (1)](E:\image\MIS Register (1).png)

![MIS Register (2)](E:\image\MIS Register (2).png)

+ Number of MIPS Register

  MIPS has 32 registers, each MIPS register is 32 bit wide, Groups of 32 bits called a word in MIPS ISA.

  **MIPS ISA 中一共有 32 个寄存器，每一个寄存器大小都是 32 位（1 字）**

+ Names of MIPS Register

  + Registers are numbered from 0 to 31   可以用序号 0 到 31 表示相应的寄存器

    Number references：\$0，\$1，\$2，……，\$30，\$31

  + Registers are given special names   可以用特殊的名称来表示相应的寄存器

    Name references：\$8 - \$15 -> \$t0 - \$t7 (can hold temporary variables)

    ​								   \$16 - \$23 -> \$s0 - \$s7 (can hold things like C variables)

  + Each register can be referred to by number or name   每个寄存器都可以通过序号或名称来引用

    Generally, use names to make your code more readable 通常，都是通过名称使用寄存器来增强你的代码可读性

---

Operands of arithmetic instructions must be from a limited number of special locations contained in the datapath’s register file

**<u>MIPS的算术运算指令只对寄存器进行操作</u>**

<img src="E:\image\MIPS Register File.png" alt="MIPS Register File" style="zoom:50%;" />

---

Examples:

~~~C
f = (g + h) - (i + j); //C赋值语句
~~~

将变量 f、g、h、i、j 分别分配给寄存器 \$s0、\$s1、\$s2、\$s3、\$s4，编译后的MIPS代码是什么？

~~~shell
add $t0, $s1, $s2 #register $t0 contains g + h
add $t1, $s3, $s4 #register $t1 contains i + j
sub $s0, $t0, $t1 #f gets $t0 - $t1
~~~

上述代码中，# 右边的是注释，注释总是在一行的末尾结束，即不允许多行注释

注意与其他语言不同的是，这种语言的每一行最多只有一条指令

将C语言程序转换成MIPS汇编指令是由*编译器*完成的

---

### 2.2 Memory Operands 存储器操作数 

Programming languages have simple variables that contain single data elements, but they also have more complex data structures like arrays and structures. 编程语言中有金汉一个数据元素的简单变量，也有像数组或结构那样的复杂数据结构。

The processor can keep only a small amount of data in registers, but computer memory contains billions of data elements. Hence, data structures (arrays and structures) are kept in memory. 处理器只能将少量数据保存在寄存器中，但存储器有数十亿的数据元素。因此，数据结构（如数组和结构）是存放在存储器中的。

MIPS的算术运算指令只对寄存器进行操作，因此MIPS必须包含在存储器和寄存器之间传送数据的指令，这些指令称为数据传送指令，而为了访问存储器中的一个字，指令必须给出存储器地址。

**数据传送指令（data transfer instruction)**：A command that moves data between memory and registers.

​																				在存储器和寄存器之间移动数据的命令

**地址（address）**：A value used to delineate the location of a specifi c data element within a memory array.

​								  用于在存储器空间中指明某特定数据元素位置的值

***Memory is a large, single-dimensional array, with the address acting as the index to that array, starting at 0.*** 

***存储器就是一个很大的下标从 0 开始的一维数组，地址就相当于数组的下标***



Processor is the memory interconnections.

<img src="E:\.workspace\Note\COD\Images\Processor.png" alt="Processor" style="zoom: 50%;" />



<img src="E:\.workspace\Note\COD\Images\MIPS Organization.png" alt="MIPS Organization" style="zoom: 50%;" />

Since 8-bit bytes are useful in many programs, virtually all architectures today address individual bytes. 

很多程序都用到8比特的字节类型，且大多数体系结构按字节编址。

> 按字节编制就是指一个字节分配一个地址

Therefore, the address of a word matches the address of one of the 4 bytes within the word, and addresses of sequential words differ by 4. 

因此，一个字的地址必和它所包括的4字节中的某个地址相匹配，且连续字的地址相差4.

In MIPS, words must start at addresses that are multiples of 4. This requirement is called an alignment restriction, and many architectures have it. 

**因为MIPS是按字节编址的，所以字的起始地址必须是4的倍数**。很多体系结构都有这种限制，这被称为**对齐限制（alignment restriction)**

Computers divide into those that use the address of the left most or “big end” byte as the word address versus those that use the rightmost or “little end” byte. MIPS is in the big-endian camp. 

有两种类型的字节寻址的计算机：

+ **大端编址（big-endian）**：用最左边或大端（big end）字节的地址作为字地址

+ **小端编址（little-endian）**：用最右边或小端（little end）字节的地址作为字地址

MIPS采用的是大端编址

Since the order matters only if you access the identical data both as a word and as four bytes, few need to be aware of the endianess. 

由于使用相同的地址去访问一个字和4个字节时，端才起作用，因此大多数情况下不用关注这个问题

***Byte addressing also affects the array index.***   ***字节寻址也影响到数组下标***



The operands of **<u>*all*</u>** ALU instructions are registers. 

This means to operate on a variables in memory you must:

1. Load the value/values from memory into a register   从内存中取数到寄存器中
2. Perform the instruction   执行指令
3. Store the result back into memory   将运算结果存到存储器中

Going to and from memory can be expensive (4x or 20x slower than operating on a register), so keep variables in registers as much as possible!

---

Examples:

~~~C
g = h + A[8];
~~~

A是一个含有100个字的数组，变量 g 和 h 分别分配给寄存器 \$s0 和 \$s1，数组A的起始地址存放在寄存器 $s3 中，编译后的MIPS代码为：

~~~SHELL
lw $t0, 32($s3) #注意是32！
add $s0, $s1, $t0
~~~

上面写的是 32 的原因是MIPS是按字节寻址，8代表8x4个字节

> + 数组A的起始地址称为**基址（base address）**
>
> + 数据传送指令中的常量称为**偏移量（offset）**
>
> + 存放基址的寄存器称为**基址寄存器（base register）**

---

~~~C
A[12] = h + A[8];
~~~

变量 h 存放在寄存器 \$s2 中，数组A的基址存放在​ \$s3 中，编译后的MIPS代码为：

~~~shell
lw $t0, 32($s3)   #temporary reg $t0 gets A[8]
add $t0, $s2, $t0 #temporary reg $t0 gets h + A[8]
sw $t0, 48($s3)   #store h + A[8] back into A[12]
~~~

---

### 2.3 Constant or Immediate Operands 常数或立即数操作数 

程序中经常会在某个操作中使用到常数，但从已介绍的指令来看，如果要使用常数必须将其从存储器中取出。

避免使用取数指令的另一个方法是，提供其中一个操作数是常数的算术运算指令。

有一个常数操作数的快速加法指令叫作加立即数（add immediate），或者写成 addi。

Constant operands occur frequently, and by including constants inside arithmetic instructions, operations are much faster and use less energy than if constants were loaded from memory.

常数操作数出现频率高，而且相对于从存储器中取常数，包含常数的算术运算指令执行速度快很多，并且能耗低。

The constant zero has another role, which is to simplify the instruction set by off ering useful variations. For example, the move operation is just an add instruction where one operand is zero. Hence, MIPS dedicates a register $zero to be hard-wired to the value zero. (As you might expect, it is register number 0) 

常数0还有另外的作用，有效使用它可以简化指令集。例如，数据传送指令可以被视作一个操作数为0的加法。因此，MIPS将寄存器$zero恒置为0（此寄存器编号也是0）。

---

## 3. MIPS Fields MIPS 字段

There are three basic instruction formats:

+ R-type：3 register operands（2 source register, 1 destination register)
+ I-type：2 register operands（16 bit constant or offset）
+ J-type：no register operands（26 bit constant）

---

### 3.1 R-type/R-format R型

**R-type/R-format MIPS Instruction（R型指令）**：

<img src="E:\.workspace\Note\COD\Images\MIPS R-type Fields.png" alt="MIPS R-type Fields" style="zoom: 50%;" />

R型 MIPS 指令是用于寄存器的（for register）

MIPS R型指令的各字段名称及含义：

+ ***op***： Basic operation of the instruction, traditionally called the **<u>*op*</u>code**. 指令的基本操作，通常称为操作码

+ ***rs***：The first **<u>*r*</u>**egister **<u>*s*</u>**ource operand.   第一个源操作数寄存器（移位指令中不使用，恒置为0）

+ ***rt***：The second register source operand.   第二个源操作数寄存器

+ ***rd***：The **<u>*r*</u>**egister **<u>*d*</u>**estination operand. It gets the result of the operation. 用于存放操作结果的目的寄存器

+ ***shamt***：**<u>Sh</u>**ift **<u>am</u>**ou**<u>n</u>**t.（This field is set to 0 in all but the shift instructions）位移量（除了移位指令，其他指令都不使用该字段，故此字段内容为0

+ ***funct***：**<u>Funct</u>**ion. This field, often called the **function code**, selects the specifi c variant of the operation in the op field.  功能，一般称为功能码，用于指明 op 字段中操作的特定变式

---

### 3.2 I-type/I-format I型操作码

**I-type/I-format MIPS Instruction（I型指令）**：

<img src="E:\.workspace\Note\COD\Images\MIPS I-type Fields.png" alt="MIPS I-type Fields" style="zoom:50%;" />

I 型 MIPS 指令是用于立即数的和数据传送的（for immediate）

MIPS I型指令的各字段名称及含义：

+ ***op***：Basic operation of the instruction, traditionally called the opcode.  指令的基本操作，通常称为操作码

+ ***rs***：The register which stores the base address or the first operand.  基址寄存器或第一个源操作数寄存器

+ ***rt***：The register which stores the result, called **<u>*t*</u>**arget **<u>*r*</u>**egister.  存储基址加上偏移量的结果或立即数运算的结果的寄存器

+ ***constant or address***：The field stores immediate or address.  存储立即数或偏移量的字段

---

### 3.3 J-type/J-format J型

**J-type/J-format MIPS Instruction（J型指令）**：

<img src="E:\.workspace\Note\COD\Images\MIPS J-type Fields.png" style="zoom:67%;" />

J 型指令是跳转指令

MIPS J型指令的各字段名称及含义：

+ ***op***：Basic operation of the instruction, traditionally called the opcode.   指令的基本操作，通常称为操作码

+ **address**：Store the address.   存放将要跳转到的指令的地址

  **(地址要保证为4的倍数，所以最后两位一定为0，26位相当于28位)**

---

虽然多种指令会使硬件变得复杂，但是保持指令格式的类似性可以降低复杂度。

+ R 型和 I 型格式的前三个字段长度相等，并且名称也一样，都是 op、rs、rt

+ I 型格式的第四个字段 constant or address 和 R 型后三个字段 rd、shamt、funct 长度之和相等

***计算机硬件是根据指令的第一个字段 opcode 的值来区分指令的类型的***，每种格式的指令的第一个字段有不同的值区间，一以便让计算机直到指令后半部分是三字段（R型）还是一字段（I型）

---

目前已使用过得MIPS指令的各个字段的值：

![](E:\image\t1.png)

n.a. 表示 not applicable，表示该字段在该指令格式中不出现

add 和 sub 具有相同的操作码，硬件根据 funct 字段的值来决定进行的操作

---

Example:

~~~C
A[300] = h + A[300];
~~~

数组 A 的基址存放在 $t1 中，h 存放在 \$s2 中，编译后的MIPS代码为：

~~~shell
lw $t0, 1200($t1)   # temporary reg $t0 gets A[300]
add $t0, $s2, $t0   # temporary reg $t0 gets h + A[300]
sw $t0, 1200($t1)   # stores h + A[300] back into A[300]
~~~

这三条MIPS指令的机器语言代码为：

~~~shell
lw $t0, 1200($t1):

100011   01001   01000   0000 0100 1001 1000
op       rs      rt      address(offset)

# lw的opcode是35
# rs是$t1，编号为9
# rt是$t0，编号为8
# address是偏移量1200
~~~

~~~shell
add $t0, $s2, $t0:

000000   10010   01000   01000   00000   100000
op       rs      rt      rd      shamt   funct

# add的opcode是0
# rs是$s2，编号为12
# rt是$t0，编号为8
# rd是$t0，编号为8
# shamt不使用，为0
# add的opcode是32
~~~

~~~shell
sw $t0, 1200($t1):

101011   01001   01000   0000 0100 1001 1000
op       rs      rt      address(offset)

# sw的opcode是35
# rs是$t1，编号为9
# rt是$t0，编号为8
# address是偏移量1200
~~~

---

## 4. Stored Program 存储程序

Today’s computers are built on two key principles:

+ Instructions are represented as numbers   指令用数的形式表示
+ Programs are stored in memory to be read or written, just like data  和数据一样，程序存储在存储器中并且可以读写

<img src="E:\.workspace\Note\COD\Images\Stored Progarm.png" style="zoom: 67%;" />

**Stored Program（存储程序）**：The switch happens simply by loading memory with programs and data and then telling the computer to begin executing at a given location in memory. Treating instructions in the same way as data greatly simplifies both the memory hardware and the software of computer systems. Specifically, the memory technology needed for data can also be used for programs, such as compilers.

---

## 5. Arithmetic Operations 算数操作(待补充)



---

## 6. Logical Operations 逻辑操作

**Logical Oprations** are used to simplify the packing and unpacking of bits into words.

逻辑操作是用于对字中的若干位进行打包或者拆包的操作。

C、Java和MIPS中的逻辑操作：

<img src="E:\.workspace\Note\COD\Images\Logical Operation1.png" style="zoom: 60%;" />

<img src="E:\.workspace\Note\COD\Images\Logical Operation2.png" style="zoom:80%;" />

**Attention:heavy_exclamation_mark：*<u>MIPS implements NOT using a NOR with one operand being zero</u>*.**

​						MIPS用一个操作数为 0 的 NOR 指令来实现 NOT 取反操作，因为 ~(a | 0) = ~a

---

### 6.1 Shift 移位

**Shift（移位）**：Move all the bits in a word to the left or right, filling the emptied bits with 0s.								  			                 将一个字里面的所有位都向左或向右移动，并在空出来的位上填充0

移位分为左移和右移，MIPS中的逻辑左移和逻辑右移指令为：

+ ***sll***：Shift left logically.   逻辑左移
+ ***srl***：Shift right logically.   逻辑右移

语法格式为：

~~~shell
sll $reg2, $reg1, c
# 表示将寄存器$reg1中的内容逻辑左移 c 位，结果存放在寄存器$reg2中
~~~

~~~shell
srl $reg2, $reg1, c
# 表示将寄存器$reg1中的内容逻辑右移 c 位，结果存放在寄存器$reg2中
~~~

Example:

$s0：0000 0000 0000 0000 0000 0000 0000 1001~2~ = 9~10~

~~~shell
sll $t2, $s0, 4
~~~

执行上面的操作后，结果为

$t2：0000 0000 0000 0000 0000 0000 1001 0000~2~ = 144~10~（ = 9 x 2^4^）

移位指令属于R型指令，shamt字段在移位指令中用于表示*位移量*，上面的指令对应的机器代码是：

~~~shell
000000   00000   10000   01010   00100   000000
op       rs      rt      rd      shamt   funct
~~~

指令sll的编码在op字段和funct字段都为0，rs字段不使用，被置为0

:o:逻辑左移还有额外的作用：***左移 i 位就相当于乘以 2^i^***，这与十进制数左移 i 位相当于乘以 10^i^ 类似

---

sll 和 srl 的第二个源操作数必须是常量，表示位移量，MIPS还提供了用寄存器存储的值表示位移量的移位指令：

+ ***sllv***：Shift left logically variable. 
+ ***srlv***：Shift right logically variable. 

语法格式为：

~~~shell
sllv $reg3, $reg1, $reg2
# 表示将$reg1中的内容逻辑左移$reg2存储的值个位，结果存放在$reg3中
~~~

~~~shell
srlv $reg3, $reg1, $reg2
# 表示将$reg1中的内容逻辑右移$reg2存储的值个位，结果存放在$reg3中
~~~

**<u>*The only difference*</u>**：Shift amount is not in instruction, but in a register.

---

### 6.2 AND/OR 按位与/按位或

+ ***and***：A logical bitby-bit operation with two operands that calculates a 1 only if there is a 1 in *<u>both</u>* operands.  **按位与**操作当且仅当两个操作位均为 1 时结果才为 1

+ ***or***：A logical bit-bybit operation with two operands that calculates a 1 if there is a 1 in <u>*either*</u> operand. **按位或**操作当且仅当两个操作位中任意一位为 1 时结果就为 1

语法格式为：

~~~shell
and $reg3, $reg1, $reg2
# 表示将$reg1和$reg2中的内容进行按位与操作，结果存放到$reg3中
~~~

~~~shell
or $reg3, $reg1, $reg2
# 表示将$reg1和$reg2中的内容进行按位或操作，结果存放到$reg3中
~~~

Example:

$t1：0000 0000 0000 0000 0011 1100 0000 0000

$t2：0000 0000 0000 0000 0000 1101 1100 0000

~~~shell
and $t3, $t1, $t2
or $t4, $t1, $t2
~~~

执行上面的操作后，结果为

$t3：0000 0000 0000 0000 0000 1100 0000 0000

$t4：0000 0000 0000 0000 0011 1101 1100 0000

:o:AND can apply a bit pattern to a set of bits to force 0s where there is a 0 in the bit pattern. Such a bit pattern in conjunction with AND is traditionally called a mask, since the mask “conceals” some bits.

AND提供了一种将源操作数中某些位置置为0的能力，前提是另一个操作数中的对应位为0，后一个操作数传统上被称为***掩码*(mask)**，寓意其可隐藏某些位。

---

MIPS也提供了立即数与和立即数或的指令：

+ ***andi***：
+ ***ori***：

---

### 6.3 NOT 按位取反

NOT：A logical bit-bybit operation with one operand that inverts the bits; that is, it replaces every 1 with a 0, and every 0 with a 1. 该操作仅有一个操作数，将1变成0，将0变成1,。

In keeping with the three-operand format, the designers of MIPS decided to include the instruction NOR (NOT OR) instead of NOT.  为了保持三操作数的格式，MIPS的设计者引入或非NOR（NOT OR）指令来取代NOT

A NOR 0  = NOT(A OR 0) = NOT (A)

+ ***nor***：A logical bit-by-bit operation with two operands that calculates the NOT of the OR of the two operands. That is, it calculates a 1 only if there is a 0 in both operands. 或非操作当且仅当两个操作数都为0时，结果才为1

语法格式为

~~~shell
nor $reg3, $reg1, $reg2
# 表示将$reg1和$reg2中的内容进行按位或非操作，结果存放到$reg3中
~~~

Example:

$t1：0000 0000 0000 0000 0011 1100 0000 0000

$t2：0000 0000 0000 0000 0000 0000 0000 0000

~~~shell
nor $t0, $t1, $t2
~~~

执行上面的操作，结果为

$t0：1111 1111 1111 1111 1100 0011 1111 1111

\$t0的内容就是​\$t1的内容按位取反的结果

---

Constants are rare for NOR, since its main use is to invert the bits of a single operand; thus, the MIPS instruction set architecture has no immediate version of NOR.

常数在NOR中出现的很少，因为NOR的主要功能就是将单操作数按位取反，因此，MIPS ISA没有涉及支持NOR立即数的版本，即没有 nori 指令:heavy_exclamation_mark:

---

## 7. Conditional Branch 条件分支

**Conditional Branch**：An instruction that requires the comparison of two values and that allows for a subsequent transfer of control to a new address in the program based on the outcome of the comparison. 条件分支指令先比较两个值，然后根据比较的结果决定是否从程序中的一个新地址开始执行指令序列

### 7.1 相等/不相等则分支

MIPS language includes two decision-making instructions, similar to *if* statement with a *go to*

*beq* and *bne* are traditionally called conditional branches. beq 和 bne 指令传统上称为条件分支指令

+ ***beq***：Branch if equal. 相等则分支

  语法格式：

  ~~~shell
  beq $reg1, $reg2, label
  #如果$reg1的值与$reg2的值相等，则跳转到标签为label的语句执行
  ~~~

+ ***bne***：Branch if not equal. 不相等则分支

  语法格式：

  ~~~shell
  bne $reg1, $reg2, label
  #如果$reg1的值与$reg2的值不相等，则跳转到标签为label的语句执行
  ~~~

Example:

~~~C
if(i == j)
    f = g + h;
else
    f = g - h;
~~~

f、g、h、i、j都是变量，依次对应于\$s0 - \$s4，该C语言代码段编译后形成的MIPS代码为：

~~~shell
bne $s3, $s4, Else
add $s0, $s1, $s2
Else: sub $s0, $s1, $s2
~~~

---

### 7.2 小于则置位

+ ***slt***：Set less than. 小于则置位

语法格式：

~~~shell
slt $reg3, $reg1, $reg2
#如果$reg1的值比$reg2的值小，则$reg3的值置为1，否则为0
~~~

+ slti：Set less than immdiate. 小于立即数则置位

语法格式：

~~~shell
slti $reg2, $reg1, i
#如果$reg1的值比i的值小，则$reg2的值置为1，否则为0
~~~

Example:

~~~C
while(a[i] == k)
{
    sum += 1;
    i++;
}
~~~

i 和 k 对应于寄存器 \$s0 和 \$s1，sum对应于 \$s2，数组 a 的基址存放在 $s3 中，编译后的MIPS代码为：

~~~shell
Loop: sll $t0, $s0, 2 #$t0 = i * 4
	  add $t0, $s3, $t0 #$t0 = the address of a[i]
	  lw $t1, 0($t0) #$t1 = a[i]
	  addi $s2, $s2, 1 #sum = sum + 1
	  addi $s0, $s0, 1 #i = i + 1
	  bne $t1, $s1, Exit #if a[i] != k, go to Exit
	  j Loop #go to Loop
Exit:
~~~

MIPS体系结构没有提供小于则分支的指令，因为这种指令过于复杂，它会延长时钟周期时间，或增加平均执行每条指令的周期数(CPI)

> **Basic Block（基本块）**：A sequence of instructions without branches (except possibly at the end) and without branch targets or branch labels (except possibly at the beginning).  没有分支（可能出现在末尾者除外），并且没有分支目标/分支标签（可能出现在开始者除外）的指令序列

---

### 7.3 边界检查的简便方法

小于则置位有slt、slti、sltu和sltiu

slt和slti用于处理有符号整数，sltu和sltiu用于处理无符号整数

$s0：11111111 11111111 11111111 11111111

$s1：00000000 00000000 00000000 00000001

~~~shell
slt $t0, $s0, $s1
sltu $t1, $s0, $s1
~~~

执行上面两条指令后：

+ 执行slt指令，被认为进行有符号数的比较，\$s0中的值为 -1，\$s1中的值为 1，那么 $t0 中的值为1
+ 执行sltu指令，被认为进行无符号数的比较，\$s0中的值为4294967295，​\$s1中的值为仍为 1，那么 $t1 中的值为0

将有符号数作为无符号数来处理，是一种检验 $0 \leq x < y$ 的低开销方法，常用于检查数组的下标是否越界，问题的关键在于负数在二进制补码表示法中看起来像是无符号表示法中一个很大的数，因为在无符号数中最高有效位是符号位，而有符号数中最高有效位是具有最大权重的位。所以使用无符号数比较 x < y，在检查x是否小于y的同时，也检查了x是否为一个负数。

边界检查的简便方法：

$t1存储数组长度Length

~~~shell
sltu $t0, $s1, $t1 #$t0 = 0 if $s1 >= $t1 or $s1 < 0
beq $t0, $0, IndexOutOfBounds #if bad, go to errors
~~~