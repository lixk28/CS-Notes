/* initialization from incompatible pointer type */
// int a[3][4]

// int *p=a[0]  right
// int *p=a   wrong

// int (*p)[4]=a right
// int (*p)[4]=a[0] wrong
