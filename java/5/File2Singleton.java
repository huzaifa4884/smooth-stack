import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;


public class File2Singleton {
    private static Connection conn = null;
	
	private static File2Singleton instance = null;
	
	public static File2Singleton getInstance() {
		instance = new File2Singleton();
        return instance;
	}
}
