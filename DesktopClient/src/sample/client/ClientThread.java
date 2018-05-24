package sample.client;

public class ClientThread {
    public static Client client;

    public static void main(String[] args) {
        //Llamar clase de crear Ventana
    }
    public static void initClient(){
        client= new Client("127.0.0.1");
        client.start();
    }
}
