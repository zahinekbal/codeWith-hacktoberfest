#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void insertion_sort(int *arr,int n);


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
 insertion_sort(str,n);

 return 0;
}

void insertion_sort(int *arr,int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
   {
     temp = arr[i];
     for(j=i-1;j>=0 && temp<arr[j];j--)
       arr[j+1] = arr[j];
    arr[j+1] = temp;
}

for(i=0;i<n;i++)
  printf("%d  ",arr[i]);
 printf("\n");
}
=
