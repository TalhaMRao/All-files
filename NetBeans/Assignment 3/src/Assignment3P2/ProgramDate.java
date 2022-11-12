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
public class ProgramDate
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        Date date1 = new Date();//intiializes the date1 as a date object
        date1.day = 22;//sets date1 date to a date
        date1.month = 2;//sets date1 date to a date
        date1.year = 2001;//sets date1 date to a date

        Date date2 = new Date();//intiializes the date2 as a date object
        date2.day = 7;//sets date2 date to a date
        date2.month = 12;//sets date2 date to a date
        date2.year = 2003;//sets date2 date to a date

        date1.addDays(1);//calls the addDays menthod in the date class and sends it 1
        date2.addDays(2);//calls the addDays menthod in the date class and sends it 2

        date1.print();//calls the print menthod in the date class
        date2.print();//calls the print menthod in the date class

        int diff = date1.compare(date2);//calls the compare method in date1 and sends it date2
        
        System.out.println("The difference between the dates is "+diff);//prints out the difference in dates
    }
}
