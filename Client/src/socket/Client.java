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
            //entrada = new BufferedReader((new InputStreamReader(client.getInputStream())));
            while(true){
            teclado = new BufferedReader(new InputStreamReader(System.in));
            String tec = teclado.readLine();
            salida = new PrintStream(client.getOutputStream());//Canal de salida
            salida.println(tec);
            salida.print(tec);
            /*
            String msg = entrada.readLine();
            System.out.println(msg);
            */

                entrada = new BufferedReader((new InputStreamReader(client.getInputStream())));
                String msg = entrada.readLine();
                System.out.println(msg);
            }

            /*entrada.close();

            salida.close();
            teclado.close();
            client.close();
            */
        }catch (Exception e){};
    }
}

/*
QByteArray read = socket->read(socket->bytesAvailable());
qDebug() << "Read : " << read.size();

QFile file(  ???); // what should I put in the bracket???
if(!(file.open(QIODevice::Append)))
{
    qDebug("File cannot be opened.");
    exit(0);
}
file.write(read);
file.close();
 */