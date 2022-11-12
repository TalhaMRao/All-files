/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package midterm;

import java.util.Scanner;

/**
 *
 * @author Talha Rao 1008904
 */
public class Books
{
    static int counter = 1;
    String title;
    String[][] author = new String[10][2];
    final int id = counter;
    int countA = 0;
    
    public void addAuthors()
    {
        Author a = new Author();
        author[countA][0] = a.fN;
        author[countA][1] = a.lN;
        countA++;
    }

    public void title(String x)
    {
        if (x.length() < 5 || x.length() > 50)
        {
            x = "No Title";
        } else
        {
            this.title = x;
        }
        counter++;
    }

}
