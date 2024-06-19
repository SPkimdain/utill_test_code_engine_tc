package testcase.rule.security.ExposureOfSystemDataChecker

import java.io.File
import java.io.FileReader
import java.io.IOException

object TestCase {
	fun violation1(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {
			e.printStackTrace()					// @violation
		}
	}

	fun violation2(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {
			println(e)							// @violation
			println("Error: " + e)				// @violation
			println("Error: " + e + " Hello")	// @violation
			println("Error: $e Hello")			// @violation
		}
	}

	fun good(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {
			logger.error("IOException")			// good
		}
	}
}