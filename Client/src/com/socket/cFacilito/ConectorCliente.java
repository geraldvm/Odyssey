package com.socket.cFacilito;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ConectorCliente {


    Socket cliente;
    int puerto = 7777;
    String ip = "127.0.0.1";
    PrintStream salida;
    BufferedReader entrada,teclado;
    public void iniciar(){
        try{

            cliente = new Socket(ip,puerto);

            entrada = new BufferedReader(new InputStreamReader(cliente.getInputStream()));
            teclado = new BufferedReader(new InputStreamReader(System.in));
            salida = new PrintStream(cliente.getOutputStream());
            String tec = teclado.readLine();
            String msg = entrada.readLine();

            System.out.println(msg);


            entrada.close();
            salida.close();
            teclado.close();
            cliente.close();

        }catch (Exception e){};

    }
}
