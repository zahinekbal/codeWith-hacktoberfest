/******************************************************************************
QUICK SORT (Java)

Test case - 1:

Input:
5
10 22 78 91 38

Ouput:
10 22 38 78 91
-------------------------------------------
Test case - 2:

Input:
10
9 76 229 20 63 92 38 19 71 91

Ouput:
9 19 20 38 63 71 76 91 92 229
*******************************************************************************/
import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the size of the array and the array from console
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Call the quick sort function
        quickSort(arr, 0, n - 1);

        // Print the sorted array
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");

        sc.close();
    }

    /**
     * The method that sorts the array using QuickSort algorithm
     * 
     * @param arr  The array that is to be sorted
     * @param low  Starting index
     * @param high Ending index
     */
    private static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // PI is partitioning index, arr[pi] is now at right place
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    /**
     * This function takes last element as pivot an places the pivot element at its
     * right place. It also places smaller elements on the left of this pivot
     * element It also places greater elements on the right of this pivot element
     * 
     * @param arr
     * @param low
     * @param high
     * @return
     */
    private static int partition(int[] arr, int low, int high) {

        // Pivot is the element that needs to be placed in the right position
        int pivot = arr[high];

        // counter is the index of smaller element
        int counter = (low - 1);
        for (int i = low; i < high; i++) {

            // If current element is smaller than pivot
            if (arr[i] < pivot) {
                // Increment index of smaller element
                counter++;

                // Swap the smaller element and current element
                int temp = arr[counter];
                arr[counter] = arr[i];
                arr[i] = temp;
            }
        }

        // Swap the last element
        int temp = arr[counter + 1];
        arr[counter + 1] = arr[high];
        arr[high] = temp;

        // return the index of element sorted
        return counter + 1;
    }
}
