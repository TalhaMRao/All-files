package Assignment4P3;

import java.util.*;  // Import the Scanner class

/**
 * @author talha
 * @Due Date = Feb 7, 2022
 * @Assignment 4
 */
public class Rect
{
    Scanner input = new Scanner(System.in);  // Create a Scanner object
    
    private static int len = 0;
    private static int width = 0;

    private static int[] coorL =//intializes an array for the coordinates
    {
        0, 0
    };
    private static int[] coorR =//intializes an array for the coordinates
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

    protected void createRect()
    {
        System.out.println("What would like the top left coordinate of the rectangle to be? Enter x then y");
        coorL[0] = input.nextInt();
        coorL[1] = input.nextInt();

        System.out.println("What would like the bottom right coordinate of the rectangle to be? Enter x then y");
        coorR[0] = input.nextInt();
        coorR[1] = input.nextInt();

        len = coorR[1] - coorL[1];
        width = coorR[0] - coorL[0];

        if (len == 0)
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
        coorL[0] = x;//sets the first coor to x
        coorL[1] = y;//sets the second coor to y
        
        coorR[1] = coorL[1] + len;
        coorR[0] = coorL[0] + width;
    }

    protected void changeSize(int n)//creates a fucntion sets the dimensions of the rectangle to n
    {
        len = n;//set len to n
        width = n;//set width to n
    }

    protected void print()//function to print out the dimensions of the rectangle
    {
        System.out.println("The length of the rectangle is " + len + ", the width of the rectangle is " + width);//prints out the dimensions
        System.out.println("The area of the rectangle is " + getArea() + ". The circumference is " + getCircumf() + "\n");//prints the area and the circumference
    }
}
