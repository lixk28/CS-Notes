# Performance 性能

[toc]

---

## 1.Performance Metrics 性能的量度

> + **Latency/Response Time/Execution Time（响应时间/执行时间）**：Clocks from input to corresponding output  执行时间
> + **Throughput/Bandwidth（吞吐率/带宽）**：How many results per clock 单位时间内完成任务的数量
>



1. If we upgrade a machine with a new faster processor, what do we improve? 

   如果我们将计算机的处理器替换为更高速的型号

   **Generally, Decreasing response time almost improves throughput.** Hence, both response time and throughput are improved.

   **一般来说，降低响应时间几乎都可以增加吞吐率。**因此，这个方案同时改进了响应时间和吞吐率。

   

2. If we add additional processors to a system that uses multiple processor for seperate tasks, what do we improve?

   如果我们为一个系统增加多个处理器来分别处理独立的任务

   No one tasks gets work done faster, only throughput increases.

   这个方案不会使任务完成的更快，只会增加其吞吐率。



For a computer X, we can relate its performance and execution time 对于某个计算机X，我们可以表述为：
$$
Performance_X = \frac{1}{Execution \ Time_X} \quad (性能_X = \frac{1}{执行时间_X})
$$


In discussing a computer design, we often want to relate the performance of two different conputers quantitatively.

We will use the phrase "X is n times faster than Y" to mean 在讨论计算机设计时，经常要定量地比较两台不同计算机的性能

我们使用 "X 是 Y 的 n 倍快" 的表达方式，即：
$$
\frac{Performance_X}{Performance_Y} = n \quad (\frac{性能_X}{性能_Y} = n)
$$
If X is n times as fast as Y, then the execution time on Y is n times as long as it is on X:
$$
\frac{Performance_X}{Performance_Y} = \frac{Execution \ Time_Y}{Execution \ Time_X} = n
$$
Example: If computer A runs a program in 10 seconds and computer B runs the same program in 15 seconds, how much faster is A than B?

$ \frac{Performance_A}{Performance_B} = \frac{Execution \ time_A}{Execution \ time_B} = \frac{15}{10} = 1.5 $



---

### 1.1 Response Time/Execution Time  响应时间/执行时间

Time is the measure of computer performance:the computer that performs the same cmount of work in the least time is the fastest.

The most straightfroward definition of time is called ***wall clock time(墙上时钟时间）***, ***response time(响应时间)***, or ***elapsed time(消逝时间)***.

These terms mean the total time to complete a task（考虑所有时间）, including disk accesses, memory accesses, input/output(I/O) activities, operating  system overhead.



+ **CPU Execution Time(CPU执行时间)**：简称**CPU Time(CPU 时间)**，执行某一任务在CPU上花费的时间，而不包括等待I/O或运行其他程序的时间

  注意：用户所感受到的是响应时间，而不是CPU时间

  CPU时间可分为用于用户程序的时间和操作系统为用户服务花去的CPU时间：

  $ \begin{cases}
  	用户CPU时间：在程序本身所花费的CPU时间\\
  	系统CPU时间：为执行程序而花费在操作系统上的时间
  \end{cases} $

---

### 1.2 CPU Clocking

+ **时钟周期(Clock Cycle)**：The time for one clock period, usually of the processor clock, which runs at a constant time.  计算机一个时钟周期的时间，通常是处理器时钟，一般为常数

  也叫 tick、clock tick、colck period、clock 或 cycle

+ **时钟长度(Clock Period)**：Duration of a clock cycle. 每个时钟周期持续的时间长度

Let CP represent Clock Cycle Time/Clock Period, CR represent Clock Rate
$$
CP = \frac{1}{CR} \quad 时钟周期 = \frac{1}{时钟频率}
$$

> 1s = 10^3^ ms = 10^6^ us = 10^9^ ns = 10^12^ ps

> 1MHz = 10^6^ Hz
>
> 1GHz = 10^9^ Hz

Example：时钟周期为 250ps，对应的时钟频率为 4GHz

---

## 2. CPU Performance and Its Factors CPU 性能及其影响因素

CPU的性能量度针对的是CPU执行时间，我们关注的是CPU执行时间

 A simple formula relates the most basic metrics (clock cycles and clock cycle time) to CPU time:
$$
CPU \ execution \ time \ for \ a \ program = CPU \ clock \ cycles \ for \ a \ program \times Clock \ cycle \ time
$$

$$
一个程序的CPU执行时间 = 一个程序的CPU时钟周期数 \times 时钟周期时间
$$

Alternatively, because clock rate and clock cycle time are inverses:
$$
CPU \ execution \ time \ for \ a \ program = \frac{CPU \ clock \ cycles \ for \ a \ program}{Clock  \ rate} 
$$

$$
一个程序的CPU执行时间 = \frac{一个程序的CPU时钟周期数}{时钟频率}
$$

---

### 2.1 Instruction Performance 指令的性能

+ **IC（instruction count）**：The number of instructions executed for a program. **执行某程序所需要的总指令数量**
+ **CPI（clock cycles per instruction）**: The average number of clock cycles per instruction for a program or program fragment.  即**执行每条指令所需要的时钟周期数**，表示执行某个应用程序或者程序片段时所需要的时钟周期**<u>平均数</u>**    

$$
CPI = \frac{CC}{IC} = \frac{执行某程序所需要的时钟周期数}{执行某程序所需要的总指令数}
$$

---

### 2.2 The Classical CPU Performance Equation 经典CPU性能公式

CPU performance is dependent upon three characteristics:

+ clock cycle/rate   **CC/CR**
+ clock cycles per instruction   **CPI**
+ instruction count   **IC**



**Basic CPU performance equation：**
$$
CPU \ time = Instruction \ count \times CPI \times Clock \ cycle \ time = IC \times CPI \times CP\\
（CPU时间 = 程序指令数 \times CPI \times 时钟周期）
$$
or, since the clock rate is the inverse of clock cycle time:
$$
CPU \ time = \frac{Instruction \ count \times CPI}{Clock \ Rate} = \frac{IC \times CPI}{CR} \\
（CPU时间 = \frac{程序指令数 \times CPI}{时钟频率}）
$$


---

### 2.3 Another Measure - MIPS 另一种评估方式 - MIPS

**MIPS（Millions of Instruction per Second）**：**每秒执行多少百万条指令**
$$
MIPS = \frac{Instruction \ count}{Execution \ time \times 10^6}
	 = \frac{Instruction \ count}{\frac{Instruction \ count \times CPI}{Clock \ rate} \times 10^6} 
	 = \frac{Clock rate}{CPI \times 10^6}
$$
which is:
$$
MIPS = \frac{CR}{CPI \times 10^6}
$$
MIPS doesn't account for:

+ 不同机器，指令集不同，无法比较
+ 同一机器，程序代码不同，MIPS会随之变化
+ MIPS可能会跟性能成反比

**<u>执行时间是唯一有效的计算机性能度量方法</u>**

---

## 3. Examples

eg1. Consider the following performance measurements for a program:：

|   Measurement    | Computer A  | Computer B |
| :--------------: | :---------: | :--------: |
| Instructon Count | 100 billion | 80 billion |
|    Clock Rate    |    4GHz     |    4GHz    |
|       CPI        |     1.0     |    1.1     |

1. Which computer has the higher MIPS rating？
2. Which computer is faster？

Sol:

1. 计算机A：$ MIPS_A = \frac{时钟频率~A}{CPI_A \times 10^6} = \frac{4 \times 10^9}{1.0 \times 10^6} = 4000 $

   计算机B：$MIPS_B= \frac{时钟频率_B}{CPI_B \times 10^6} = \frac{4 \times 10^9}{1.1 \times 10^6} = 3636 $

   所以B的MIPS更高

2. 计算机A的CPU执行时间：$T_A = \frac{指令数_A \times CPI_A}{时钟频率_A} = \frac{(100 \times 10^8) \times 1.0}{4 \times 10^9} = 2.5s$

   计算机B的CPU执行时间：$T_B = \frac{指令数_B \times CPI_B}{时钟频率_B} = \frac{(80 \times 10^8) \times 1.1}{4 \times 10^9} = 2.2s$

   所以计算机B更快，虽然A的MIPS大，但A的指令数更多，用得时间更长，所以B的性能更好



---

**Amdahl's Law 阿姆达尔定律**：The performance enhancement possible with a given improvement is limited by the amount that the improved feature is used. It is a quantitative version of the law of diminishing returns.

**优化大概率事件远比优化小概率事件更能提高性能**
$$
Execution \ time \ after \ improvement = \frac{Execution \ time \ affected \ by \ improvement}{Amount \ of \ improvement} + Execution \ time \ unaffected
$$

$$
t_{improved} = \frac{t_{affected}}{R_{speedup}} + t_{unaffected}
$$

$$
Speedup = \frac{1}{\frac{f}{r} + (1 - f)}
$$

r 为改善倍率，f 为可改进比例



Example: Suppose a program runs in 100 seconds on a machine, where multiplies are executed 80% of the time. How much do we need to improve the speed of multiplication if we want the program to run 4 times faster?"