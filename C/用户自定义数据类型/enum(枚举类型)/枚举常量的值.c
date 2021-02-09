#include<stdio.h>

int main()
{
	enum Weekday1{mon1,tue1,wed1,thu1,fri1,sat1,sun1};
	printf("%d ",mon1);
	printf("%d ",tue1);
	printf("%d ",wed1);
	printf("%d ",thu1);
	printf("%d ",fri1);
	printf("%d ",sat1);
	printf("%d\n\n",sun1);
	
	enum Weekday2{mon2=1,tue2,wed2,thu2,fri2,sat2,sun2};
	printf("%d ",mon2);
	printf("%d ",tue2);
	printf("%d ",wed2);
	printf("%d ",thu2);
	printf("%d ",fri2);
	printf("%d ",sat2);
	printf("%d\n\n",sun2);
	
	enum Weekday3{mon3=1,tue3=7,wed3,thu3,fri3,sat3,sun3};
	printf("%d ",mon3);
	printf("%d ",tue3);
	printf("%d ",wed3);
	printf("%d ",thu3);
	printf("%d ",fri3);
	printf("%d ",sat3);
	printf("%d\n\n",sun3);
	
	enum Weekday4{mon4=1,tue4,wed4,thu4=7,fri4,sat4,sun4};
	printf("%d ",mon4);
	printf("%d ",tue4);
	printf("%d ",wed4);
	printf("%d ",thu4);
	printf("%d ",fri4);
	printf("%d ",sat4);
	printf("%d\n\n",sun4);
	
	enum Weekday5{mon5,tue5,wed5,thu5=7,fri5,sat5,sun5};
	printf("%d ",mon5);
	printf("%d ",tue5);
	printf("%d ",wed5);
	printf("%d ",thu5);
	printf("%d ",fri5);
	printf("%d ",sat5);
	printf("%d\n",sun5);
	
	return 0;
}
