//Packing Final Code

import java.io.*;
import java.util.*;

class Packar
{
    public static void main(String A[]) throws Exception
    {
        String Header = null;
        byte key = 0x11;
        int i=0, j=0;
        int iRet = 0;
        byte Buffer[] = new byte[100];
        byte bHeader[] = new byte[100];

        Scanner sobj = new Scanner(System.in);  

        System.out.println("Enter the name of folder:");
        String FolderName = sobj.nextLine();  

        System.out.println("Enter the name of pack file:");
        String PackName = sobj.nextLine();                 

        File fobj = new File(FolderName);

        if((fobj.exists()) && (fobj.isDirectory()))
        {
            File packobj = new File (PackName);

            packobj.createNewFile();

            FileOutputStream foobj = new FileOutputStream(packobj);
            System.out.println("Folder is Present");

            FileInputStream fiobj = null;

            File fArr[] = fobj.listFiles();

            System.out.println("Number of files in the folder are :"+fArr.length);

            for(i = 0; i < fArr.length; i++)
            {
                fiobj = new FileInputStream(fArr[i]);
                
                
                if(fArr[i].isFile() == true)
                {
                   
                   //Header Formation
                    Header = fArr[i].getName() + " " + fArr[i].length();

                    for(j = Header.length(); j< 100; j++)
                    {
                       Header = Header + " ";
                    }

                    bHeader = Header.getBytes();
                    
                    //write Header into pack file
                    foobj.write(bHeader,0,100);
                    
                    //read the data from input files from Marvellous Folder
                    while((iRet = fiobj.read(Buffer)) != -1)
                    {
                        //Encryption logic
                        for(j = 0; j<iRet; j++)
                        {
                            Buffer[j] = (byte)(Buffer[j] ^ key);
                        }

                        //write the files data into pack file
                           foobj.write(Buffer,0,iRet);
                    }
                }
                fiobj.close();
            }
            foobj.close();
        }
        else
        {
            System.out.println("Ther is no such folder");
        }
    
    }
}
