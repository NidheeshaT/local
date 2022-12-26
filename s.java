import java.io.*;
import java.net.*;
import java.util.*;

public class s
{
    private static ServerSocket servSock;
    private static final int PORT = 1234;
    
    public static void main(String[] args) throws IOException
    {
        System.out.println("Opening port...\n");
        try
        {
            servSock = new ServerSocket(PORT); //Step 1.
        }
        catch(IOException ioEx)
        {
            System.out.println("Unable to attach to port!");
            System.exit(1);
        }
        System.out.println("Ready to serve client...\n");
        do
        {
          handleClient();
        }while (true);
    }
    private static void handleClient() throws IOException
    {
        Socket link = null; //Step 2.
       
        link = servSock.accept(); //Step 2.
        Scanner input = new Scanner(link.getInputStream());//Step 3.
        PrintWriter output =new PrintWriter(link.getOutputStream(),true); //Step 3.
        int numMessages = 0;
        String message = input.nextLine(); //Step 4.
        while (!message.equals("CLOSE"))
        {
            System.out.println("Message received from Client: " + message);
            numMessages++;
            output.println("Message " + numMessages + ": " + message); //Step 4.
            message = input.nextLine();
        }
      
        output.println(numMessages +" messages received.");//Step 4.
 
        System.out.println("\n* Closing connection... *");
        link.close(); //Step 5.
    }   
}
