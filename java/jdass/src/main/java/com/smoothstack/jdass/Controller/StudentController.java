package com.smoothstack.jdass.Controller;

import com.smoothstack.jdass.Service.StudentService;
import com.smoothstack.jdass.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import java.sql.SQLException;

@RestController
public class StudentController {

    @Autowired
    StudentService studentService;

    @RequestMapping(path = "/student/{studentId}" , method = RequestMethod.GET)
    public Student func(@PathVariable Integer studentId) {
        try {
            return studentService.getStudentById(studentId);
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
        return new Student();
    }
}
