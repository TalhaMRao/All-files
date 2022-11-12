/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package assignment5P2;

import java.util.Random;

/**
 *Sorry i couldnt comment this code. I had to study for a midterm
 * @author talha
 * P2
 * due Monday 8 am
 */
public class RandomString
{

    Random random = new Random();
    StringBuilder o = new StringBuilder();

    String nextString(int n)
    {
        String store = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        if (n > 0)
        {
            o.append(store.charAt((int) (random.nextFloat() * 56)));

            for (int i = 0; i < n - 1; i++)
            {
                o.append(store.charAt((int) (random.nextFloat() * store.length())));
            }
            return o.toString();
        }
        return "";
    }
}
