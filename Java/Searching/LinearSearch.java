/*
*   Java program for linear search
*   It doesn't require array to be sorted
*   Running time complexity is O(N) where N is size of array
*/
public class LinearSearch {
    public static int search(int[] arr,int target){
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]==target)
                return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {2,1,4,6,3,10,15,9,7};
        int target = 10;
        System.out.println(search(arr,target));
    }
}
