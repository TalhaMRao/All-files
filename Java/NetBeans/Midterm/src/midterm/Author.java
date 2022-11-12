/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package midterm;

import java.util.Scanner;

/**
 *
 * @author talha
 */
public class Author
{

    String fN;
    String lN;

    public void name()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the first name of the author");
        String fN = sc.nextLine();
        System.out.println("Please enter the first name of the author");
        String lN = sc.nextLine();
        sc.close();
    }
}
