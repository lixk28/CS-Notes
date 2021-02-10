# Algorithm Analysis

An **algorithm** is a clearly specified set of simple instructions to be followed to solve a problem.

算法是为求解一个问题需要遵循的、被清楚地指定的简单指令的集合。

## 1. Mathematical Background

Definition:

+ 如果存在正常数 $c$ 和 $N$，当  $n \geq N$  时，有 $T(n) \leq cf(n)$，则记为 $T(n) = \Omicron(f(n))$

+ 如果存在正常数 $c$ 和 $N$，当  $n \geq N$  时，有 $T(n) \geq cg(n)$，则记为 $T(n) = \Omega(g(n))$

+ $T(n) = \Theta(h(n))$ 当且仅当 $T(n) = \Omicron(h(n))$ 且 $T(n) = \Theta(h(n))$

+ 如果对任意的常数 $c$ ，存在 $N$，当 $n > N$ 时，有 $T(n) < cp(n)$，则记为 $T(n) = \omicron(p(n))$

  非正式的定义为：如果 $T(n) = \Omicron(p(n))$ 且 $T(n) \neq \Theta(p(n))$，则 $T(n) = \omicron(p(n))$

Explanation:

+ $T(n) = \Omicron(f(n))$：表示 T(n) 的增长率小于等于 f(n) 的增长率
+ $T(n) = \Omega(g(n))$：表示 T(n) 的增长率大于等于 f(n) 的增长率
+ $T(n) = \Theta(h(n))$：表示 T(n) 的增长率等于 f(n) 的增长率
+ $T(n) = \omicron(p(n))$：表示 T(n) 的增长率小于 f(n) 的增长率



