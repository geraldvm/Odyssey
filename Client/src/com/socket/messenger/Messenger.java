package com.socket.messenger;

public class Messenger {
    public static Conector servidor,cliente;
    public static void main (String[] args){
        Interface inter = new Interface();
    }

    public static void initCliente(String ip)
    {
        cliente = new Conector(ip);
        cliente.start();
    }
}
