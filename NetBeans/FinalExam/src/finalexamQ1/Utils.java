/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package finalexamQ1;

/**
 *
 * @author talha
 */
public class Utils
{

    static void zoom(Zoomable[] z)
    {
        for (int i = 0; i < z.length; i++)
        {
            if (i % 2 == 0)
            {
                z[i].zoomIn();
            } else
            {
                z[i].zoomOut();
            }
        }
    }
}
