/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package P3;

/**
 *
 * @author talha
 */
public class Utility
{

    public Object max(Comparable[] x)
    {
        Object temp = x[0];
        for (int i = 0; i < x.length; i++)
        {
            if (x[i].compareTo(temp) == 1)
            {
                temp = x[i];
            }
        }
        return temp;
    }

    public Object min(Comparable[] x)
    {
        Object temp = x[0];
        for (int i = 0; i < x.length; i++)
        {
            if (x[i].compareTo(temp) == -1)
            {
                temp = x[i];
            }
        }
        return temp;
    }
}
