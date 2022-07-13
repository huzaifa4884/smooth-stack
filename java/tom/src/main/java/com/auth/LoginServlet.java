package com.auth;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(value = "/login")
public class LoginServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request , HttpServletResponse response ) throws ServletException , IOException {
        String userName = request.getParameter("userName");
        String password = request.getParameter("password");

        if (userName.equals("root") && password.equals("root")) {
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<h1> dashboard </h1>");
        }

        else {
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<h1> incorrect username of password </h1>");
        }


    }


}
