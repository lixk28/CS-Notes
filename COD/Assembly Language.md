# Assembly Language

[toc]

## 1. Assembler Directives

A . before an text string means the token(string) that follows it is an **assembler *directive*（汇编程序指令）**. 

Assembler DIRECTIVES = Keywords prefixed with ‘.’

Offcial Doc:

+ .align      Align next data item on specified byte boundary (0=byte, 1=half, 2=word, 3=double)  
+ .ascii      Store the string in the Data segment but do not add null terminator  
+ .asciiz     Store the string in the Data segment and add null terminator  
+ .byte       Store the listed value(s) as 8 bit bytes  
+ .data       Subsequent items stored in Data segment at next available address  
+ .double     Store the listed value(s) as double precision floating point  
+ .end_macro  End macro definition.  See .macro  
+ .eqv        Substitute second operand for first. First operand is symbol, second operand is expression (like #define)  
+ .extern     Declare the listed label and byte length to be a global data field  
+ .float      Store the listed value(s) as single precision floating point  
+ .globl      Declare the listed label(s) as global to enable referencing from other files  
+ .half       Store the listed value(s) as 16 bit halfwords on halfword boundary  
+ .include    Insert the contents of the specified file.  Put filename in quotes.  
+ .kdata      Subsequent items stored in Kernel Data segment at next available address  
+ .ktext      Subsequent items (instructions) stored in Kernel Text segment at next available address  
+ .macro      Begin macro definition.  See .end_macro  
+ .set        Set assembler variables.  Currently ignored but included for SPIM compatability  
+ .space      Reserve the next specified number of bytes in Data segment  
+ .text       Subsequent items (instructions) stored in Text segment at next available address  
+ .word       Store the listed value(s) as 32 bit words on word boundary

---

Syntax of several commonly used assembler directives:

+ Control the placement and interpretation of bytes in memory 控制存储器中字节的分布方式和解释
  + .data <address>：Subsequent items are considered data 后面的内容都被视为数据
  + .text <address>：Subsequent items are considered instructions 后面的内容都被视为指令
  + .align N：Skip to next address multiple of 2^N^ 跳过 2^N^ 个字节，不存储任何内容
+ Allocate Storage 给内存分配内容
  + .byte b~1~, b~2~, …, b~n~：Store a sequence of bytes (8 bits) 
  + .half h~1~, h~2~, …, h~n~：Store a sequence of half-words (16 bits)
  + .word w~1~, w~2~, …, w~n~：Store a sequence of words (32 bits)
  + .ascii "string"：Store a sequence of ASCII encoded bytes (every character is stored in byte)
  + .asciiz "string"：Store a sequence of zero-terminated ASCII encoded bytes (end with a zero word)
  + .space N：Reserve N successive(连续的) bytes
+ Defien Scope 定义作用域
  + .global sym：Declare symbol to be visible to other files
  + .extern sym size：Sets size of symbol defined in another file (Also make it directly addressable)

---

## 2. Assembler Coments

All text follow a '#' to the end of the line is ignored

## 3. Assembler Labels

***Labels*（标签）** are symbols thar **<u>represent memory address</u>**. A label is just a <u>**marker**</u> in the code that **<u>can be used in other statements</u>**.

+ Labels take on the value of the address where they are declared.

+ Labels can be for data as well as for instructions.

Label Syntax:  ***label*: data/instruction**

In MIPS assembler any text string followed by a ':' is a label.

~~~shell
.data 0x80000000
	item: .word 1	# a data word label

.text 0x00010000
	start: add $t0, $s0, $s1	# an instruction label
~~~

<u>The label *main* does not need to be included</u> as MARS assumes the program begins at the first line in the assembled program. BUT <u>it is nice to label the starting point</u>, and generally most runtimes will look for a global symbol named *main* as the place to begin execution.



**ONLY** instructions and labels can be defined in a text segment, **ADN ONLY** data and labels canbe defined in a data segment.

You can have <u>multiple data segments and multiple text segments</u> in a program, but **<u>the text must be in a text segment</u>** and t**<u>he data in a data segment</u>**.



## 4. Pseudo Instructions

+ ***li***（load immediate）
  + syntax：***li $r, i***
  + function：load the number i into regiser $r
+ ***la***（load address）
  + syntax：
    1. ***la $r, addr***
    2. ***la \$r, \$base***
    3. ***la \$r, (offset)\$base***
  + function：
    1. load the address addr into register $r
    2. load the address stored in register \$base into register \$r
    3. load the sum of the address stored in register \$base and offset into register \$r
+ ***move***
  + syntax：***move \$r1, \$r2***
  + function：move the text from register \$r2 to ​\$r1
+ 

## 5. System Service

The ***syscall*** operator is used to call system services.

System services provide access to the user console, disk drivers, and any other external devices.

The service to be executed is a number stored in the $v0 register.



​      A number of system services, mainly for input and output, are available for use by your MIPS program. They are described in the table below. MIPS register contents are not affected by a system call, except for result registers as specified in the table below.    

***How to use SYSCALL system service*：**  

> Step 1. Load the service number into register \$v0.
> Step 2. Load argument values, if any, in \$a0, ​\$a1, ​\$a2, or \$f12 as specified.
> Step 3. Issue the SYSCALL instruction.
> Step 4. Retrieve return values, if any, from result registers as specified.

Example: display the value stored in \$t0 on the console

```shell
li  $v0, 1           # service 1 is print integer
add $a0, $t0, $zero  # load desired value into argument register $a0, using pseudo-op
syscall
```

​      **Table of Available Services：**    

| Service                                                      | Code in $v0 | Arguments                                                    | Result                                                       |
| ------------------------------------------------------------ | ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| print integer                                                | 1           | $a0 = integer to print                                       |                                                              |
| print float                                                  | 2           | $f12 = float to print                                        |                                                              |
| print double                                                 | 3           | $f12 = double to print                                       |                                                              |
| print string                                                 | 4           | $a0 = address of null-terminated string to print             |                                                              |
| read integer                                                 | 5           |                                                              | $v0 contains integer read                                    |
| read float                                                   | 6           |                                                              | $f0 contains float read                                      |
| read double                                                  | 7           |                                                              | $f0 contains double read                                     |
| read string                                                  | 8           | $a0 = address of input buffer $a1 = maximum number of characters           to read | *See note below table*                                       |
| sbrk (allocate heap memory)                                  | 9           | $a0 = number of bytes to allocate                            | $v0 contains address of allocated memory                     |
| exit (terminate execution)                                   | 10          |                                                              |                                                              |
| print character                                              | 11          | $a0 = character to print                                     | *See note below table*                                       |
| read character                                               | 12          |                                                              | $v0 contains character read                                  |
| open file                                                    | 13          | $a0 = address of null-terminated string containing filename $a1 =           flags $a2 = mode | $v0 contains file descriptor (negative if error). *See note below           table* |
| read from file                                               | 14          | $a0 = file descriptor $a1 = address of input buffer $a2 =           maximum number of characters to read | $v0 contains number of characters read (0 if end-of-file, negative           if error). *See note below table* |
| write to file                                                | 15          | $a0 = file descriptor $a1 = address of output buffer $a2 =           number of characters to write | $v0 contains number of characters written (negative if error). *See           note below table* |
| close file                                                   | 16          | $a0 = file descriptor                                        |                                                              |
| exit2 (terminate with value)                                 | 17          | $a0 = termination result                                     | *See note below table*                                       |
| *Services 1 through 17 are compatible with the SPIM simulator,           other than Open File (13) as described in the Notes below the table.           Services 30 and higher are exclusive to MARS.* |             |                                                              |                                                              |
| time (system time)                                           | 30          |                                                              | $a0 = low order 32 bits of system time $a1 = high order 32 bits           of system time. *See note below table* |
| MIDI out                                                     | 31          | $a0 = pitch (0-127) $a1 = duration in milliseconds $a2 =           instrument (0-127) $a3 = volume (0-127) | Generate tone and return immediately. *See note below table* |
| sleep                                                        | 32          | $a0 = the length of time to sleep in milliseconds.           | Causes the MARS Java thread to sleep for (at least) the specified           number of milliseconds. This timing will not be precise, as the Java           implementation will add some overhead. |
| MIDI out synchronous                                         | 33          | $a0 = pitch (0-127) $a1 = duration in milliseconds $a2 =           instrument (0-127) $a3 = volume (0-127) | Generate tone and return upon tone completion. *See note below           table* |
| print integer in hexadecimal                                 | 34          | $a0 = integer to print                                       | Displayed value is 8 hexadecimal digits, left-padding with zeroes if           necessary. |
| print integer in binary                                      | 35          | $a0 = integer to print                                       | Displayed value is 32 bits, left-padding with zeroes if necessary. |
| print integer as unsigned                                    | 36          | $a0 = integer to print                                       | Displayed as unsigned decimal value.                         |
| (not used)                                                   | 37-39       |                                                              |                                                              |
| set seed                                                     | 40          | $a0 = i.d. of pseudorandom number generator (any int). $a1 = seed           for corresponding pseudorandom number generator. | No values are returned. Sets the seed of the corresponding           underlying Java pseudorandom number generator (`java.util.Random`).           *See note below table* |
| random int                                                   | 41          | $a0 = i.d. of pseudorandom number generator (any int).       | $a0 contains the next pseudorandom, uniformly distributed int value           from this random number generator's sequence. *See note below table* |
| random int range                                             | 42          | $a0 = i.d. of pseudorandom number generator (any int). $a1 =           upper bound of range of returned values. | $a0 contains pseudorandom, uniformly distributed int value in the           range 0 = [int] [upper bound], drawn from this random number           generator's sequence. *See note below table* |
| random float                                                 | 43          | $a0 = i.d. of pseudorandom number generator (any int).       | $f0 contains the next pseudorandom, uniformly distributed float           value in the range 0.0 = f 1.0 from this random number generator's           sequence. *See note below table* |
| random double                                                | 44          | $a0 = i.d. of pseudorandom number generator (any int).       | $f0 contains the next pseudorandom, uniformly distributed double           value in the range 0.0 = f 1.0 from this random number generator's           sequence. *See note below table* |
| (not used)                                                   | 45-49       |                                                              |                                                              |
| ConfirmDialog                                                | 50          | $a0 = address of null-terminated string that is the message to user | $a0 contains value of user-chosen option 0: Yes 1: No 2:           Cancel |
| InputDialogInt                                               | 51          | $a0 = address of null-terminated string that is the message to user | $a0 contains int read $a1 contains status value 0: OK status -1:           input data cannot be correctly parsed -2: Cancel was chosen -3:           OK was chosen but no data had been input into field |
| InputDialogFloat                                             | 52          | $a0 = address of null-terminated string that is the message to user | $f0 contains float read $a1 contains status value 0: OK status -1:           input data cannot be correctly parsed -2: Cancel was chosen -3:           OK was chosen but no data had been input into field |
| InputDialogDouble                                            | 53          | $a0 = address of null-terminated string that is the message to user | $f0 contains double read $a1 contains status value 0: OK status -1:           input data cannot be correctly parsed -2: Cancel was chosen -3:           OK was chosen but no data had been input into field |
| InputDialogString                                            | 54          | $a0 = address of null-terminated string that is the message to user $a1           = address of input buffer $a2 = maximum number of characters to           read | *See Service 8 note below table* $a1 contains status value 0:           OK status. Buffer contains the input string. -2: Cancel was           chosen. No change to buffer. -3: OK was chosen but no data had           been input into field. No change to buffer. -4: length of the           input string exceeded the specified maximum. Buffer contains the           maximum allowable input string plus a terminating null. |
| MessageDialog                                                | 55          | $a0 = address of null-terminated string that is the message to user $a1           = the type of message to be displayed: 0: error message,           indicated by Error icon           1: information message, indicated by Information icon           2: warning message, indicated by Warning icon           3: question message, indicated by Question icon           other: plain message (no icon displayed) | N/A                                                          |
| MessageDialogInt                                             | 56          | $a0 = address of null-terminated string that is an information-type           message to user $a1 = int value to display in string form after           the first string | N/A                                                          |
| MessageDialogFloat                                           | 57          | $a0 = address of null-terminated string that is an information-type           message to user $f12 = float value to display in string form           after the first string | N/A                                                          |
| MessageDialogDouble                                          | 58          | $a0 = address of null-terminated string that is an information-type           message to user $f12 = double value to display in string form           after the first string | N/A                                                          |
| MessageDialogString                                          | 59          | $a0 = address of null-terminated string that is an information-type           message to user $a1 = address of null-terminated string to           display after the first string | N/A                                                          |

Values of $v0 in commonly used syscall:

+ $v0 = 5：Read integer

+ $v0 = 1：Print integer
+ $v0 = 8：Read string

+ $v0 = 4：Print string
+ $v0 = 10：Exit the program

---

