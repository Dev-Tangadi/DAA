#include<stdio.h>

int n,x,a[100],b,m,e;
int counter=0;

int bst(int x,int b,int e)
   {
    m=(b+e)/2;
    if(e>=b)
      {
        if(x==a[m])
        {
            counter=counter+1;
            return m;
        }
        else if(x>a[m])
       {
            counter=counter+1;
            return bst(x,m+1,e);
        }
        else
        {
            counter=counter+1;
            return bst(x,b,m-1);
        }
    }
    return -1;
}

void main()
  {
    int i,result;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    printf("Enter Array Elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter Element to be Searched: ");
    scanf("%d",&x);
    b = 0;
    e = n;
    result = bst(x,b,e);
    if(result==-1)
   {
        printf("\nElement not found");
    }
    else
    {
        printf("\nElement found at index %d ",result);
    }
    printf("\nTime Complexity = %d",counter);
}
