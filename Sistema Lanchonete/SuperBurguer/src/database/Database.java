package database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import main.SoftwareInfo;

public abstract class Database {
	private static Connection singletonConnection = null;
	
	public Database() {
		getSingletonConnection();
	}
	
	public static Connection getSingletonConnection(){
		if(singletonConnection==null) {
			try {
				Class.forName(SoftwareInfo.DB_DRIVER);
				singletonConnection = DriverManager.getConnection(SoftwareInfo.DB_URL, SoftwareInfo.DB_USERNAME, SoftwareInfo.DB_PASSWORD);
			} catch(Exception ex) {
				System.err.println("N�o foi poss�vel iniciar conex�o com o banco de dados.\n" + ex.getMessage());
			}
		}
		
		return singletonConnection;
	}
	
	public static ResultSet DBExecuteQuery(String sqlScript) {
		if(singletonConnection!=null)
			try {
				PreparedStatement stmt = (PreparedStatement) getSingletonConnection().prepareStatement(sqlScript);
				return stmt.executeQuery();
			} catch (SQLException ex) {
				System.err.println("ERRO: N�o foi poss�vel executar consulta.");
				ex.printStackTrace();
			}
		else
			System.err.println("Nenhuma conex�o com o banco de dados foi estabelecida ainda.");
		
		return null;
	}
	
	public static boolean DBUpdate(String sqlScript) {
		if(singletonConnection!=null)
			try {
				PreparedStatement stmt = (PreparedStatement) getSingletonConnection().prepareStatement(sqlScript);
				stmt.executeUpdate();
				return true;
			} catch (SQLException ex) {
				System.err.println("ERRO: N�o foi poss�vel atualizar o database.");
				ex.printStackTrace();
			}
		else
			System.err.println("Nenhuma conex�o com o banco de dados foi estabelecida ainda.");
		
		return false;
	}
	
	public static boolean DBUpdate(PreparedStatement stmt) {
		if(singletonConnection!=null)
			try {
				stmt.executeUpdate();
				return true;
			} catch (SQLException ex) {
				System.err.println("ERRO: N�o foi poss�vel atualizar o database.");
				ex.printStackTrace();
			}
		else
			System.err.println("Nenhuma conex�o com o banco de dados foi estabelecida ainda.");
		
		return false;
	}

}
