package testcase.rule.security.ServerSideRequestForgeryChecker

import java.net.HttpURLConnection
import java.net.URL
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation(request: HttpServletRequest) {
		val urlText = request.getParameter("url")
		val url = URL(urlText)
		val connection = url.openConnection() as HttpURLConnection		// @violation
	}

	fun good1(request: HttpServletRequest) {
		val urlWhiteListed = "https://example.com/"
		val urlText = request.getParameter("url")
		if (urlText.startsWith(urlWhiteListed)) {
			val url = URL(urlText)
			val connection = url.openConnection() as HttpURLConnection	// good
		}
	}

	val urlMap: Map<String, URL> = java.util.Collections.emptyMap();

	fun good2(request: HttpServletRequest) {
		val url1 = urlMap.get(request.getParameter("url"))
		val connection1 = url1?.openConnection() as HttpURLConnection	// good

		val url2 = urlMap[request.getParameter("url")]
		val connection2 = url2?.openConnection() as HttpURLConnection	// good
	}
}