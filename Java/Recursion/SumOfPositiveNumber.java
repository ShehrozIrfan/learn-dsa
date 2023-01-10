//Recursion program to find Sum of n positive numbers in Java

package Java.Recursion;

public class SumOfPositiveNumber {
    public static int sum(int n) {
        if (n == 1) {
            return 1;
        } else {
            return n + sum(n-1);
        }
    }

    public static void main(String[] args) {
        int n = 5;
        int result = sum(n);
        System.out.println("Sum of the first " + n + " positive integers: " + result);
    }
}