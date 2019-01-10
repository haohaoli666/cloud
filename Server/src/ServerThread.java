import java.io.*;
import java.net.Socket;
import java.net.URLDecoder;
import java.security.spec.ECField;
import java.util.StringTokenizer;
import java.sql.*;
import java.sql.*;

public class ServerThread implements Runnable {

	// 连接
	private Socket client;
	boolean online;
	// 数据库
	static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
	static final String DB_URL = "jdbc:mysql://localhost:3306/note";

	static final String user = "root";
	static final String password = "wkhawysha1998";
	public Connection conn;
	public Statement stmt;

	public PrintStream out;
	public BufferedReader buf;

	public String user_name;

	public ServerThread(Socket client) throws SQLException, ClassNotFoundException {
		this.client = client;

		this.online = false;

		conn = null;
		stmt = null;
		// 注册驱动
		Class.forName(JDBC_DRIVER);
		// 打开链接
		System.out.println("连接数据库...");
		conn = DriverManager.getConnection(DB_URL, user, password);

	}

	public void run() {
		try {

			out = new PrintStream(client.getOutputStream());
			buf = new BufferedReader(new InputStreamReader(client.getInputStream()));
			boolean flag = true;
			while (flag) {
				String str = buf.readLine();
				System.out.println(str);
				if (str.equals("login") && online == false) { // 登录
					Login();
					if (online == false)
						out.println("login\nfailed");
					else {
						out.println("login\nok\n" + user_name + "\n");
						Thread.sleep(100);
						get_group(); // 获取群组
					}
				}
				if (str.equals("register") && online == false) { // 注册
					Register();
				}
				if (online == false) {
					continue;
				}
				if (str.equals("new_book") && online == true) { // 新建笔记本
					new_book();
				}
				if (str.equals("new_group") && online == true) { // 新建群组
					new_group();
				}
				if (str.equals("new_note") && online == true) { // 新建笔记
					new_note();
				}
				if (str.equals("get_group") && online == true) { // 获取群组
					get_group();
				}
				if (str.equals("get_book") && online == true) { // 获取笔记本
					get_book();
				}
				if (str.equals("get_notes") && online == true) { // 获取笔记
					get_notes();
				}
				if (str.equals("get_content") && online == true) { // 获取笔记内容
					get_content();
				}
			}
			out.close();
			client.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void Login() throws IOException, SQLException {
		String name = buf.readLine();
		String user_password = buf.readLine();
		// 执行查询
		System.out.println(" 实例化Statement对象...");
		stmt = conn.createStatement();
		String sql;
		sql = "SELECT user_name FROM users";
		ResultSet rs = stmt.executeQuery(sql);

		boolean userExit = false;
		while (rs.next()) {
			if (rs.getString("user_name").equals(name)) {
				userExit = true;
				break;
			}
		}
		if (userExit == true) {
			sql = "SELECT user_password FROM users WHERE user_name = '" + name + "'";
			rs = stmt.executeQuery(sql);
			while (rs.next()) {
				if (rs.getString("user_password").equals(user_password)) {
					online = true;
					user_name = name;
					break;
				} else {
					System.out.println("login failed");
				}
			}
		} else {
			System.out.println("login failed");
		}
	}

	public void Register() throws IOException, SQLException {
		String name = buf.readLine();
		String user_password = buf.readLine();
		// 执行查询
		System.out.println(" 实例化Statement对象...");
		stmt = conn.createStatement();
		String sql;
		sql = "SELECT user_name FROM users";
		ResultSet rs = stmt.executeQuery(sql);

		boolean userExit = false;
		while (rs.next()) {
			if (rs.getString("user_name").equals(name)) {
				userExit = true;
				break;
			}
		}
		if (userExit == true) {
			out.println("register\nfailed\n");
		} else {
			System.out.println("user_name is vaild");
			sql = "INSERT INTO users(user_name,user_password) \r\n" + "values(\"" + name + "\",\"" + user_password
					+ "\");";
			stmt.execute(sql);
			out.println("register\nok\n");
		}
	}

	public void new_book() throws IOException, SQLException { // 创建新的笔记本
		String group_name = buf.readLine();
		String book_name = buf.readLine();
		String des = buf.readLine();
		// 执行查询
		System.out.println(" 实例化Statement对象...");
		stmt = conn.createStatement();
		String sql;
		sql = "SELECT book_name FROM books WHERE group_name = '" + group_name + "'";
		ResultSet rs = stmt.executeQuery(sql);

		boolean noteExit = false;
		while (rs.next()) {
			if (rs.getString("").equals(book_name)) { // 存在同名的笔记本
				noteExit = true;
				break;
			}
		}
		if (noteExit == true) { // 存在同名笔记本
			out.println("new_note\nfailed\n");
		} else { // 不存在同名笔记本，创建该笔记本
			System.out.println("book_name is vaild");
			sql = "INSERT INTO books(group_name,book_name,book_describe) \r\n" + "values('" + group_name + "','"
					+ book_name + "','" + des + "');";
			stmt.execute(sql);
			out.println("new_book\nok\n");
		}
	}

	public void new_group() throws IOException, SQLException { // 创建新的群组
		String group_name = buf.readLine();
		// 执行查询
		System.out.println(" 实例化Statement对象...");
		stmt = conn.createStatement();
		String sql;
		sql = "SELECT group_name FROM group_table WHERE group_name = '" + group_name + "'";
		ResultSet rs = stmt.executeQuery(sql);

		boolean noteExit = false;
		while (rs.next()) {
			if (rs.getString("group_name").equals(group_name)) { // 存在同名的笔记本
				noteExit = true;
				break;
			}
		}
		if (noteExit == true) { // 存在同名群组
			out.println("new_group\nfailed");
		} else { // 不存在同名群组，创建该群组
			System.out.println("group_name is vaild");
			sql = "INSERT INTO group_table(group_name,user_name\r\n)" + "values('" + group_name + "','" + user_name
					+ "');";
			stmt.execute(sql);
			out.println("new_group\nok\n");
		}
	}

	public void new_note() throws IOException, SQLException { // 创建新的笔记
		String group_name = buf.readLine();
		String book_name = buf.readLine();
		String note_name = buf.readLine();
		// 执行查询
		System.out.println(" 实例化Statement对象...");
		stmt = conn.createStatement();
		String sql;
		sql = "SELECT note_name FROM notes WHERE group_name = '" + group_name + "' AND book_name = '" + book_name
				+ "' AND note_name = '" + note_name + "'";
		ResultSet rs = stmt.executeQuery(sql);

		boolean noteExit = false;
		while (rs.next()) {
			if (rs.getString("note_name").equals(note_name)) { // 存在同名的笔记
				noteExit = true;
				break;
			}
		}
		if (noteExit == true) { // 存在同名笔记
			out.println("new_group\nfailed\n");
		} else { // 不存在同名笔记，创建该笔记
			System.out.println("note_name is vaild");
			sql = "INSERT INTO notes(group_name,book_name,note_name \r\n)" + "values('" + group_name + "','"
					+ book_name + "','" + note_name + "');";
			stmt.execute(sql);
			out.println("new_note\nok\n");
		}
	}

	public void get_group() throws SQLException { // 获取群组
		System.out.println("getting group");
		System.out.println("实例化Statement对象...");
		stmt = conn.createStatement();
		String sql = "SELECT group_name FROM group_table WHERE user_name = '" + user_name + "'";
		ResultSet rs = stmt.executeQuery(sql);

		String my_group = "";
		my_group += "get_group\n";
		while (rs.next()) {
			my_group += rs.getString("group_name") + "\n";
		}
		System.out.println(my_group);
		my_group += "get_group_end\n";
		out.println(my_group);
	}

	public void get_book() throws IOException, SQLException { // 获取笔记本
		String group_name = buf.readLine();

		System.out.println("实例化statement...");
		stmt = conn.createStatement();
		String sql = "SELECT book_name FROM books WHERE group_name = '" + group_name + "'";
		ResultSet rs = stmt.executeQuery(sql);

		String my_book = "";
		my_book += "get_book\n";
		while (rs.next()) {
			my_book += rs.getString("book_name") + "\n";
		}
		System.out.println(my_book);
		my_book += "get_book_end\n";
		out.println(my_book);
	}

	public void get_notes() throws IOException, SQLException { // 获取笔记
		String group_name = buf.readLine();
		String book_name = buf.readLine();
		System.out.println("实例化statement...");
		stmt = conn.createStatement();
		String sql = "SELECT note_name FROM notes WHERE group_name = '" + group_name + "' AND book_name = '" + book_name
				+ "';";
		ResultSet rs = stmt.executeQuery(sql);

		String my_note = "";
		my_note += "get_notes\n";
		while (rs.next()) {
			my_note += rs.getString("note_name") + "\n";
		}
		System.out.println(my_note);
		my_note += "get_note_end\n";
		out.println(my_note);
	}

	public void get_content() throws IOException, SQLException { // 获取笔记内容
		String group_name = buf.readLine();
		String book_name = buf.readLine();
		String note_name = buf.readLine();
		System.out.println("实例化statement...");
		stmt = conn.createStatement();
		String sql = "SELECT content FROM notes WHERE group_name = '" + group_name + "' AND book_name =" + book_name
				+ "' AND note_name = '" + note_name + "'";
		ResultSet rs = stmt.executeQuery(sql);

		String content = "";
		content += "get_content\n";
		while (rs.next()) {
			content += rs.getString("content") + "\n";
		}
		System.out.println(content);
		content += "get_content_end\n";
		out.println(content);
	}
	

}
