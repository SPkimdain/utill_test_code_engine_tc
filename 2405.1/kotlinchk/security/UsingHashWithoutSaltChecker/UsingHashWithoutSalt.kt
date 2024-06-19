package testcase.rule.security.UsingHashWithoutSaltChecker

import java.security.MessageDigest

object TestCase {
	fun violation(password: String): ByteArray? {
		val digest = MessageDigest.getInstance("SHA-256")
		digest.reset()
		return digest.digest(password.toByteArray())			// @violation
	}

	fun good(password: String, salt: ByteArray): ByteArray? {
		val digest = MessageDigest.getInstance("SHA-256")
		digest.reset()
		digest.update(salt)
		return digest.digest(password.toByteArray())			// good
	}
}