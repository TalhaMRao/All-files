/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package P1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.util.Random;

/**
 *
 * @author talha
 */
public class FileUtils
{

    static long length(File path)
    {
        long size = 0;
        File[] filesList = path.listFiles();
        try
        {
            for (int i = 0; i < filesList.length; i++)
            {
                if (filesList[i].isFile())
                {
                    size += filesList[i].length();
                } else
                {
                    size += FileUtils.length(filesList[i]);
                }
            }
        } catch (Exception e)
        {
            System.out.println("An error occured. Double check the path and if the file exists");
            size = 1;
        }
        return size;
    }

    static String createRandomFile() throws IOException
    {
        Random random = new Random();
        StringBuilder o = new StringBuilder();

        String store = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < 15; i++)
        {
            o.append(store.charAt((int) (random.nextFloat() * store.length())));
        }
        String fileName = o.toString() + ".txt";
        System.out.println(fileName);

        File file = new File(fileName);
        if (file.createNewFile())
        {
            return System.getProperty("user.dir");
        } else
        {
            System.out.println("File could not be created, probably already exists");
        }

        return "";
    }

    static void split(String x, int n) throws IOException
    {
        File file = new File(x + ".txt");
        FileReader fr = new FileReader(file);
        BufferedReader reader = new BufferedReader(fr);
        PrintWriter pw = null;

        long lines = 0;
        int noOfFiles = 0;
        String temp;
        int lineAt = 1;
        int startLine = 1;
        int i;

        if (file.exists())
        {
            lines = Files.lines(file.toPath()).count();
        }
        noOfFiles = (int) Math.ceil((double) lines / n);
        int endLine = (int)lines;
        
        for (i = 1; i <= noOfFiles; i++)
        {
            pw = new PrintWriter(x + (i) + ".txt");
            while (lineAt <= endLine)
            {
                temp = reader.readLine();
                if (lineAt >= startLine && lineAt <= endLine)
                {
                    pw.println(temp);
                }
                lineAt++;
            }
            startLine += n;
        }
        if (lines % n != 0)
        {
            pw = new PrintWriter(x + (i) + ".txt");
        }
        pw.close();
        fr.close();
    }
    
    
}
