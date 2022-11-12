package P1234;

import java.util.Random;//imports random number generator

/**
 * @author talha
 * P2
 * due Monday 8 am
 */
public class main
{
    public static void main(String[] args)
    {
        Circle[] circle;//makes a circle object
        circle = new Circle[100];//intiates 100 circles 
        for (int i = 0; i < 100; i++)//for loop iterates to 100
        {
            circle[i] = new Circle();//new circle object
            circle[i].radius = i + 1;//sets radius to i + 1
        }
        
        Random random = new Random();//new random number generator
        int r = random.nextInt(1001 - 10) + 10;//random number bounds
        Circle circle1 = new Circle();//new circle
        circle1.radius = r;//sets radius to r
        System.out.println(circle1.radius);//prints radius
        circle1.addAll(circle);//calls the add all method
        System.out.println(circle1.radius);//prints new radius
    }
}
