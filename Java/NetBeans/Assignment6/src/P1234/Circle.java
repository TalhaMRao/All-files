package P1234;

import java.util.*;

/**
 * @author talha
 * P1 & 3
 * due Monday 8 am
 */
public class Circle
{

    int radius;//creates variable

    Circle[] decompose()//makes decompose method
    {
        Circle[] circleF;//craetes a circle 
        circleF = new Circle[100];//creates 100 of that variable
        int j = 0;//intiailzes a vairable as a counter set to 0
        for (int i = 2; i <= radius; i++)//for loop loops to the size of the radius
        {
            while (radius % i == 0)//while loop iterates as long as radius is divisible by i
            {
                circleF[j] = new Circle();//craetse a new circle as circleF
                circleF[j].radius = i;//sets its radius to i
                radius /= i;//divides radius by i
                j++;//iterates counter
            }
        }
        return circleF;//returns the circle array
    }

    void add(Circle x)//method to add circle radius
    {
        radius += x.radius;//radius adds with x.radius
    }

    void addAll(Circle[] x)//gets the circle array
    {
        for (int i = 0; i < x.length; i++)//loops till the lenght of the array
        {
            radius += x[i].radius;//adds radius to the x.radius for each element
        }
    }
}
