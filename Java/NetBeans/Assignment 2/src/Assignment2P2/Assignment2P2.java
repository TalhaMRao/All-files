package Assignment2P2;

/**
 * @author talha
 * @Due Date = Jan 24, 2022
 * @Assignment 2
 */
public class Assignment2P2
{

    /**
     * This function checks to see if it sees a prime number. It returns a
     * boolean, either true or false. It recieves an integer.
     */
    public static int primeCheck(int n)
    {
        for (int i = 2; i < n; i++)//i loops through all the numbers to n
        {
            if (n % i == 0)//checks if a number is divisible by i
            {
                return 0;//returns false and ends program
            }
        }
        return 1;//returns true and ends programs
    }

    public static void main(String[] args)//main
    {
        int num = 10000;//saves variable
        System.out.println("The prime numbers to 10000 are ");//prints output

        for (int i = 2; i <= num; i++)//loops to num
        {
            switch (primeCheck(i))//looks at primeCheck(i)
            {
                case 1://if it is 1
                    System.out.print(i + " ");//prints
                    break;//ends
            }
        }
    }
}
