//千万不要犯这种低级错误，又很难debug，写的时候一定要注意细心！！！ 

/* The firse program
#include<stdio.h>

int main() 
{
	int x;
	scanf("%d",&x);
	if(x==1)      // this expression is true only when x=1
	  x=x+1;
	else
	  x=x-1;
	printf("%d",x);
                
    return 0;
}
*/
 
/* The second program
#include<stdio.h>

int main() 
{
	int x;
	scanf("%d",&x);
	if(x=1)        // this expression is always true x=1为非0值  所以为真 
	  x=x+1;
	else
	  x=x-1;
	printf("%d",x);  // the final result is always (x+1)
	
	return 0;
}
*/ 
            
/* The third program
#include<stdio.h> 

int main()
{
	int x=0;
	if(x=0)
	  printf("It's zero.");
	else
	  printf("It's not zero.");
	  
	return 0;
}
*/
