//Recursive function to find power of a number in Java
package Recursion;

public class Power {

    //function to calculate power
    static int power(int num, int pow)
    {
        if (pow == 0)
        {
            return 1;
        }
        else
        {
            return num * power(num, pow - 1);
        }
    }   

    public static void main(String args[])
    {
        int num = 2;
        int pow = 8;

        System.out.println(power(num, pow));
    }
}