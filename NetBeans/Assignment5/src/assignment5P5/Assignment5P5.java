/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package assignment5P5;

/**This code dosent work properly but hopefully ill get part marks
 *Sorry i couldnt comment this code. I had to study for a midterm
 * @author talha
 * P5
 * due Monday 8 am
 */
public class Assignment5P5
{

    public static void main(String[] args)
    {
        // TODO code application logic here
        String pattern1 = "_";//creates varaibles
        String pattern2 = "gmail.com";//creates varaibles
        String input = "frost_@gmail.com ";//creates varaibles
        String[] list =
        {
            " ", " ", " ", " ", " ", " ", " ", " "//creates varaibles
        };
        int j = 0;//creates varaibles
        int _counter = 0;//creates varaibles
        int gmail = 0;//creates varaibles
        for (int i = 0; i < input.length(); i++)//loops through the lenght of the input
        {
            StringBuilder build = new StringBuilder();//new string using builder
            if (input.charAt(i) == ';' || input.charAt(i) == ' ' || input.charAt(i) == ',')
            {
                list[j] += build.toString();//adds the string 
                j++;
            } else
            {
                build.append(input.charAt(i));
            }
        }
        for (int i = 0; i <= j; i++)
        {
            if (list[i].endsWith("@gmail.com"))
            {
                gmail++;
            }
            for (int k = 0; k < list[i].length(); k++)
            {
                if (list[i].charAt(k) == '_')
                {
                    _counter++;
                    break;
                }
            }
        }
        System.out.println("There are " + _counter++ + " with an _ and " + gmail + " gmail associated emails.");
    }
}
