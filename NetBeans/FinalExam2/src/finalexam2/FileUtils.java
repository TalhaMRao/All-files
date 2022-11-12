package finalexam2;

import java.io.File;
import java.util.ArrayList;

/**
 *
 * @author talha
 */
public class FileUtils
{

    public static ArrayList<File> listFiles(String source, String[] extensions)
    {
        File file = new File(source);
        ArrayList<File> allFiles = new ArrayList<>();
        for (int i = 0; i < extensions.length; i++)
        {
            String temp = extensions[i];
            File[] matchingFiles = file.listFiles((File dir, String name) -> name.endsWith(temp));
            for (int j = 0; j < matchingFiles.length; j++)
            {
                allFiles.add(matchingFiles[j]);
            }
        }
        return allFiles;
    }
}
