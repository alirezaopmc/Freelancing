/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chatapp.chat;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Rajat
 */
public class CreateClientThread implements Runnable {
    Thread client_thread;
    //String t_name;
    //PrintWriter toServer;
    //BufferedReader fromServer;
    Socket client_socket;
    ChatFunctions cf;
    public CreateClientThread(int port) throws UnknownHostException, IOException{
        //t_name=name;
        cf = new ChatFunctions();
        while (true){
            boolean portTaken = false;
            ServerSocket socket = null;
            try {
                socket = new ServerSocket(port);
            } catch (IOException e) {
                portTaken = true;
            } finally {
                if (socket != null)
                try {
                    socket.close();
                } catch (IOException e) { /* e.printStackTrace(); */ }
            }
            if(portTaken){
                client_thread=new Thread(this);
                client_socket = new Socket("127.0.0.1", port);
                cf.openClientStreams(client_socket, port);
                System.out.println("Starting thread");
                break;
            }
        }
        //client_thread.start();
    }
    @Override
    public void run(){
        String msg = "";
        Scanner scanner = new Scanner(System.in);
        if (!"exit".equals(msg)){
            //System.out.print("Msg : ");
            
            System.out.print("Client2 : ");
            msg = scanner.nextLine();
            cf.toServer.println(msg);
            String tmp="";
            try {
                tmp = cf.fromServer.readLine();
            } catch (IOException ex) {
                Logger.getLogger(CreateClientThread.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println("Server2 : " + tmp);    
        }else{
        try {
            cf.closeClientStreams(client_socket);
        } catch (IOException ex) {
            Logger.getLogger(CreateClientThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        }
    }
    
}