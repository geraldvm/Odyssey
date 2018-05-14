package sample;
import java.io.*;
import java.nio.file.Files;

public class ToBytes {

    public static byte[] getBytes(File f)throws FileNotFoundException, IOException{
        byte[] buffer = new byte[1024];
        ByteArrayOutputStream os = new ByteArrayOutputStream();
        FileInputStream fis = new FileInputStream(f);
        int read;
        while ((read = fis.read(buffer))!=-1){

        }

    }
    public static void main(String[] args) {

    }
}
