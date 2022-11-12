/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package P12;

import java.lang.Comparable;

/**
 * @author Talha Rao
 * @due March 28, 2022
 * @assignment Assignment 8
 */
public class Circle implements Comparable<Circle>
{

    int radius;
    int circumference;

    Circle(int radius, int circumference)
    {
        this.radius = radius;
        this.circumference = circumference;
    }

    public int compareTo(Circle cir)
    {
        if (radius == cir.radius)
        {
            return 0;
        } else if (radius < cir.radius)
        {
            return -1;
        }
        else
            return +1;
    }
}
