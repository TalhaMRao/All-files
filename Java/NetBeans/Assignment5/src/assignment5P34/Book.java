/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package assignment5P34;

/**
 *Sorry i couldnt comment this code. I had to study for a midterm
 * @author talha
 * P3
 * due Monday 8 am
 */
public class Book
{

    private String author1, author2, author3, title;
    private int page, YoP, price;

    public String getTitleinTitleCase()
    {
        StringBuilder o = new StringBuilder();
        o.append(Character.toUpperCase(title.charAt(0)));
        for (int i = 0; i < title.length() - 1; i++)
        {
            if (Character.isWhitespace(title.charAt(i)))
            {
                o.append(Character.toUpperCase(title.charAt(i + 1)));
            } else
            {
                o.append(Character.toLowerCase(title.charAt(i + 1)));
            }
        }
        return o.toString();
    }

    public boolean contains(String pattern)
    {
        return title.matches(".*" + pattern + ".*");
    }

    public void printAuthors()
    {
        System.out.println(author1);
        if (author2 != null)
        {
            System.out.println(author2);
        }
        if (author3 != null)
        {
            System.out.println(author3);
        }
    }

    public Book(String author1, String title, int page, int YoP, int price)
    {
        this.author1 = author1;
        this.title = title;
        this.page = page;
        this.YoP = YoP;
        this.price = price;
    }

    public Book(String author1, String author2, String title, int page, int YoP, int price)
    {
        this.author1 = author1;
        this.author2 = author2;
        this.title = title;
        this.page = page;
        this.YoP = YoP;
        this.price = price;
    }

    public Book(String author1, String author2, String author3, String title, int page, int YoP, int price)
    {
        this.author1 = author1;
        this.author2 = author2;
        this.author3 = author3;
        this.title = title;
        this.page = page;
        this.YoP = YoP;
        this.price = price;
    }

}
