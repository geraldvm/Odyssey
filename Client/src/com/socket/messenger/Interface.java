package com.socket.messenger;



import java.util.Scanner;

public class Interface {
    public static void main(String[] args) {
        Messenger.initCliente("127.0.0.1");


        Scanner entrada = new Scanner(System.in);

        int i=0;
        while(true) {
            String x = entrada.next();
            System.out.println(x);
            if (x.equals("send")) {
                Messenger.cliente.enviarMSG("Party");
                System.out.println("OK Send");
                // break;
                i++;
            }
        }
    }
}
