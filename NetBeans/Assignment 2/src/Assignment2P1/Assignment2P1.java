package Assignment2P1;

/**
 * @author talha
 * @Due Date = Jan 24, 2022
 * @Assignment 2
 */
public class Assignment2P1//file
{

    /**
     * This function checks to see if it sees a prime number. It returns a
     * boolean, either true or false. It recieves an integer.
     */
    public static boolean primeCheck(int n)//function
    {
        for (int i = 2; i < n; i++)//i loops through all the numbers to n
            if (n % i == 0)//checks if a number is divisible by i
                return false;//returns false and ends program
  
        return true;//returns true and ends programs
    }

    public static void main(String[] args)//main
    {
        int num = 10000;//saving value in variable
        int i = 2;//saving value in variable
        System.out.println("The prime numbers to 10000 are ");//printing output for user

        while (i <= num)//while the num is less than 10000
        {
            if (primeCheck(i))//check if its a prime number, if it is then
            {
                System.out.print(i + " ");//print out the number
            }
            i++;//increment
        }
    }

}
