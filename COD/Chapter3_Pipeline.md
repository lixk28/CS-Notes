# Pipline 流水线

[toc]

---

定时钟周期：选取多个任务中最长的时间为时钟周期

+ 流水线不改善单个任务的延迟(latency)，



---

数据通路流水线化：
目标：保证几乎为1.0的CPI，同时提高时钟速率
方法：将处理器变成一个多级流水线

---

Pipeline Performance

Pipeline Speedup

$\displaystyle Time \ to \ an \ instruction_{pipeline} = \frac{Time \ to \ execute \ an \ instruction_{sequential}}{Number \ of \ stages}$

---

Pipeline Registers

在不同阶段之间增加寄存器，保存前一个周期产生的信息
<img src="E:\image\image-20201125082539933.png" alt="image-20201125082539933" style="zoom:50%;" />

Use datapath figure below to represent pipeline:
<img src="E:\image\image-20201125082649791.png" alt="image-20201125082649791" style="zoom:67%;" />

流水线寄存器命名规则：前级/后级

:one:IF/ID	:two:ID/EX	:three:EX/MEM	:four:MEM/WB

流水线受时钟控制

功能：时钟上升沿到来时，保存前级结果，在下个时钟上升沿到来时，输出到下级组合逻辑

---

MIPS Pipeline Control Path Modifications
<img src="E:\image\image-20201125085936980.png" alt="image-20201125085936980" style="zoom: 67%;" />

控制信号每一级往下一级传递，需要在这一级用到的控制信号，下一级就不需要了

---

Events on Pipe Stages of the MIPS Pipeline
<img src="E:\image\image-20201125090453181.png" alt="image-20201125090453181" style="zoom: 67%;" />

IR represents Instruction

---

控制信号在IF/ID阶段产生，由控制逻辑电路译码生成

控制信号也必须流水线化，因为每一个阶段不仅需要数据，还需要相应的控制信号
<img src="E:\image\image-20201125092515258.png" alt="image-20201125092515258" style="zoom:50%;" />

---

## Hazards

**Hazard(冒险)** is a situation that prevents starting the next instruction in the next cycle.

+ Structure hazard(结构冒险): 同一个部件被不同指令所使用
+ Data hazard(数据冒险): 后面的指令用到前面指令结果时，前面指令的结果还没有产生(数据依赖)
+ Control hazard(控制冒险): 转移或异常改变执行流程，顺序执行指令在目标地址产生前已经取出

---

### :one: Structure Hazard

+ 将 Instruction Memory 和 Data Memory 分开

+ Register File Access is fine, clock rising edge controls register writing, clock falling edge controls loading of pipeline state registers

  通过设置在上升沿触发寄存器写入操作（在前半个周期完成），在下降沿触发寄存器读出操作（在后半个周期完成）

  这种方法是可行的，因为时钟周期是按最长阶段确定的，而寄存器的访问很快

---

### :two: Data Hazard

+ 寄存器竞争

  + Method 1: Stall(流水线阻塞)，延迟到数据写入到寄存器之后，后续指令才继续执行
    + 缺点：控制非常复杂，需要修改数据通路，还会影响到吞吐率
  + Method 2: 这是最差的做法，由编译器插入若干条NOP指令，浪费指令的空间和时间
  + Method 3: Forwarding(转发) / Bypassing(旁路) 利用Datapath的中间数据
    + 把数据从流水段寄存器中直接取到ALU的输入端，寄存器写/读端口分别在前/后半周期，使写入被直接读出
    + <img src="E:\image\image-20201127103925904.png" alt="image-20201127103925904" style="zoom:50%;" />
    + <img src="E:\image\image-20201127104027555.png" alt="image-20201127104027555" style="zoom:50%;" />

  Datapath with forwarding hardware:
  <img src="E:\image\image-20201127104442882.png" alt="image-20201127104442882" style="zoom:60%;" />

Load 指令采用第5周期下降沿写入的状态

---

### :three: Control Hazard

当指令的流向不是预期的方式：

+ 有条件分支(beq, bne)需阻塞3个周期
+ 无条件跳转需阻塞1个周期

Jump指令在ID阶段可以被判断出来，这时只需要阻塞一个周期（只能这么做）

bne和beq指令在EX阶段可以被判断出来，需要阻塞三个周期

---

### 分支预测

假定一个分支的结果，不等待实际的分支判断，直接根据假定的分支结果执行流程。

+ 总假设分支不发生
+ 总假设分支发生
+ 动态预测

---

~~~shell
lw $6, 0($7)
add $8, $9, $10
sub $11, $6, $8
//不需要阻塞
//转发可以解决
~~~

---

| IF    | ID    | EX    | MEM   | WB    |
| ----- | ----- | ----- | ----- | ----- |
| 305ps | 275ps | 280ps | 305ps | 250ps |

流水线的时钟周期：t~setup~ + t~clk-q~ + t~max-pipeline~(在上面五个阶段中取最长的)

---

`$s0 - $s3 = 56 30 30 7  `

`$t0 - $t4 = 7 7 7 7 7`

~~~shell
add $t0, $s0, $0
and $t1, $t0, $s1
or $t2, $t0, $s2
sub $t3, $t0, $s3
srl $t4, $t0, 2
~~~

没有转发、没有阻塞、没有检测的流水线CPU

在第七个周期时，`$t0 - $t4 = ?`：56 ,6, 3 ,7, 7

在第八个周期时，`$t0 - $t4 = ?`：56, 6, 31, 49, 7

在第九个周期时，`$t0 - $t4 = ?`：56, 6, 31, 49, 14

and or 运算结果是错的

---

~~~shell
start:	lw $t0, 0($a0)
		beq $t0, 0, end
		addiu $t0, $t0, 10
		sw $t0, 0($a0)
end:	
~~~

从数据依赖性上来看：

beq 和 addiu 之间需要阻塞吗？如果需要，则应阻塞几个周期？：不需要

addiu 和 sw 之间需要阻塞吗？需要转发吗？：不需要阻塞，需要转发，从MEM/WB => MEM

---

~~~shell
		lw $v0, 0($a0)
loop:	beq $a1, $0, exit
		sll $v0, $v0, 1
		addi $a1, $a1, -1
		sw $v0, 0($a0)
		j loop
exit:	jr $ra
~~~



