#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int a[2000], b[2000];

void main(){

    int i,j,low,high,n;
    double f;
    clock_t s,e;
    printf("Enter n ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
        a[i]=rand()%10000;

    printf("The elements are: ");
        for(i=0; i<n; i++)
            printf("%d \t", a[i]);

        low = 0, high = n-1;

        s=clock();
        for(i=0; i<100000; i++)
            mergesort(low,high);
        e=clock();
       // f=(double)(e-s)/sysconf(_SC_CLK_TCK);

        printf("\n\nThe sorted elements: ");
        for(i=0; i<n; i++)
            printf("%d \t", a[i]);

       // printf("Time taken: %lf", (f)/10000);
    }

    mergesort(int low, int high)
    {
        int mid;
        if(low<high)
        {
            mid = (low+high)/2;
            mergesort(low,mid);
            mergesort(mid+1,high);
            merge(low,mid,high);
        }


    }

    merge(int low, int mid, int high){
        int i,j,k,h;
        h=low; i=low; j=mid+1;
        while(h<=mid && j<=high)
        {
            if(a[h] <= a[j])
               {

                b[i]=a[h]; h=h+1;}
            else{
                b[i]=a[j]; j=j+1;
            }i=i+1;
        }


    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            b[i]= a[k];
            i=i+1;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            b[i]=a[k];
            i=i+1;
        }
    }
    for(k=low; k<=high; k++)
        a[k]=b[k];
    }
