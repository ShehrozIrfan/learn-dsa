//Insertion Sort in Java

public class InsertionSort {
    void sort(int arr[])
    {
        //finding length of the array
        int len = arr.length;
        for (int i = 1; i < len; ++i)
        {
            int key = arr[i];
            int j = i - 1;

            /*moving the elememnts of the array that are greater than 
            key to a posiiton ahead of their current position */
            while (j >= 0 && arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
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
        InsertionSort is = new InsertionSort();
        int arr[] = {23, 12, 87, 10, 11, 64};
        is.sort(arr);
        System.out.println("Sorted Array: ");
        is.display(arr);
    }
}