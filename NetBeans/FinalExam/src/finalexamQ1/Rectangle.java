/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package finalexamQ1;

/**
 *
 * @author talha
 */
public class Rectangle extends Shape
{

    double length, width;

    Rectangle(double x, double y, double pos)
    {
        length = x;
        width = y;
        position = pos;

    }

    @Override
    public void zoomIn()
    {
        length = length * 2;
        width = width * 2;
    }

    @Override
    public void zoomOut()
    {
        if (0 == length / 2 || 0 == width / 2)
        {
            throw new IllegalZoomException();
        }
        length = length / 2;
        width = width / 2;
    }
}
