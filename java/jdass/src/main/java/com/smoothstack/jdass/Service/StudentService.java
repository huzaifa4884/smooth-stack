package com.smoothstack.jdass.Service;

import com.smoothstack.jdass.Dao.StudentDao;
import com.smoothstack.jdass.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.sql.SQLException;

@Component
public class StudentService {

    @Autowired
    StudentDao studentDao;

    public Student getStudentById(Integer studentId) throws SQLException {

        return studentDao.getStudentById(studentId);
    }
}
