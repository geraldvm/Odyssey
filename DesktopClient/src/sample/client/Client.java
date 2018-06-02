package sample.client;
import java.io.*;
import java.net.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;


public class Client extends Thread {
    private Socket s;
    private ServerSocket ss;
    private InputStreamReader entradaSocket;
    private DataOutputStream salida;
    private BufferedReader entrada;
    private final int puerto =7777;


    DataInputStream input;
    byte[] buffer = new byte[250000];
    int veces=0;


    public Client(String ip){

        try{
            this.s = new Socket(ip,this.puerto);

            this.entradaSocket = new InputStreamReader(s.getInputStream());
            this.entrada = new BufferedReader(entradaSocket);
            this.salida= new DataOutputStream(s.getOutputStream());

            this.input = new DataInputStream(s.getInputStream());
            //this.salida.writeUTF("Conectado- \n");


        }catch (Exception e){};

    }

    public  void run(){
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        String text;
        /*while (true) {
            listen();
        }*/
        /*while (true) {
            try {
                if(veces<1){
                    songStreaming(baos);
                    veces++;
                    //baos.flush();


                    //entrada.read();
                    //input.skipBytes(6000000);
                }else{


                    text=entrada.readLine();
                    entrada.mark(0);
                    entrada.reset();

                    writeFile(text);
                    System.out.println("---"+text);
                }


            } catch (Exception e) { };
        }*/
    }

    public void sendMSG(String msg){
        System.out.println("Enviando...");
        try {
            this.salida = new DataOutputStream(s.getOutputStream());
            //salida.writeChars(msg);
            this.salida.writeUTF(msg);
            System.out.println("ENVIADO\n");
        }catch (IOException e){};
    }

    public void sendSong(byte[] song){
        System.out.println("SEND SONG");
        try {
            this.salida = new DataOutputStream(s.getOutputStream());
            this.salida.write(song);
        }catch (IOException e){};
    }

    public  void readMSG(){
        try{
            //System.out.println(entrada.readLine());
            writeFile(entrada.readLine());
        }catch (IOException e){};


    }
    public void disconnected(){
        try {
            s.close();
        }catch (Exception e){};
        try {
            ss.close();
        }catch (Exception e){};
    }
    public void writeFile(String data)
    {
        try {
            //String str = "Hello";

            BufferedWriter writer = new BufferedWriter(new FileWriter("src/sample/Files/temporal.xml"));
            writer.write(data);
            System.out.println("temp.xml Ready");

            writer.close();
        }catch (Exception e){};
    }
/*
    public void createMP3(byte data[]){

        File destination = new File("PRUEBA.mp3");

        try(FileOutputStream fos= new FileOutputStream(destination)){
            fos.write(data);
            fos.close();
        }catch (Exception e){
            System.out.println("there was an error");
        }
    }*/

    public void writeFileAppend(String data)
            throws IOException {
        //String str = "World";
        BufferedWriter writer = new BufferedWriter(new FileWriter("ws", true));
        //writer.append(');
        writer.append(data);

        writer.close();
    }

    public void songStreaming(ByteArrayOutputStream baos)throws Exception{
        System.out.println("START...");

        for(int n=0;n<6905032;n+=250000){
            baos.write(buffer, 0, input.read(buffer));

        }byte result[] = baos.toByteArray();
        File f = new File("src/sample/Files/sound.mp3");
        Files.write(f.toPath(), result);
        System.out.println("Recibiendo...");

    }
    public void listen(){
        String text;

        while (true) {
            try {
                text = entrada.readLine();

                //System.out.println((text.contains("END")));///*
                if ((text.contains("END"))) {


                    System.out.println("BREAK");
                    break;
                } else {

                    //writeFile(text);
                    System.out.println("---" + text);
                }
            } catch (Exception e) { }

        }

    }
}
//http://www.cplusplus.com/forum/general/27659/