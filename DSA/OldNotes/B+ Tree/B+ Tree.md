# B+ Tree

A B+ tree of order M is an M-ary tree with the following properties:

+ The data items are stored at leaves
+ The root is either a leaf or has between $2$ and $M$ children
+ All non-leaf nodes (except the root) have between $\lceil \frac{M}{2} \rceil$ and $M$ children
+ **The non-leaf nodes store up to $M-1$ keys** to guide the searching, key i represents the smallest key in subtree i+1（非叶子节点最多有M-1个关键字）
+ **All leaves are at the same depth and have between $\lceil \frac{L}{2} \rceil$ and $L$ data items**, for some $L$（叶子节点存储的数据项个数满足 $\lceil \frac{L}{2} \rceil \leq \#data \ items \leq L$）

---

**Insertion**:
If leaf x contains < L keys, then insert k into x at thecorrect position in node x
If leaf x is already full, which is x contains L keys. Split x:

1. Cut x off from its parent.
2. Insert k into x, pretending x has space for k. Now x has L+1 keys
3. After inserting k, split x into 2 new leaves x~L~ and x~R~ **(the split position is $\lceil \frac{L}{2} \rceil$)**, with x~L~ containing the $\lceil \frac{L+1}{2} \rceil$ smallest keys, and x~R~ containing the remaining $\lfloor \frac{L+1}{2} \rfloor$ keys. 
4. Find the minimum key in x~R~, and let it be the parent of x~L~ and x~R~, then insert it into the old parent of x
5. After inserting, if the parent of x~L~ and x~R~ now has M keys, split it. 

How to split an internal node:
To inset a key k into a full internal node x:

1. Cut off x from its parent.
2. Insert k and its left and right child pointers into x, pretending there is space. Now x has M keys.
3. Split x into 2 new internal nodes x~L~and x~R~, with x~L~ containing the $\lceil \frac{M}{2} \rceil - 1$ smallest keys, and x~R~ containing the $\lfloor \frac{M}{2} \rfloor$ largest keys. Note that the $\lceil \frac{M}{2} \rceil$~th~ key m is not placed in x~L~ or x~R~.
4. Make m the parent of x~L~ and x~R~, and insert m together with its child pointers into the old parent of x. If the spilt internal node x (which means x is root) does not have a parent, then create a new root containing the key m and its two children.

Splitting will continue as long as we encounter full internal nodes.

---

**Deletion**:

To delete a key target k, we can find it at a leaf x and an internal node, or just at a leaf x:

1. If we find k at a leaf x and an internal node y, we delete k in leaf x, and then replace k in node y with the smallest key in x.

2. After deleting k in leaf x, if x has less than $\lceil \frac{L}{2} \rceil$ keys, we consider the siblings of x:

   + If the right sibling of x contains more than $\lceil \frac{L}{2} \rceil$ keys, move the smallest key to the correct position of x, then set the key in the parent of x and its right sibling.
   + If the left sibling of x contains more than $\lceil \frac{L}{2} \rceil$ keys, move the largest key to the correct position of x, then set the key in the parent of x and its left sibling.

   + If the right and left sibings of x both contain $\lceil \frac{L}{2} \rceil$ keys (cannot be less, because $\lceil \frac{L}{2} \rceil$ is the smallest number of keys in a node), we cannot borrow any keys, instead we merge them. If the right or left sibling of x contains $\lceil \frac{L}{2} \rceil$ keys, merge it and x, then remove the pointer to leaf x at parent, then delete the separating key between it and x from the parent.

3. After deleting the separating key in the parent node u, and then u has less than $\lceil \frac{M}{2} \rceil - 1$.

   + If u is root, and after removing u is empty, then remove u and make its child the new root.
   + If the right or left sibling v of u has $\lceil \frac{M}{2} \rceil$ keys or more, move the separating key between u and v in the parent of u and v down to u, make the leftmost/rightmost child of v the rightmost/leftmost child of u, move the leftmost/rightmost key in v to become the separating key between u and v in the parent of u and v.
   + If both the siblings v of u contains exactly $\lceil \frac{M}{2} \rceil - 1$ keys, move the separating key between u and v in the parent of u and v down to u, move the keys and child pointers in u to v, remove the pointer to u at parent.

   

   

   

   

   