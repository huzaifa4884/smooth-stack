package com.smoothstack.jdass.Dao;

import com.smoothstack.jdass.Student;
import org.springframework.stereotype.Component;

import java.sql.*;

@Component
public class StudentDao {

    public Student getStudentById(Integer studentId) throws SQLException {
        Student st = new Student();
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/smoothstack" , "ass" , "IBMQ_16_melbourne");
        Statement statement;
        statement = conn.createStatement();
        ResultSet resultSet;
        resultSet = statement.executeQuery("SELECT * FROM Student");
        while (resultSet.next()) {
            System.out.println(studentId);
            if (resultSet.getInt("id") == studentId) {
                st.setId(studentId);
                st.setName(resultSet.getString("name"));
                break;
            }
        }
        return st;
    }
}
