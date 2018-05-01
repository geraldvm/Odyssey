package socket;
import java.net.*;
import java.io.*;

public class conector {
    public ServerSocket server;
    public Socket socket;
    public int puerto = 9000;
    public  DataOutputStream salida; //Stream de salida
    public BufferedReader entrada;
    public void iniciar() {

        try{
            server = new ServerSocket(puerto);
            socket = new Socket();
            socket = server.accept();// Esperar peticion de conexion

            entrada = new BufferedReader(new InputStreamReader(socket.getInputStream()));//Canal de entrada
            String mensaje = entrada.readLine();
            System.out.println(mensaje);
            salida = new DataOutputStream(socket.getOutputStream());//Canal de salida
            salida.writeUTF("Adios Mundo");
            socket.close();
        }catch (Exception e){};
    }
}
