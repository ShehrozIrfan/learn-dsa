import java.util.Arrays;

public class CountingSort {
    public static void countingSort(int[] array) {
        // Find the minimum and maximum values in the array
        int max = findMax(array);
        int min = findMin(array);

        // Calculate the range of values
        int range = max - min + 1;

        // Create an array to store the count of each value
        int[] count = new int[range];

        // Create an output array
        int[] output = new int[array.length];

        // Count the frequency of each element
        for (int value : array) {
            count[value - min]++;
        }

        // Modify the count array to store the final position of each element
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array based on the count array
        for (int i = array.length - 1; i >= 0; i--) {
            output[count[array[i] - min] - 1] = array[i];
            count[array[i] - min]--;
        }

        // Copy the sorted elements back to the original array
        for (int i = 0; i < array.length; i++) {
            array[i] = output[i];
        }
    }

    // Function to find the maximum value in an array
    public static int findMax(int[] array) {
        int max = array[0];
        for (int value : array) {
            if (value > max) {
                max = value;
            }
        }
        return max;
    }

    // Function to find the minimum value in an array
    public static int findMin(int[] array) {
        int min = array[0];
        for (int value : array) {
            if (value < min) {
                min = value;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        int[] arr = {4, 2, 2, 8, 3, 3, 1};

        System.out.println("Original Array: " + Arrays.toString(arr));

        countingSort(arr);

        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
}
