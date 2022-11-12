/**
 * @author talha
 * @Due Date = Jan 24, 2022
 * @Assignment 3
 */
package Assignment3P2;

/**
 *
 * @author talha
 */
public class Date
{

    int day = 0;//day variable intialized
    int month = 0;//month variable intialized
    int year = 0;//month variable intialized

    void print()//void method that prints the dates
    {
        System.out.println("The date in year/month/day is " + year + "/" + month + "/" + day);//prints out the date
    }

    void addDays(int n)//method to add n number of days into the date, gets an int n
    {
        day = day + n;//increments the current date by n

        if (day > 30)//makes sure that the dates dont go past 30 days
        {
            day = 1;
            month++;
        }
        if (month > 12)//makes sure the months dont go past 12 months
        {
            month = 1;
            year++;
        }
    }

    int compare(Date x)//a method to compare the dates of x to the class's own. recieves a date and returns an int
    {
        int diff_day = 0;//intializes date difference
        int diff_month = 0;//intializes date difference
        int diff_year = 0;//intializes date difference
        int tot=0;//total difference
        int n = 0;//counter
        if (x.year > year)//checks to see if x is larger than the class date
        {
            n = 1;
        } else if (x.year < year)//checks to see if x is larger than the class date
        {
            n = -1;
        }

        if (x.month > month)//checks to see if x is larger than the class date
        {
            n = 1;
        } else if (x.month < month)//checks to see if x is larger than the class date
        {
            n = -1;
        }

        if (x.day > day)//checks to see if x is larger than the class date
        {
            n = 1;
        } else if (x.day < day)//checks to see if x is larger than the class date
        {
            n = -1;
        }

        if (n == -1)
        {
            diff_day = x.day - day;//saves the diff in dates
            diff_month = x.month - month;//saves the diff in dates
            diff_year = x.year - year;//saves the diff in dates
            if (diff_day < 0)//makes sure dates dont pass whats possible
            {
                diff_month--;
                diff_day += 30;
            }
            if (diff_month < 0)//makes sure dates dont pass whats possible
            {
                diff_year--;
                diff_month += 12;
            }
        }
        if (n == 1)
        {
            diff_day = day - x.day;//saves the diff in dates
            diff_month = month - x.month;//saves the diff in dates
            diff_year = year - x.year;//saves the diff in dates
            if (diff_day < 0)//makes sure dates dont pass whats possible
            {
                diff_month--;
                diff_day += 30;
            }
            if (diff_month < 0)//makes sure dates dont pass whats possible
            {
                diff_year--;
                diff_month += 12;
            }
        }
        tot = diff_day + diff_month*30 + diff_year*365;//adds up the differnces into tot
        return tot;//returns tot
    }
}
