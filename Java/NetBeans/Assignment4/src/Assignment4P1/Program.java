package Assignment4P1;

/**
 * @author talha
 * @Due Date = Feb 7, 2022
 * @Assignment 4
 */
public class Program
{
    public static void main(String[] args)//main
    {
        Rect rect1 = new Rect();//intializes class Rect to rect1 variable
        rect1.createRect();//calls the createRect method from rect1 to change it parameters
        
        int rect1Area = rect1.getArea();//calls rect1.getArea, sends it the len and width and saves the area in a varaible
        int rect1Circum = rect1.getCircumf();//calls rect1.getCircum, sends it the len and width and saves the circum in a varaible
        rect1.move(3,4);//calls move from rect1 and sends it 3 and 4
        rect1.print();//calls print from rect1 to print all the values
        
        Rect rect2 = new Rect();//intializes class Rect to rect1 variable
        rect2.createRect();
        
        System.out.println(rect2.isBiggerThan(rect1));//prints out the comparision of area between rect2 and rect1
    }
    
}
