package sample.document;
import java.io.*;
import java.nio.file.Files;
public class ToFile {

    public static void toFile(byte data[], File destination){
        try(FileOutputStream fos= new FileOutputStream(destination)){
            fos.write(data);

            fos.close();
        }catch (Exception e){
            System.out.println("there was an error");
        }
    }

    public static void main(String[] args) {
        String someText = "This is some fsds text";
        byte[] data = someText.getBytes();
        File destination = new File("sample.mp3");
       // toFile(data,destination);
        try {
            File f = new File("/home/gerald/Documents/I Sem 2018/Datos 2/Odyssey/DesktopClient/src/sample/Files/Prueba.mp3");
            Files.write(destination.toPath(), Files.readAllBytes(f.toPath()));
        }catch (Exception e){};
    }
}
