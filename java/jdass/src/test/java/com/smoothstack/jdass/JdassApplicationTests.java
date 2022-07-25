package com.smoothstack.jdass;

import com.smoothstack.jdass.Controller.StudentController;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class JdassApplicationTests {

	@Test
	void contextLoads() {
	}
	@Test
	void requestForStudent() {
		StudentController studentController = new StudentController();
		Student st = new Student();
		st.setName("huzaifa");
		st.setId(0);
		st.setSchoolId(0);
		assert(studentController.func(0).equals(st));
	}

}
