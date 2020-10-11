class SelectionSort
{
    void func_SelectionSort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
        {
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[min_idx] > arr[j])
                    min_idx = j;

            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String args[])
    {
        int arr[] = {2,1,3,5,4};
        new SelectionSort().func_SelectionSort(arr);
        for (int i=0; i<arr.length; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
}