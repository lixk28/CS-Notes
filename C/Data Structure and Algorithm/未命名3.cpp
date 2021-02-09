
#include<stdio.h>  
#include<stdlib.h>  
/* 
*已知二叉树的先序和中序遍历，求后序遍历  
*/  
int pos[1000];  
int n;  
int flag=0;  
int locationInMid(int mid[],int ms,int me,int h)  
{  
    int i;  
    for(i=ms;i<=me;++i)  
    {  
        if(mid[i]==h)  
            return i;  
    }  
    return -1;  
}  
void postOrder(int pre[],int ps,int pe,int mid[],int ms,int me) //有待改进的地方，函数的参数可以简化，因为数组的地址是0号元素的地址，知道头结点在mid中的位置后，左右子树的个数即可得到   
{  
    int hm=0,cl=0,cr=0;  
    pos[--n]=pre[ps];  
    //--n;  
    hm=locationInMid(mid,ms,me,pre[ps]);  
    if(hm==-1)  
    {  
    //  printf("No\n");  
        flag=-1;  
        return ;  
    }  
    else  
    {  
        cl=hm-ms;  
        cr=me-hm;  
        if(cr>0)  
            postOrder(pre,ps+cl+1,pe,mid,hm+1,me);  
        if(cl>0)  
            postOrder(pre,ps+1,ps+cl,mid,ms,hm-1);  
    }  
    return ;  
}  
int  main()  
{  
    int pre[1000];  
    int mid[1000];  
    int i,t;  
    while(scanf("%d",&n)!=EOF)  
    {  
        t=n;  
        for(i=0;i<n;++i)  
            scanf("%d",&pre[i]);  
        for(i=0;i<n;++i)  
            scanf("%d",&mid[i]);  
        postOrder(pre,0,n-1,mid,0,n-1);  
        if(flag==-1)  
        {  
            printf("No\n");  
            flag=0;  
        }  
        else  
        {  
            for(i=0;i<t;++i)//注意：n是全局变量所以上一个语句执行完之后，n的值已经不是原来的n了，所以要用t保存n最初的值   
                printf("%d ",pos[i]);  
            printf("\n");  
        }  
    }  
    return 0;  
}  
