package P5;

import java.util.ArrayList;

/**
 * @author talha
 * P1 & 3
 * due Monday 8 am
 */
public class main
{

    public static void main(String[] args)
    {
        System.out.println(PrimeNumber(7));//prints the returned list
    }

    static ArrayList<Integer> PrimeNumber(int n)
    {
        ArrayList<Integer> arr = new ArrayList<Integer>();//makes array list
        int k = 0, i = 2;//initalize vairables
        while (k < n)
        {  // to only print till n
            boolean isPrime = true;  // boolean intialized
            for (int d = 2; d <= i / 2; d++)//loops till half of i
            {
                if (i % d == 0)//if i is not prime
                {
                    isPrime = false;//sets to false
                    break; // i is not a prime, no reason to continue checking
                }
            }
            if (isPrime)//if its true however
            {
                arr.add(i);//adds it to array ist
                k++; // increase k by when a prime number is found
            }
            i++; // increment i for next number
        }
        return arr;//returns list
    }
}
