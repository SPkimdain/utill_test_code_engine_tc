package testcase.rule.security.UseOfInsufficientRandomValuesChecker

import java.security.SecureRandom
import java.util.*

object TestCase {
	fun violation1(n: Int) : Int {
		return (Math.random() * n).toInt()			// @violation
	}

	fun violation2(n: Int) : Int {
		val seed = System.currentTimeMillis();
		val random = Random(seed)					// @violation
		return random.nextInt(n)
	}

	fun good(n: Int) : Int {
		val random = SecureRandom()					// good
		return random.nextInt(n)
	}
}