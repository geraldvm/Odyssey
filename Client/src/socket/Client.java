package socket;

import java.net.*;
import java.io.*;


public class Client{
    public Socket client;
    public int puerto = 7777;
    public String ip = "127.0.0.1";

    public PrintStream salida; //Stream de salida
    public BufferedReader entrada, teclado;
    public void iniciar() {

        try{
            client = new Socket(ip,puerto);
            entrada = new BufferedReader((new InputStreamReader(client.getInputStream())));
            teclado = new BufferedReader(new InputStreamReader(System.in));
            String tec = teclado.readLine();
            salida = new PrintStream(client.getOutputStream());//Canal de salida
            salida.println(tec);
            String msg = entrada.readLine();
            System.out.println(msg);


            entrada.close();

            salida.close();
            teclado.close();
            client.close();
        }catch (Exception e){};
    }
}
