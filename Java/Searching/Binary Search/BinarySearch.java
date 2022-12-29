/*
    Binary Search implementation code in Java
    This is used to search an element in sorted array
    Time complexity : O(logn)
*/


public class BinarySearch {
    public static int search(int[] arr,int target){
        int start = 0;
        int end = arr.length-1;
        while (start <= end) {
            int mid = start+(end-start)/2;
            if(target == arr[mid])
                return mid; //Return the index of element if found in array
            if(arr[mid]<target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;  //Return -1 if element is not present in array
    }
    public static void main(String[] args) {
        int[] arr = {2,3,4,5,6,7,8,9,10,11,13,15,19,24,26,28};
        int target = 24;
        int foundAt = search(arr,target);
        if(foundAt==-1)
            System.out.println("Element not found");
        else
            System.out.println("Element found at "+foundAt);
    }
}
