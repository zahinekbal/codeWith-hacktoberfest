#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void selection_sort(int *arr,int n);

int main()
{
 int arr[SIZE];
 int *str;
 printf("Enter size of array : ");
 int n;
 scanf("%d",&n);
 printf("Enter elements of array : ");
 int i;
 for(i=0;i<n;i++)
 scanf("%d",&arr[i]);
 str = arr;
 selection_sort(str,n);
 return 0;
}

void selection_sort(int *arr,int n)
{
 int i,j,temp,k;
 for(i=0;i<n;i++)
  {
    k = i;
     for(j=i+1;j<n;j++)
      if(arr[j]<arr[k])
       k = j;
    temp = arr[i];
    arr[i] = arr[k];
    arr[k] = temp;
}

for(i=0;i<n;i++)
  printf("%d  ",arr[i]);
 printf("\n");
}
