#include <stdio.h> 
  
 void main(){ 
     int i,temp,j,n,a,smallest,counter=0, arr[100]; 
     printf("Enter the size of list: "); 
     scanf("%d",&n); 
     printf("Enter %d values: ",n); 
     for(a=0;a<n;a++){ 
         scanf("%d",&arr[a]); 
     } 
     printf("\nList before sorting is: "); 
     for(a=0;a<n;a++){ 
         printf("%d ",arr[a]); 
     } 
     counter=counter+1; 
     for(i=0;i<=n-2;i++){ 
         counter=counter+1; 
         smallest=i; 
         for(j=i+1;j<=n-1;j++){ 
             counter=counter+1; 
             if(arr[j]<arr[smallest]){ 
                     counter=counter+1; 
                     smallest=j; 
             } 
     } 
         counter=counter+1; 
         temp=arr[i]; 
         arr[i]=arr[smallest]; 
         arr[smallest]=temp; 
 } 
 printf("\nList after sorting is: "); 
 for(a=0;a<n;a++){ 
         printf("%d ",arr[a]); 
     } 
   printf("\nTime Complexity = %d",counter); 
 }