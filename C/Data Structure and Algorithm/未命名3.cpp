
#include<stdio.h>  
#include<stdlib.h>  
/* 
*��֪������������������������������  
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
void postOrder(int pre[],int ps,int pe,int mid[],int ms,int me) //�д��Ľ��ĵط��������Ĳ������Լ򻯣���Ϊ����ĵ�ַ��0��Ԫ�صĵ�ַ��֪��ͷ�����mid�е�λ�ú����������ĸ������ɵõ�   
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
            for(i=0;i<t;++i)//ע�⣺n��ȫ�ֱ���������һ�����ִ����֮��n��ֵ�Ѿ�����ԭ����n�ˣ�����Ҫ��t����n�����ֵ   
                printf("%d ",pos[i]);  
            printf("\n");  
        }  
    }  
    return 0;  
}  
