/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package finalexamQ1;

/**
 *
 * @author talha
 */
public class Circle extends Shape
{

    double radius;

    Circle(double x, double pos)
    {
        radius = x;
        position = pos;
    }

    @Override
    public void zoomIn()
    {
        radius = radius * 2;
    }

    @Override
    public void zoomOut()
    {
        if (0 == radius / 2)
        {
            throw new IllegalZoomException();
        }
        radius = radius / 2;
    }
}
