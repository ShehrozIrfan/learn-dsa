//Recursion program to find sum of first n positive numbers

package Java.Recursion;

public class Sum_Of_Positive_Number {
    public static void main(String[] args)
    {
        int n = 10;
        int sum = 10;
        System.out.println("First " + n + " Numbers: ");

        for (int i = 1; i <= n; i++)
        {
            System.out.println(i + " ");
            sum += i;
        }

        System.out.println();
        System.out.println("Sum of first " + n + " Positive Numbers: " + sum);
    }
}