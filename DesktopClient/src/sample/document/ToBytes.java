package sample.document;
import java.io.*;
import java.nio.file.Files;

public class ToBytes {

    public static byte[] getBytes(File f)throws FileNotFoundException, IOException{
        byte[] buffer = new byte[1024];
        ByteArrayOutputStream os = new ByteArrayOutputStream();
        FileInputStream fis = new FileInputStream(f);
        int read;
        while ((read = fis.read(buffer))!=-1){
            os.write(buffer,0,read);
            System.out.println(os);

        }
        fis.close();
        os.close();
        return os.toByteArray();

    }
    public static void main(String[] args) {
        try {
            File f = new File("/home/gerald/Documents/I Sem 2018/Datos 2/Odyssey/DesktopClient/src/sample/Files/sound.wav");
            byte[] bytesFromFile = getBytes(f);
           // byte[] bytesFromFile = Files.readAllBytes(f.toPath());
            System.out.println(bytesFromFile.length);

        }catch (Exception e){

        }
    }
}
