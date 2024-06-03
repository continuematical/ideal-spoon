import com.mysql.cj.jdbc.Driver;

import java.sql.*;
import java.util.Properties;

public class Main {

    public static Connection getConnectPostgres(String username, String password) throws Exception {
        String url = "jdbc:postgresql://localhost:5432/postgres";
        String driver = "org.postgresql.Driver";
        Class.forName(driver);
        //创立连接
        return DriverManager.getConnection(url, username, password);
    }

    public static Connection getConnectPostgresUseProp(String username, String password) throws Exception {
        String url = "jdbc:postgresql://localhost:5432/postgres";
        String driver = "org.postgresql.Driver";
        Properties props = new Properties();
        Class.forName(driver);
        props.setProperty("user", username);
        props.setProperty("password", password);
        Connection conn = DriverManager.getConnection(url, props);
        return conn;
    }


    public static void getConnectUsePropMySQL() throws Exception {
        Class<?> clazz = Class.forName("com.mysql.cj.jdbc.Driver");
        Driver driver = (Driver) clazz.newInstance();
        String url = "jdbc:mysql://localhost:3306/test";
        //提供连接要用的
        Properties info = new Properties();
        info.setProperty("user", "root");
        info.setProperty("password", "123456");
        // 获取连接
        Connection conn = driver.connect(url, info);
        // 创建数据库
        Statement stmt = conn.createStatement();
        stmt.
    }

    public static void main(String[] args) throws Exception {

    }
}