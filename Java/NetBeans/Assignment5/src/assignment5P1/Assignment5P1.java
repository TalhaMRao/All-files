package assignment5P1;

import java.util.*;//imports scanner

/**
 *
 * @author talha
 * P1
 * due Monday 8 am
 */
public class Assignment5P1
{

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);//intiates scanner
        System.out.println("Enter the string that you would like analyszed");//prompt for user
        String sIn = input.nextLine();//gets input from user

        int j;//counter
        for (int i = 0; i < sIn.length(); i++)//for loop to loop through the length of the string array
        {
            j = 1;//sets counter to 1 at the beginning every time
            while ((i + 1 < sIn.length()) && (sIn.charAt(i) == sIn.charAt(i + 1)))//loop that makes sure the index dosent exceed the lenght of the string and checks if the next char and the current char are the same
            {
                i++;//increment i
                j++;//increment j
            }
            if (j > 1)//if j is 1 than it dosent need to be printed
            {
                System.out.print(sIn.charAt(i) + "" + j + "");//print the letter and J
            } else
            {
                System.out.print(sIn.charAt(i));//only prints the letter
            }
        }
        System.out.print("\n");//adds a new line to make it look good
    }
}
