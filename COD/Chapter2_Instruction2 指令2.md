# Instruction2 指令2

[toc]

---

## Procedure 过程

***Procedure*(过程)**： A stored subroutine that performs a specific task based on the parameters with which it is provided. 根据提供的参数执行一定任务的存储的子程序

Procedure also called functions, methods or subroutines.

A procedure or function is one tool programmers use to structure programs, both to make them easier to understand and to allow code to be reused. 过程或函数时程序员进行结构化编程的工具，两者均有助于提高程序的可理解性和代码的可重用性

Similarly, in the execution of a procedure, the program must follow these six steps: 

1. Put parameters in a place where the procedure can access them. 将参数放在过程可以访问的位置
2. Transfers control to the procedure. 将控制转交给过程
3. Acquire the storage resources needed for the procedure. 获得过程所需的存储资源 
4. Perform the desired task. 执行需要的任务
5. Put the result value in a place where the calling program can access it. 将结果的值放在调用程序可以访问的位置
6. Return control to the point of origin, since a procedure can be called from several points in a program. 将控制返回初始点，因为一个过程可能由一个程序中的多个点调用

+ ***Caller*(调用者)**：The program that instigates a procedure and provides the necessary parameter values.  调用一个过程并为过程提供必要参数值的程序
  + A “calling” program (Caller) must：
    + Provide procedure parameters. In other words, put the arguments in a place where the procedure can access them
    + Transfer control to the procedure. “Jump” to it, and provide a “link” back

+ ***Callee*(被调用者)**：A procedure that executes a series of stored instructions based on parameters provided by the caller and then returns control to the caller. 根据调用者提供的参数执行一系列存储的指令，然后将控制权返回个调用者的过程
  + A “called” procedure (Callee) must:
    + Acquire/create resources needed to perform the function (local variables, registers, etc.)
    + Perform the function
    + Place results in a place where the Caller can find them
    + Return control back to the Caller through the supplied link
+ ***Program Counter*(程序计数器)**：The register containing the address of the instruction in the program being executed. 包含在程序中正在被执行指令地址的寄存器，在存储程序的概念中，专门使用一个寄存器来保存**<u>当前运行的指令的地址</u>**，程序计数器在MIPS体系结构中缩写为**PC**

---

### 1. Procedure in MIPS

MIPS软件在为过程调用分配寄存器时遵循以下规定：

+ **\$a0 - \$a3**：用于传递参数的 4 个**参数寄存器** (<u>a</u>rguments)
+ **\$v0 - \$v1**：用于返回值的两个**返回值寄存器** (<u>v</u>alues)

+ **\$ra**：用于返回起始点的**返回地址寄存器** (<u>r</u>eturn <u>a</u>ddress)，其中存储的地址称为**返回地址(return address)**, 返回地址是必需的，因为<u>同一过程可能在程序的不同部分调用</u>

MIPS汇编语言为过程调用提供了一条过程调用指令，称为**跳转和链接指令(jump-and-link instruction)**：**跳转到某个地址的同时将下一条指令的地址保存在寄存器\$ra中**

MIPS汇编语言为过程返回提供了一条过程返回指令，称为**寄存器跳转指令(jump register)**：**表示无条件跳转到寄存器所指定的地址**

+ ***jal***：Jump and link(it should be jump after link actually). 跳转和链接

  语法格式：

  ~~~shell
  jal ProcedureAddress	#ProcedureAddress 表示过程的地址
  ~~~

+ ***jr***：JUmp register. 寄存器跳转

  语法格式：

  ~~~shell
  jr $ra	#$ra是专门用于保存返回地址即PC+4的寄存器
  ~~~

+ jal 和 jr 的功能：

  1. 首先，jal 指令将当前指令 (即jal自己) 的下一条指令的地址，或者我们用program counter的概念表示，即将 **PC+4** 保存在寄存器 \$ra 中，为过程返回作准备

  2. 然后，程序会跳转到地址为 ProcedureAddress 的指令处，执行过程
  3. 最后，过程执行完成后，在过程的最后一条指令总是 jr 指令，返回到 caller

  将参数值放在 \$a0 - \$a3，然后使用 jal X 跳转到过程 X，被调用者执行运算，将结果放在 \$v0 - \$v1，然后使用 jr \$ra 将控制返回给调用者

---

### 2. Procedure Call and Stack

#### 2.1 Stack 栈

***Stack*(栈)**：A data structure for spilling registers organized as a last-in-first-out queue. 后进先出的队列

The last-in element called ***stack top*(栈顶)**, the first-in element called stack ***bottom*(栈底).**

Placing data onto the stack is called a ***push(压栈)***, and removing data from the stack is called a ***pop*(出栈)**.

***Stack pointer*(栈指针)** points at the stack top.

<img src="E:\image\image-20201018151812001.png" alt="image-20201018151812001" style="zoom:50%;" />

MIPS reserves register 29 for the stack pointer, named \$sp. MIPS 保留 29 号寄存器作为栈指针寄存器

MIPS Stack Convention:

+ **<u>Stack grows from the high address to low address</u>** 栈是从高地址向低地址生长的

  也就是**从低地址向高地址压栈**，出栈则相反

+ Every entry in stack accounts for 4 bytes 栈中每个元素占 1 个字

+ **Push and pop are implemented by instruction sw and lw** 压栈和出栈操作用指令 sw 和 lw 实现

+ **\$sp must be adjusted by instruction add and sub** 栈指针必须用指令 add 和 sub 来调整

  Unlike x86, which has instruction push and pop that can adjust stack pointer automatically

---

Stack Management Primitives:

+ Allocate k: Reserve k words of stack

  ~~~shell
  addi $sp, $sp, -4k
  ~~~

+ Deallocate k: Release k words of stack

  ~~~shell
  addi $sp, $sp, 4k
  ~~~

+ Push Rx: Push Reg[x] onto stack

  ~~~shell
  addi $sp, $sp, -4
  sw $Rx, 0($sp)
  ~~~

+ Pop Rx: Pop the value on the top of the stack into Reg[x]

  ~~~shell
  lw $Rx, 0($sp)
  addi $sp, $sp, 4
  ~~~

  

---

 The function and importance of Stack:

+ Somtimes we need more than 4 arguments and 2 return values, so we must create some local variables in procedure, and release them after the procedure is executed

  有时候我们需要在过程中定义和使用局部变量（单个变量、数组、结构体等）

+ Sometimes we need to use the register that have used in caller, but these registers must be restored to the values that they contained before the procedure was invoked

  有时候我们需要在过程中使用调用者中的寄存器

+ For nested procedure, we need to store the value in \$ra, because we only have one \$ra to store PC+4, if we don't store the value in \$ra, and the procedure calls another procedure, we cannot return the caller.

  Also, the nested procedures normally need to reuse return value registers.

  对于嵌套过程，我们需要多次使用 \$ra，并且可能要重复使用 \$v0 - \$v1

  <img src="E:\image\备注 2020年10月18日.png" style="zoom: 33%;" />

---

#### 2.2 Leaf Procedure 叶过程

***Leaf Procedure*(叶过程)**：Procedures that do not call other procedures. 不调用其他过程的过程

There is a leaf procedure in C:

The parameter variables a, b, c, and d correspond to the argument registers \$a0, \$a1, \$a2, and \$a3, and f corresponds to \$s0. 

~~~C
int leaf_example(int a, int b, int c, int d)
{
    int e;
    e = (a + b) - (c + d);
    return e;
}
~~~

The compiled MIPS aseembly code:

~~~shell
leaf_example:	addi $sp, $sp, -12		# adjust stack to make room for 3 items
				sw $t1, 8($sp)			# save register $t1 for use afterwards
				sw $t0, 4($sp)			# save register $t0 for use afterwards
				sw $s0, 0($sp)			# save register $s0 for use afterwards
				
				add $t0, $a0, $a1
				add $t1, $a2, $a3
				sub $s0, $t0, $t1
				add $v0, $s0, $zero
				
				lw $s0, 0($sp)			# restore register $s0 for caller
				lw $t0, 4($sp)			# restore register $t0 for caller
				lw $t1, 8($sp)			# restore register $t1 for caller
				addi $sp, $sp, 12		# adjust stack to delete 3 items
				
				jr $ra					# jump back to calling routine
~~~

为了避免保存和恢复一个值未被使用过的寄存器（通常是临时寄存器），MIPS将18个寄存器分为 2 组：

+ **\$t0 - \$t9**：10个临时寄存器(temporary)，在过程调用中**不必被**被调用的过程保存
+ **\$s0 - \$s7**：8个保留寄存器(save)，在过程调用中**必须被**保存并且恢复

#### 2.3 Stack Frame 栈帧

如果栈中需要定义**一些不适用于寄存器的局部变量**，例如局部的数组和结构体等，我们就需要在栈中为这些局部变量分配空间。

**Stack Frame(栈帧)** / ***Procedure Frame*(过程帧)** / ***Activation Record*(活动记录)**：Every procedure has its own stack area, the segment of the stack containing a procedure’s saved registers and local variables. 一个过程的栈帧是这个过程的栈区，是栈中包含过程所保存的寄存器和局部变量的片段

+ 每个过程都有自己的栈区，栈由若干个栈帧组成
+ 用专门的帧指针寄存器指定起始位置
+ 当前栈帧的范围在帧指针和栈指针之间
+ 当使用帧指针时，在调用中使用 \$sp 的地址进行初始化，而 \$sp 可以用 \$fp 来恢复
+ 程序执行时，栈指针可以移动，但帧指针不变，所以过程内对栈信息的访问大多通过帧指针进行

***Frame Pointer*(帧指针)**: A value denoting the location of the saved registers and local variables for a given procedure. 指向给定过程中保存的寄存器和局部变量的值

<img src="E:\image\image-20201018155334657.png" alt="image-20201018155334657" style="zoom:50%;" />

#### 2.4 Nested Procedure 嵌套过程

递归

