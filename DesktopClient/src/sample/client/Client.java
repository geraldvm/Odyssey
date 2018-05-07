package sample.client;
import java.io.*;
import java.net.*;

public class Client extends Thread {
    private Socket s;
    private ServerSocket ss;
    private InputStreamReader entradaSocket;
    private DataOutputStream salida;
    private BufferedReader entrada;
    private final int puerto =7777;



    public Client(String ip){

        try{
            this.s = new Socket(ip,this.puerto);

            this.entradaSocket = new InputStreamReader(s.getInputStream());
            this.entrada = new BufferedReader(entradaSocket);

            this.salida= new DataOutputStream(s.getOutputStream());
            this.salida.writeUTF("Conectado- \n");

        }catch (Exception e){};

    }

    public  void run(){
        String texto;
        while (true) {
            try {
                texto= entrada.readLine();
                //writeFile(texto);
                writeFileAppend(texto);
                System.out.println(texto+"\n");
            } catch (IOException e) { };
        }
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
            throws IOException {
        //String str = "Hello";
        BufferedWriter writer = new BufferedWriter(new FileWriter("what.txt"));
        writer.write(data);
        System.out.println("MP3 Ready");

        writer.close();
    }

    public void writeFileAppend(String data)
            throws IOException {
        //String str = "World";
        BufferedWriter writer = new BufferedWriter(new FileWriter("ws", true));
        //writer.append(');
        writer.append(data);

        writer.close();
    }
}
//http://www.cplusplus.com/forum/general/27659/