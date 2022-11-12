/**
 * @author talha
 * @Due Date = Jan 24, 2022
 * @Assignment 3
 */
package Assignment3P1;

/**
 *
 * @author talha
 */
public class Program
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)//main
    {
        Rect rect1 = new Rect();//intializes class Rect to rect1 variable
        rect1.len = 5;//calls len from rect1 and sets it to 5
        rect1.width = 7;//calls width from rect1 and sets it to 7
        int rect1Area = rect1.getArea(rect1.len,rect1.width);//calls rect1.getArea, sends it the len and width and saves the area in a varaible
        int rect1Circum = rect1.getCircumf(rect1.len,rect1.width);//calls rect1.getCircum, sends it the len and width and saves the circum in a varaible
        rect1.move(3,4);//calls move from rect1 and sends it 3 and 4
        rect1.print();//calls print from rect1 to print all the values
        
        Rect rect2 = new Rect();//intializes class Rect to rect2 variable
        rect2.len = 3;//calls len from rect2 and sets it to 3
        rect2.width = 1;//calls width from rect1 and sets it to 1
        int rect2Area = rect2.getArea(rect2.len,rect2.width);//calls rect2.getArea, sends it the len and width and saves the area in a varaible
        int rect2Circum = rect2.getCircumf(rect2.len,rect2.width);//calls rect2.getCircum, sends it the len and width and saves the circum in a varaible
        rect2.move(7,-2);//calls move from rect1 and sends it 7 and -2
        rect2.print();//calls print from rect2 to print all the values
    }
}
