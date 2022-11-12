package Assignment4P1;

import java.util.*;  // Import the Scanner class

/**
 * @author talha
 * @Due Date = Feb 7, 2022
 * @Assignment 4
 */
public class Rect
{
    Scanner input = new Scanner(System.in);  // Create a Scanner object
    
    private static int len = 0;//intializes len
    private static int width = 0;//intializes width
    private static int[] coor =//intializes an array for the coordinates
    {
        0, 0
    };

    protected boolean isBiggerThan(Rect x)
    {
        if (x.getArea() < getArea())
        {
            return true;
        }
        return false;
    }

    protected void createRect()//creates the size of a rectangle and sets its coordinates if the user chooses
    {                          //gets nothing and returns nothing

        System.out.println("What would you like the len of the rectangle to be?");//text for user
        len = input.nextInt();//gets input from user
        System.out.println("What would you like the width of the rectangle to be?");//text for user
        width = input.nextInt();//gets input from user
        input.nextLine();//throws away the enter from the user
        System.out.println("Would you like to give coordinates to the rectangle? Yes/No");//text for user
        String choice = input.nextLine();  // Read user input

        if (choice.equals("yes") || choice.equals("Yes"))
        {
            System.out.println("To add coordinates please enter two numbers");//text for user
            coor[0] = input.nextInt();//gets input from user
            coor[1] = input.nextInt();//gets input from user
        }
        if (len == 0)//compares the variables and corrects them
        {
            len = 1;
        }
        if (width == 0)
        {
            width = 1;
        }

        if (len < 0)
        {
            len = len * (-1);
        }
        if (width < 0)
        {
            width = width * (-1);
        }

    }

    protected int getCircumf()//creates a method that gets the length and width and returns the circumference
    {
        int c;////intializes c
        c = 2 * (len + width);//calcualtes the values of the circumference
        return c;//returns c
    }

    protected int getArea()//creates a method that gets the length and width and returns the area of the rect
    {
        int c;//intializes len
        c = width * len;//calcualtes the area of the rect and saves it to c
        return c;//returns c
    }

    protected void move(int x, int y)//creates a function that modifies the original coor array to the 2 integers entered
    {
        coor[0] = x;//sets the first coor to x
        coor[1] = y;//sets the second coor to y
    }

    protected void changeSize(int n)//creates a fucntion sets the dimensions of the rectangle to n
    {
        len = n;//set len to n
        width = n;//set width to n
    }

    protected void print()//function to print out the dimensions of the rectangle
    {
        System.out.println("The coordinates of the rectangle is " + coor[0] + "," + coor[1]);//prints out the coordinates 
        System.out.println("The length of the rectangle is " + len + ", the width of the rectangle is " + width);//prints out the dimensions
        System.out.println("The area of the rectangle is " + getArea() + ". The circumference is " + getCircumf() + "\n");//prints the area and the circumference
    }
}
