/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package midterm;

/**
 *
 * @author talha
 */
public class Library
{

    String name;
    Books[] booksL = new Books[1000];

    public void libName(String x)
    {
        name = x;
    }
    public void bokName()
    {
        for (int i = 0; i < 1000; i++)
        {
            System.out.println();
        }
    }

    public String[] searchBooks(String x)
    {
        String[] array = new String[1000];
        int j = 0;
        for (int i = 0; i < booksL.length; i++)
        {
            if (booksL[i].title.equalsIgnoreCase(x))
            {
                array[j] = booksL[i].title;
                j++;
            }
        }
        return array;
    }
}
