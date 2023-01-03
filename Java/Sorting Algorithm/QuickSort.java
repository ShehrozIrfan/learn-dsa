//Quick Sort in java

public class QuickSort {
    int partition (int arr[], int start, int end)
    {
        //end element as the pivot element
        int pivot = arr[end]; 
        int i = (start - 1);

        for (int j = start; j <= end - 1; j++)
        {
            //if current element is smaller than pivot
            if (arr[j] < pivot)
            {
                //increment index of smaller element
                ++i;
                //swapping elements at i and j index
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
        return (i + 1);
    }

    //to implement quick sort
    void sort (int arr[], int start, int end)
    {
        if(start < end)
        {
            int p = partition(arr, start, end);
            sort(arr, start, p - 1);
            sort(arr, p + 1, end);
        }
    }

    //displaying the error
    void display(int arr[], int len)
    {
        int i;
        for (i = 0; i < len; i++)
        {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String args[])
    {
        QuickSort qs = new QuickSort();
        int arr[] = {23, 12, 87, 10, 11, 64};
        int len = arr.length;
        qs.sort(arr, 0, len - 1);
        System.out.println("Sorted Array: ");
        qs.display(arr, len);
    }
}