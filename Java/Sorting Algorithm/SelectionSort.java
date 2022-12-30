//Selection Sort in Java

public class SelectionSort {
    void sort(int arr[])
    {
        //finding length of array
        int len = arr.length;
        for (int i = 0; i < len; i++)
        {
            //finding the smallest element in the array
            int min = i;
            for (int j = i+1; j < len; j++)
            {
                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }

            //swapping the found element with the first element
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    //displaying the array
    void display(int arr[])
    {
        int len = arr.length;
        for (int i = 0; i < len; ++i)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[])
    {
        SelectionSort ss = new SelectionSort();
        int arr[] = {23, 12, 87, 10, 11, 64};
        ss.sort(arr);
        System.out.println("Sorted Array: ");
        ss.display(arr);
    }
}