Assuming that *T*1(*n*) = *O*(*f*1(*n*)), *T*2(*n*) = *O*(*f*2(*n*))，prove that
*T*(*n*) = *T*1(*n*) + *T*2(*n*) = *O*(*f*1(*n*)) + *O*(*f*2(*n*)) = *O*(max(*f*1(*n*), *f*2(*n*))).

$Proof:$

$因为T_1(n)是\Omicron(f_1(n))，所以存在c_1和N_1，使得当n>N_1时，有T_1(n) \leq c_1f_1(n)$

$同理，存在c_2和N_2，使得当n>N_2时，有T_2(n) \leq c_2f_2(n)$

$设c=c_1+c_2，N=max(N_1,N_2)，从而当n > N时，有$

$T(n) = T_1(n)+T_2(n) = \Omicron(f_1(n)) + \Omicron(f_2(n))$

​										  $\leq c_1f_1(n) + c_2f_2(n)$

​										  $ \leq (c_1+c_2)(max(f_1(n),f_2(n)))$

​										  $=c \times max(f_1(n),f_2(n))$

$所以存在c = c_1+c_2和N=max(N_1,N_2)，当n>N时，有T(n)=c \times max(f_1(n),f_2(n))$

$根据大\Omicron记号的定义可知T(n) = \Omicron(max(f_1(n),f_2(n))$

---

Suppose that *T*(*n*)=2*T*(*n*/2) + *n, T*(1) = 1. Prove that
*T*(*n*) = *O*(*n* log *n*) by induction.

$Proof:$

$归纳基：当n=2时，T(2)=2T(1)+2=2\times1+2=2log2+2=4log2$

​			  $因此，存在c\geq2(比如取c=3)，使得T(2) = 4log2 \leq c\times2log2，即T(2)=\Omicron(2log2)$

$归纳假设：假设对于所有的k \leq n时，T(k)=\Omicron(klogk)仍然成立$

​				 $则存在c和N，当k>N时，有T(k) \leq cklogk$

$归纳步：由于\frac{n}{2}<n，那么存在c_1和N，当n>N时，有$

​					$T(n)=2T(n/2)+n$

​				   		   $\leq 2 \times c_1 \frac{n}{2}log{\frac{n}{2}} + n$

​					          $=c_1n(logn-log2)+n$

​							  $=c_1nlogn-c_1nlog2+n$

​			 $因此，只要使-c_1nlog2+n \leq 0即c1\geq1，就有T(n)\leq c_1nlogn$

​			 $我们取c_2=max(c_1,1)，那么存在c\geq c_2和N，当n>N时，一定有T(n)\leq cnlogn，即T(n)=\Omicron(nlogn)$

$综上，有T(n)=\Omicron(nlogn)$



