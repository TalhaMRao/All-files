/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package assignment5P2;
import java.util.Scanner;
/**
 *Sorry i couldnt comment this code. I had to study for a midterm
 * @author talha
 * P2
 * due Monday 8 am
 */
public class Assignment5P2
{
    public static void main(String[] args)
    {
        assignment5P2.RandomString ranS = new assignment5P2.RandomString();
        Scanner input = new Scanner(System.in);
        System.out.println("How long would you like the random string");
        int n = input.nextInt();
        System.out.println("\nThe random string is \n" +ranS.nextString(n));
    }
}
