/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package assignment5P34;

/**
 *Sorry i couldnt comment this code. I had to study for a midterm
 * @author talha
 * P4
 * due Monday 8 am
 */
public class Program
{

    public static void main(String[] args)
    {
        // TODO code application logic here
        String author1 = "Mark Twain";
        String title1 = "the adventures of huckleberry finn";
        int page1 = 366;
        int YoP1 = 1884;
        int price1 = 30;
        String author2 = "Mark Twain";
        String author3 = "Tom Blakenship";
        String title2 = "the adventures of huckleberry finn";
        int page2 = 366;
        int YoP2 = 1884;
        int price2 = 30;
        Book book1 = new Book(author1, title1, page1, YoP1, price1);
        Book book2 = new Book(author2, author3, title2, page2, YoP2, price2);
        
        System.out.println(book1.getTitleinTitleCase());
        System.out.println(book1.contains("adventures"));
        book2.printAuthors();
    }

}
