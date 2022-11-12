/**
 * @author talha
 * @Due Date = Jan 24, 2022
 * @Assignment 3
 */
package Assignment3P1;

/**
 *
 * @author talha
 */
public class Rect//a class for the rectangle
{

    int len = 0;//intializes len
    int width = 0;//intializes width
    int[] coor =//intializes an array for the coordinates
    {
        0, 0
    };

    int getCircumf(int l, int w)//creates a method that gets the length and width and returns the circumference
    {
        int c;////intializes c
        c = 2 * (l + w);//calcualtes the values of the circumference
        return c;//returns c
    }

    int getArea(int l, int w)//creates a method that gets the length and width and returns the area of the rect
    {
        int c;//intializes len
        c = w * l;//calcualtes the area of the rect and saves it to c
        return c;//returns c
    }

    void move(int x, int y)//creates a function that modifies the original coor array to the 2 integers entered
    {
        coor[0] = x;//sets the first coor to x
        coor[1] = y;//sets the second coor to y
    }

    void changeSize(int n)//creates a fucntion sets the dimensions of the rectangle to n
    {
        len = n;//set len to n
        width = n;//set width to n
    }

    void print()//function to print out the dimensions of the rectangle
    {
        System.out.println("The coordinates of the rectangle is " + coor[0] + "," + coor[1]);//prints out the coordinates 
        System.out.println("The length of the rectangle is " + len + ", the width of the rectangle is " + width);//prints out the dimensions
        System.out.println("The area of the rectangle is " + getArea(len, width) + ". The circumference is " + getCircumf(len, width)+"\n");//prints the area and the circumference
    }
}
