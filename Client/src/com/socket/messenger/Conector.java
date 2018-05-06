package com.socket.messenger;
import com.sun.org.apache.xml.internal.utils.ThreadControllerWrapper;

import java.io.*;
import java.net.*;
import java.time.Duration;

public class Conector extends Thread{

    private Socket s;
    private ServerSocket ss;
    private InputStreamReader entradaSocket;
    private DataOutputStream salida;
    private BufferedReader entrada;
    final int puerto =7777;

    /*public Conector(){
        try {
            ss = new ServerSocket(puerto);
            s = ss.accept();

            //Creacion de entrada de datos para lectura de mensajes
            entradaSocket = new InputStreamReader(s.getInputStream());
            entrada = new BufferedReader(entradaSocket);

            //Creacion salida para el envio de mensajes
            salida = new DataOutputStream(s.getOutputStream());
        }catch (Exception e){};
    }*/

    public Conector(String ip){

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
                System.out.println(texto+"\n");
            } catch (IOException e) { };
        }
    }

    public void enviarMSG(String msg){
        System.out.println("Enviando...");
        try {
            this.salida = new DataOutputStream(s.getOutputStream());
            //salida.writeChars(msg);
            this.salida.writeUTF(msg);
            System.out.println("ENVIADO\n");
        }catch (IOException e){};
    }
    public  void leerMSG(){
        try{
            System.out.println(entrada.readLine());
        }catch (IOException e){};


    }
    public void desconectar(){
        try {
            s.close();
        }catch (Exception e){};
        try {
            ss.close();
        }catch (Exception e){};
    }
}
