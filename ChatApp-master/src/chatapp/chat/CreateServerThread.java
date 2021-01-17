/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chatapp.chat;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Rajat
 */
public final class CreateServerThread implements Runnable {
    Thread server_thread;
    String t_name;
    Socket server_socket;
    ServerSocket serverSocket;
    ChatFunctions cf;
    CreateClientThread cct;
    
    public CreateServerThread(int port) throws IOException{
        cf = new ChatFunctions();
        serverSocket = new ServerSocket(port);
        //runServer(port);
    }
    @Override
    public void run() {
            String msg="";    
            String reply;
                do {
                    
                try {
                    msg = cf.fromClient.readLine();
                } catch (IOException ex) {
                    Logger.getLogger(CreateServerThread.class.getName()).log(Level.SEVERE, null, ex);
                }
                    System.out.println("Client1 : "+msg);
                    Scanner sc = new Scanner(System.in);
                    
                    System.out.print("Server1 : ");
                    reply = sc.nextLine();
                    cf.toClient.println(reply);
                } while (!"exit".equals(msg));
            try {
                cf.closeServerStreams(server_socket);
            } catch (IOException ex) {
                Logger.getLogger(CreateServerThread.class.getName()).log(Level.SEVERE, null, ex);
            }
    }
    public void runServer(int port) throws IOException{
        switch (port){
            case (3000) :
                cct = new CreateClientThread(++port);
                System.out.println("Client Connected to "+port);
                cct.client_thread.start();
                break;
            case (3001) :   
                cct = new CreateClientThread(--port);
                System.out.println("Client Connected to "+port);
                cct.client_thread.start();
                break;
        }
        while(true)
        {
        server_socket = serverSocket.accept();
        cf.openServerStreams(server_socket, port);
        server_thread=new Thread(this);
        server_thread.start();
        }
    }
}