# Number Representation

计算机中数字是以二进制形式存储的，只有0和1

数的表示要解决的问题：

+ 数的符号：正数、负数、零
+ 数的形态：整数、小数、小数点的性质

---

## Ecoding 信息的表示

Encoding = Assign representation to information

Fixed-Size Codes 位数相同的编码

Unicode 统一码



some Bit Tricks（一些技巧）

1. Memory the first 10 powers of 2
   + 2^0^ = 1
   + 2^1^ = 2
   + 2^2^ = 4
   + 2^3^ = 8
   + 2^4^ = 16
   + 2^5^ = 32
   + 2^6^ = 64
   + 2^7^ = 128
   + 2^8^ = 256
   + 2^9^ = 512
   + 2^10^ = 1024
2. Memory the prefixes for powers of 2 that are multiplies of 10（2的10的倍数幂）
   + 2^10^ = Kilo（1024）
   + 2^20^ = Mega（1024$\times$1024）
   + 2^30^ = Giga（1024$\times$1024$\times$1024）
   + 2^40^ = Tera（1024$\times$1024$\times$1024$\times$1024）
   + 2^50^ = Peta（1024$\times$1024$\times$1024$\times$1024$\times$1024）
   + 2^60^ = Exa（1024$\times$1024$\times$1024$\times$1024$\times$1024$\times$1024）

