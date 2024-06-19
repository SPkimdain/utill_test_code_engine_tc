package testcase.rule.security.PathManipulationChecker

import java.io.File
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation(request: HttpServletRequest) {
		val name = request.getParameter("name")				// 외부 입력

		val filepath = "/home/user/$name"

		val file1 = File(filepath)							// @violation
		val file2 = java.io.File("/home/user/$name")		// @violation

		file1.delete()
	}

	fun good1(request: HttpServletRequest) {
		val name = request.getParameter("name")				// 외부 입력

		val filter = Regex("[./\\\\&]").replace(name, "")
		val filepath = "/home/user/$filter"

		val file1 = File(filepath)							// good
		file1.delete()
	}

	fun good2(request: HttpServletRequest) {
		val name = request.getParameter("name")				// 외부 입력

		if(Regex("[./\\\\&]").matches(name)) {
			val filepath = "/home/user/$name"

			val file1 = File(filepath)						// good
			file1.delete()
		}
	}
}