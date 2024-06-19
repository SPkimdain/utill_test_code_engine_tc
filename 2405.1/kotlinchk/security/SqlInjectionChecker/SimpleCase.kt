package testcase.rule.security.SqlInjectionChecker

import org.springframework.stereotype.Controller
import org.springframework.web.bind.annotation.GetMapping
import java.sql.* // test import *
//import java.sql.Connection
//import java.sql.ResultSet
//import java.sql.Statement
import javax.servlet.http.HttpServletRequest

object SimpleCase {
	@GetMapping("/sql")
	fun sql(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")											// 외부 입력

		val c: Connection = dataSource.getConnection()
		val rs = c.createStatement().executeQuery("select * from user where id = $userId")	// @violation
		return "sql"
	}

	@GetMapping("/sqlSimple")
	fun sqlSimple(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")											// 외부 입력

		val query = "select * from user where id = $userId"
		val c = Connection()
		val stmt = c.createStatement()
		val rs = stmt.executeQuery(query)													// @violation
		return "sql"
	}
}