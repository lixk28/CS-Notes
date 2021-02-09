# Single-Cycle CPU 单周期处理器

[toc]

---

<img src="E:\image\image-20201123235021316.png" alt="image-20201123235021316" style="zoom: 50%;" />

:cyclone:**数据通路(Data Path)**：指令执行过程中，数据所经过的路径（包括路径中的部件），是**指令的执行部件**

:cyclone:**控制器(Control)**：对指令进行译码，生成指令对应的控制信号，控制数据通路的动作。能对指令的执行部件发出控制信号，是**指令的控制部件**。



**单周期(Singel-Cycle) CPU**：CPU执行**一条指令**用**一个时钟周期**（最简单的执行方式）

在时钟上升沿保存**指令的结果**和**下一条指令的地址**，Data Path上的资源每个指令周期最多用一次



---

处理器设计：step-by-step

+ 分析指令集：datapath需求
+ 选择datapath中包含的模块，确定这些模块的功能，时序
+ 组装datapath
+ 根据指令集决定datapath中需要的控制信号
+ 设计控制信号逻辑

---

## 1. Datapath 数据通路

### 1.1 从指令分析Datapath组成

The MIPS Instruction Formats

MIPS指令的3种格式：

+ R-type(Register):<img src="E:\image\image-20201123232117236.png" alt="image-20201123232117236" style="zoom:50%;" />

+ I-type(Immediate): <img src="E:\image\image-20201123232135848.png" alt="image-20201123232135848" style="zoom:50%;" />
+ J-type(Jump): <img src="E:\image\image-20201123232151736.png" alt="image-20201123232151736" style="zoom:50%;" />

各个域分别是：

+ op: 指令操作码
+ rs, rs, rt: 源寄存器，目的寄存器
+ shamt: 移位量
+ funct: 对op操作，确定详细的操作类型
+ address/immediate: 立即数或者地址
+ instr_index/target address: 目标地址

---

+ 存储器
  + 指令存储器
  + 数据存储器
+ 寄存器(32 x 32bit)
  + 为RS提供读取
  + 为RT提供读取
  + 为RT或者RD提供写入端口
+ 程序计数器PC和PC更新电路
+ 扩展电路
+ 算术运算和逻辑运算
  + 两个寄存器之间
  + 一个寄存器和一个经过扩展后的立即数之间

---

### 1.2 Datapath Element 数据通路部件

数据通路的组成：

+ 组合单元
+ 状态单元（存储单元）

---

#### 1.2.1 Combinational Element 组合单元

组合逻辑元件的特点：

+ 其输出只取决于当前的输入
+ 所有输入到达后，:star:**<u>经过一定的逻辑门延时</u>**，输出端改变，并一直保持直到下次改变，不需要时钟来定时

<img src="E:\image\image-20201124210257642.png" alt="image-20201124210257642" style="zoom: 50%;" />



数据通路中的组合单元：

+ 加法器 Adder: <img src="E:\image\image-20201124000327506.png" alt="image-20201124000327506" style="zoom:50%;" />
+ 多路选择器 MUX:  <img src="E:\image\image-20201124000624439.png" alt="image-20201124000624439" style="zoom:50%;" />
+ 译码器 Decoder: <img src="E:\image\image-20201124000758656.png" alt="image-20201124000758656" style="zoom:50%;" />
+ 算术逻辑单元 ALU: <img src="E:\image\image-20201124000827001.png" alt="image-20201124000827001" style="zoom:50%;" />

---

#### 1.2.2 State Element 状态单元

状态元件的特点：

+ 具有存储功能，在时钟控制下，输入状态被写入到电路中，直到下一个时钟到达
+ 输入端状态由时钟决定何时写入，输出段状态随时可以读出

定时方式：边沿触发(edge-triggered)方式，即状态单元中的值只在时钟边沿改变，每个时钟周期改变一次

+ 上升沿(rising edge)触发
+ 下降沿(falling edge)触发

最简单的状态单元：

+ D触发器：一个时钟输入、一个状态

<img src="E:\image\image-20201124210333296.png" alt="image-20201124210333296" style="zoom:50%;" />

---

:one:**Register 寄存器**
<img src="E:\image\image-20201124210452928.png" alt="image-20201124210452928" style="zoom:50%;" /> 

类似于D触发器，但有以下不同：

+ N-bit input and output
+ has a Write Enable input

Write Enable 写入使能端：

+ 0: Data Out will not change	
+ 1: Data Out will become Data In(on the clock edge)

---

:two:**Register File 寄存器堆**
<img src="E:\image\image-20201124213449452.png" alt="image-20201124213449452" style="zoom:50%;" />

Register File consists of 32 registers:

+ One 32-bit input bus(总线)
  
+  **busW (Write Data)**: The 32-bit data to be written into the selected register
  
+ Two 32-bit output buses

  + **busA (Read Data A)**: The data read from selected register A
  + **busB (Read Data B)**: The data read from selected register B

+ Three select input

  <u>The 5-bit input of RW, RA and RB represents the number of register.</u>

  + **RW (Register Write)**: Select the register to be written via busW(Write Data) <u>when Write Enable is 1</u>
  + **RA (Read Register A)**: Select the register to put on busA(Read Data A)
  + **RB (Read Register B)**: Select the register to put on busB(Read Data B)

+ One Write Enable

  + **Write Enable (Write Control)**: Control the RW

+ One clock input

  + **CLK**: The CLK input is a factor <u>ONLY</u> during write operaton CLK只在向寄存器写入数据时起作用

---

**:three:Memory 存储器**
<img src="E:\image\image-20201124220455639.png" alt="image-20201124220455639" style="zoom: 67%;" /><img src="E:\image\image-20201124222222977.png" alt="image-20201124222222977" style="zoom:50%;" />

An idealized Memory:

+ One 32-bit input bus

  + **Data In**: The 32-bit data to be written into memory word corresponding to the Address

+ One 32-bit output bus

  + **Data Out**: The 32-bit data read from the memory word corresponding to the Address

+ One Address (or two Addresses, one is address read, one is for address write)

  + **Address**: Represents the address of the memory word to be read or written

+ One Write Enable (or two Enables, one is for memory read, another is for memory write)
  + **Write Enable**: 

    + Write Enable = 1: Address selects the memory word to be written via the Data In bus

      当Write Enable为1时，将Data In输入的数据，写入通过Address选择的对应地址的32位字

    + Write Enable = 0: Address selects the word in memory to put on Data Out

      当Write Enable为0时，将Address选择的对应地址的32位字，输出到Data Out上

+ One clock input

  + **CLK**: The CLK input is a factor <u>ONLY</u> during write operaton CLK只在向寄存器写入数据时起作用
  + 

---

### 1.3 Five Stages of Datapath

**Generic Steps of Datapath**

<img src="E:\image\image-20201124224453262.png" alt="image-20201124224453262" style="zoom: 50%;" />

Five Stages of Datapath:

+ Stage 1: Instruction Fecth
+ Stage 2: Instruction Decode
+ Stage 3: ALU (Arithmetic-Logic Unit)
+ Stage 4: Memory Access
+ Stage 5: Register Write

---

**​S​ta​g​e​ :one:: Instruction Fetch​**

There are three parts of Instruction Fetch stage:
<img src="E:\image\image-20201124234022432.png" alt="image-20201124234022432" style="zoom: 50%;" />

Instruction Fetch Stage:
<img src="E:\image\image-20201124234608470.png" alt="image-20201124234608470" style="zoom: 50%;" /><img src="E:\image\image-20201124234722373.png" alt="image-20201124234722373" style="zoom:50%;" />

**PC (Program)**: The register containing the address of the instruction in the program being executed. 专门用来保存**<u>当前执行的指令的地址</u>**的寄存器

No matter what the instruction is, the 32-bit instruction word must first be fetched from memory, and then increment PC by 4. 无论是什么指令，必须先从指令存储器中取出这条指令，再将PC增加4

We don’t know if instruction is a Branch/Jump or one of the other instructions until we have fetched and interpreted the instruction from memory. So all instructions initially increment the PC.

Our implementation will fully execute one instruction per clock cycle: single cycle implementation.

On each clock edge, a new value for PC will be latched into the PC register. 每个时钟上升沿到来时，PC中保存的指令地址将会得到更新

**:cyclone:Instruction Fetch**

1. First, Fetch the Instruction: Inst <= InstMem[PC]
2. Second, Update the Program Counter: 
   + Sequential Code(顺序指令): PC <= PC + 4
   + Branch and Jump(分支或跳转指令): PC <= "Something else"

---

**Stage :two:: Instruction Decode**

Decoding instructions involves:

+ Sending the fetched instruction's opcode and function code to the control unit
+ Reading two values from the Register File (rs, rt, rd is contained in the instruction)

Instruction Decode Stage:
<img src="E:\image\image-20201125100021509.png" alt="image-20201125100021509" style="zoom:50%;" />

Note that both RegFile read ports are active for all instructions during the Decode cycle using the rs and rt instruction field addresses.

+ Since haven’t decoded the instruction yet, don’t know what the instruction is!
+ Just in case the instruction uses values from the RegFile do “work ahead” by reading the two source operands

Also, all instructions (<u>except *j*</u>) use the ALU after reading the registers.

**:cyclone:Instruction Decode**

​	Upon fetching the instruction, we next gather data from the fields (decode all necessary instruction data)

1. First, Read the opcode to determine instruction type and field lengths 

   首先，读取opcode，以确定指令类型和字段长度

2. Second, Read in data from all necessary registers

   然后，从相关寄存器读出数据

---

**Stage :three:: ALU**

**:cyclone:ALU**

The real work of most instructions is done here: arithmetic, shifting, logic, comparisons

lw and sw: we do the address + offset in this stage

---

**Stage :four:: Memory Access**

**:cyclone:Memory Access**

Only the load and store instruction do anything during this stage, the others remain idle this stage or skip it all together. 只有lw和sw指令执行此阶段，其他的指令在此阶段空闲或者直接跳过此阶段

As a result of the cache system, this stage is expected to be fast. 由于有cache系统，该阶段可以加速

---

**Stage :five:: Register Write**

**:cyclone:Register Write**

Most instrucions write the result of some computation into a register.

stores, branches and jumps:

+ Don't write anything into a register at the end
+ These remain idle during this stage or skip it all together

---

### 1.4 MIPS ISA  

MIPS Instruction: <img src="E:\image\image-20201125132814498.png" alt="image-20201125132814498" style="zoom:50%;" />

+ *R-type*: <img src="E:\image\image-20201125132846834.png" alt="image-20201125132846834" style="zoom:50%;" />

  ​			ALU with register operands: **Reg[rd] <= Reg [rs] op Reg[rt]**

  ​			shift: **Reg[rd] <= Reg[rt] shift (shamt)** or **Reg[rd] <= Reg[rt] shift Reg[rs]**

+ *I-type*: <img src="E:\image\image-20201125133023451.png" alt="image-20201125133023451" style="zoom:50%;" />

  ​			ALU with constant operands: **Reg[rt] <= Reg[rs] op SEXT(immediate)** 

  ​			Load: **Reg[rt] <= Mem[Reg[rs] + SEXT(immediate)]**

  ​			Store: **Mem[Reg[rs] + SEXT(immediate)] <= Reg[rt]**		

  ​			Branch: **if(Reg[rs] == Reg[rt])	PC <= PC + 4 + SEXT(immediate)**	(or Reg[rs] != Reg[rt])

+ *J-type*: <img src="E:\image\image-20201125133312131.png" alt="image-20201125133312131" style="zoom:50%;" />

  ​			Jump: **PC <= (PC & 0xf0000000) | 4 * (immediate)**

<img src="E:\image\image-20201125133807871.png" alt="image-20201125133807871" style="zoom: 67%;" />

---

### 1.5 Datapath Buiding

#### :one: Datapath for Instruction Fecth/Decode


<img src="E:\image\image-20201125125902442.png" alt="image-20201125125902442" style="zoom:50%;" />

<img src="E:\image\image-20201125173253206.png" alt="image-20201125173253206" style="zoom: 75%;" />

---

#### :two: Datapath for 3-Operand ALU

<img src="E:\image\image-20201125130305872.png" alt="image-20201125130305872" style="zoom:50%;" />		<img src="E:\image\image-20201125173547277.png" alt="image-20201125173547277" style="zoom:75%;" />

​	R-type Instructions: *add, sub, slt, and, or*

+ rs, rt and rd will be the input Write Register, Read Register 1 and Read Register 2

+ op and func will be decoded into ALU operation

  On the clock edge, the data is read, which moves through the ALU, hopefully in time to be latched into the write port at the next clock edge
  <img src="E:\image\image-20201125130959563.png" alt="image-20201125130959563" style="zoom:50%;" />

---

#### :two: Datapath for Shift

<img src="E:\image\image-20201125174725760.png" alt="image-20201125174725760" style="zoom:75%;" />

---

#### :three: Datapath for Immediate

<img src="E:\image\image-20201125184851819.png" alt="image-20201125184851819" style="zoom:75%;" />

​	sign-extend(符号拓展): Increase the size of a data item by replicating the high-order sign bit of the original 	data item in the high-order bits of the larger destination data item.

---

#### :four: Datapath for Load/Store

<img src="E:\image\image-20201125131305478.png" alt="image-20201125131305478" style="zoom: 33%;" />
<img src="E:\image\image-20201125185834954.png" alt="image-20201125185834954" style="zoom: 75%;" />

​		Load Instruction Control Signals:
​			ASEL = 0
​			BSEL = 1
​			SEXT = 1
​			WDSEL = 1
​			WERF = 1

<img src="E:\image\image-20201125185940666.png" alt="image-20201125185940666" style="zoom:67%;" />

​		Store Instruction Control Signals:
​			ASEL = 0
​			BSEL = 1
​			SEXT = 1
​			WDSEL = 1
​			WERF = 1
​			Wr = 1			

---

#### :five: Datapath for Jump

<img src="E:\image\image-20201125193100522.png" alt="image-20201125193100522" style="zoom:67%;" />

---

#### :six: Datapath for Branch

<img src="E:\image\image-20201125194503256.png" alt="image-20201125194503256" style="zoom: 80%;" />

---

:seven: 