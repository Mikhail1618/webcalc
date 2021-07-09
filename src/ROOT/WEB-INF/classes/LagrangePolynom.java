import java.io.PrintWriter;
import java.io.IOException;
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
         
        try
	{
            writer.println("<p>Nodes: " + nodes + "</p>");
            writer.println("<p>Start: " + start + "</p>");
            writer.println("<p>End: " + end + "</p>");
            writer.println("<p>Step: " + step + "</p>");
            writer.println("<p>Method: " + method[0] + "</p>");
        }
	finally
	{
            writer.close();  
        }
    }

}
