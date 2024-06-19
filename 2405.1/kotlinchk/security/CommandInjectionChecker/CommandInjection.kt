package testcase.rule.security.CommandInjectionChecker

import java.lang.Runtime
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation(request: HttpServletRequest) {
		val command = request.getParameter("command")			// 외부 입력

		val query = "cmd /c $command"

		val runtime = Runtime.getRuntime()
		val process1 = runtime.exec(query)						// @violation
		val process2 = runtime.exec("cmd /c $command")			// @violation
		val process3 = Runtime.getRuntime().exec(query)			// @violation
	}

	fun good(request: HttpServletRequest) {
		val command = request.getParameter("command")			// 외부 입력

		val whitelist = listOf("cd", "dir", "git clone")

		if(command in whitelist) {
			val query = "cmd /c $command"

			val runtime = Runtime.getRuntime()
			val process1 = runtime.exec(query)					// good
			val process2 = runtime.exec("cmd /c $command")		// good
			val process3 = Runtime.getRuntime().exec(query)		// good
		}
	}
}