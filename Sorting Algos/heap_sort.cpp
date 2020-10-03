 #include<stdio.h>

int n;

void build_max_heap(int arr[]);
void max_heapify(int arr[],int i);
void heap_sort(int arr[]);

int main()
{
	int h;
	printf("Enter number of nodes in array : ");
	scanf("%d",&h);
	n = h;
	int arr[h+1];
	int i;
	for(i=1;i<=h;i++)
	scanf("%d",&arr[i]);
    heap_sort(arr);
	for(i=1;i<=h;i++)
	printf("%d ",arr[i]);
	return 0;
}

void heap_sort(int arr[])
{
	build_max_heap(arr);
	while(n>=2)
	{
		int temp = arr[1];
		arr[1] = arr[n];
		arr[n] = temp;
		n--;
		max_heapify(arr,1);
	}
}

void build_max_heap(int arr[])
{
	int i = n/2;
	while(i>=1)
	{
		max_heapify(arr,i);
		i--;
	}
}

void max_heapify(int arr[],int i)
{
	int l = 2*i;
	int r = l+1;
	int largest = i;
	if(l<=n && arr[l]>arr[largest])
	largest = l;
	if(r<=n && arr[r]>arr[largest])
	largest = r;
	if(largest!=i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr,largest);
	}
}
