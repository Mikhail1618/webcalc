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


        String[] commands = { "polynom.bin", nodes, start, end, step}; 
        Process proc = Runtime.getRuntime().exec(commands);
        proc.waitFor();

        Process proc2 = Runtime.getRuntime().exec("gnuplot < settings_plot");
        proc2.waitFor();

        writer.println("<p>");
        writer.println("var image = document.images[0];" +
                       "var downloadingImage = new Image();" +
                       "downloadingImage.onload = function(){" +
                       "image.src = this.src;" +
                       "};" +
                       "downloadingImage.src = \"/function.png\";");

        //writer.println("<img src=\"/function.png\" />");
        writer.println("</p>");

        writer.println("<p>");
        writer.println("<a href=\"/function.png\">function.png</a>");
        writer.println("</p>");

        writer.close();
    }

}
