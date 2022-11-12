package Assignment2P4;

import java.util.Scanner;

/**
 * @author talha
 * @Due Date = Jan 24, 2022
 * @Assignment 2
 */
public class Assignment2P4
{

    public static void main(String[] args)//main
    {
        Scanner input = new Scanner(System.in);//creates a variable for scanner
        System.out.println("The program will add every number you enter until you enter 0");//prints text
        int n = 0, i = 0;//initializes variables
        do//always does this line
        {
            System.out.println("The current sum is " + n);//prints text out
            i = input.nextInt();//reads users input
            n = n + i;//adds i to n
        } while (i != 0);//while loop condition, the while loop loops the do statement
        System.out.println("The final sum is " + n);//prints text out for user
    }

}
