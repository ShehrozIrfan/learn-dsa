//Recursive function to find Sum of square of first n positive numbers

package Recursion;

public class SumOfSquareOfPositiveNumbers {
    public static int sumSquares(int n) {
        if (n == 1) {
            return 1;
        }
        return (n * n) + sumSquares(n - 1);
    }
    
    public static void main(String args[])
    {
        int n = 5;
        System.out.println("Sum of square of First " + n + " positive numbers: ");
        System.out.println(sumSquares(n));
    }
}