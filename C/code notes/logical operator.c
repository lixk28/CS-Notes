#include<stdio.h>

int main()
{
	int num;
    printf("If U wanna enter case 1, enter 1\n");
    printf("If U wanna enter case 2, enter 2\n");
    scanf("%d",&num);
    
    if(num==1)
    {
	  int x=1,y=0,z=5;
	  int a=x&&y||z++;
	  printf("%d",z);
	}
	else
	{
	  int x=1,y=0,z=5;
	  int a=x&&y&&z++;
	  printf("%d",z);
	}  
	return 0;
}

