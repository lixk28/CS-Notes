# Queue 队列

queue ADT：先进先出 FIFO

基本操作：入队、出队 enqueue、dequeue

设置back和front两个指示器（或叫head和tail）

back指向当前队尾，front指向当前队头

---

学习STL中的queue

---

利用循环数组(circular array)实现队列

length是定义的静态数组的长度

front = (front + 1) % length   //dequeue后对指示器的操作

back = (back + 1) % length   //enqueue后对指示器的操作

当back = front + 1时队空

当front = back + 1时队满

当back = front时队列只有一个元素

---

