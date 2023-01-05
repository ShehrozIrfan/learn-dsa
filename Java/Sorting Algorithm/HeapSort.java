//Hear Sort in Java

public class HeapSort {
    public void sort(int arr[])
    {
        int len = arr.length;

        //building the heap
        for(int i = len / 2 - 1; i >= 0; i--)
        {
            heapify(arr, len, i);
        }

        //extracting element from heap
        for (int i = len - 1; i > 0; i--)
        {
            //moving current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            //calling maximum heapify on reduced heap
            heapify(arr, i, 0);
        }
    }
    
    void heapify(int arr[], int len, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        //if left child is larger than root
        if (l < len && arr[l] > arr[largest])
        {
            largest = l;
        }
        
        //if right child is larger than largest 
        if (r < len && arr[r] > arr[largest])
        {
            largest = r;
        } 

        //if largest is not the root
        if (largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, len, largest);
        }
    }

    //displaying the array
    static void display(int arr[])
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
        HeapSort hs = new HeapSort();
        int arr[] = {23, 12, 87, 10, 11, 64};
        int len = arr.length;
        hs.sort(arr);
        System.out.println("Sorted Array: ");
        hs.display(arr);
    }
}