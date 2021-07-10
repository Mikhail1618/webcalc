import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
  
@WebServlet("/polynom")
public class LagrangePolynom extends HttpServlet
{  
    protected void doPost(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException 
    {      
        response.setContentType("text/html");
        PrintWriter writer = response.getWriter();
 
        String nodes = request.getParameter("Nodes");
        String start = request.getParameter("Start");
        String end = request.getParameter("End");
        String step = request.getParameter("Step");
        String[] method = request.getParameterValues("Method");

        String[] commands = { "/usr/local/tomcat/webapps/calc_polynom/polynom.bin", nodes, start, end, step };
 
        try
	{
            //writer.println("<p>Nodes: " + nodes + "</p>");
            //writer.println("<p>Start: " + start + "</p>");
            //writer.println("<p>End: " + end + "</p>");
            //writer.println("<p>Step: " + step + "</p>");
            //writer.println("<p>Method: " + method[0] + "</p>");
        }
	finally
	{
            //writer.close();  
        }


        Process proc = Runtime.getRuntime().exec(commands);

        BufferedReader stdInput = new BufferedReader(new 
            InputStreamReader(proc.getInputStream()));

        BufferedReader stdError = new BufferedReader(new 
            InputStreamReader(proc.getErrorStream()));

       writer.println("<p>");
       String s = null;
       while ((s = stdInput.readLine()) != null)
       {
            writer.println(s);
            writer.println("<br>");//"&#10;");
       }
       writer.println("</p>");
       writer.close();

    }

}
