/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package P1;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author talha
 */
public class Main
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        try ( Scanner input = new Scanner(System.in))
        {
            System.out.println("Enter 1 to find the length of a folder, enter 2 to create a txt file with a random name,"
                    + " enter 3 to try FileUtils.split method, enter 4 to try FileUtils.createDirectories method");
            int c = input.nextInt();

            if (c == 1)/////////////////////////////////////////////////////////////////////////////////////
            {
                System.out.println("What is the file path? Example: \"C:\\Users\\talha\\OneDrive\\Documents\\NetBeansProjects\\Assignment9\"");

                String filePath = input.nextLine();
                File file = new File(filePath);

                long size = FileUtils.length(file);

                System.out.println("The size of that file is " + size);
            } else if (c == 2)/////////////////////////////////////////////////////////////////////////////////
            {
                String filePath = FileUtils.createRandomFile();
                System.out.println("The file was saved to the directory: " + filePath);
            } else if (c == 3)
            {
                System.out.println("Enter the name of the file. The file must be in this directory.");
                String filePath = input.nextLine();
                filePath = input.nextLine();

                System.out.println("Enter the number of lines you would like to split it by.");
                int n = input.nextInt();
                FileUtils.split(filePath, n);
            } else
            {

            }
        } catch (Exception e)
        {
            System.out.println("There was an error in the inputs");
        }
    }
}
