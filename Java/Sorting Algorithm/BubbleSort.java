//Bubble Sort in Java

public class BubbleSort {
    void bubbleSort(int arr[])
    {
        //finding length of the array
        int len = arr.length;
        for (int i = 0; i < len-1; i++)
        {
            for (int j = 0; j < len-i-1; j++)
            {
                if (arr[j] > arr[j+1]) 
                {
                    //swap arr[j+1] and arr[j]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
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
        BubbleSort bs = new BubbleSort();
        int arr[] = {23, 12, 87, 10, 11, 64};
        bs.bubbleSort(arr);
        System.out.println("Sorted Array: ");
        bs.display(arr);
    }
}
