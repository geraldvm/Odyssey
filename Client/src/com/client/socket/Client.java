package com.client.socket;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
    public static void main(String[] args) throws UnknownHostException, IOException {
        try {
            //String name =args[0];
            Socket socket = new Socket("127.0.0.1", 7777);
            PrintWriter printWriter = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader bufferedReader = new java.io.BufferedReader(new InputStreamReader(System.in));
            //BufferedReader bufferedReaderFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            //printWriter.println("Cliene Happy");
            while (true) {
                String readerInput = bufferedReader.readLine();
                printWriter.println(readerInput);
                //System.out.println(new BufferedReader(new InputStreamReader(socket.getInputStream())).readLine());
                //System.out.println(bufferedReaderFromServer.readLine());
            }
        }  catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
