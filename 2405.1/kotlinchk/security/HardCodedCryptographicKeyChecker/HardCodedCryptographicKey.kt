package testcase.rule.security.HardCoded.CryptographicKeyChecker

import javax.crypto.Cipher
import javax.crypto.spec.SecretKeySpec

object TestCase {
	fun violation1(text: String): String {
		val key = "22df3023sf~2;asn!@#/>as"
		val bToEncrypt = text.toByteArray()
		val sKeySpec = SecretKeySpec(key.toByteArray(), "AES")				// @violation
		val aesCipher = Cipher.getInstance ("AES")
		aesCipher.init(Cipher.ENCRYPT_MODE, sKeySpec)
		val bCipherText = aesCipher.doFinal(bToEncrypt)
		return String(bCipherText)
	}

	fun violation2(text: String): String {
		val key = 1234567890
		val bToEncrypt = text.toByteArray()
		val sKeySpec = SecretKeySpec(key.toByteArray(), "AES")				// @violation
		val aesCipher = Cipher.getInstance ("AES")
		aesCipher.init(Cipher.ENCRYPT_MODE, sKeySpec)
		val bCipherText = aesCipher.doFinal(bToEncrypt)
		return String(bCipherText)
	}

	fun violation3(text: String): String {
		val key = byteArrayOf(72, 101, 108, 108, 111)
		val bToEncrypt = text.toByteArray()
		val sKeySpec = SecretKeySpec(key, "AES")							// @violation
		val aesCipher = Cipher.getInstance ("AES")
		aesCipher.init(Cipher.ENCRYPT_MODE, sKeySpec)
		val bCipherText = aesCipher.doFinal(bToEncrypt)
		return String(bCipherText)
	}

	fun good(text: String) {
		val key : String = getPassword("../key.ini")
		val decryptedKey = decrypt(key)
		val bToEncrypt = text.toByteArray()
		val sKeySpec = SecretKeySpec(decryptedKey.toByteArray(), "AES")		// good
		val aesCipher = Cipher.getInstance ("AES")
		aesCipher.init(Cipher.ENCRYPT_MODE, sKeySpec)
		val bCipherText = aesCipher.doFinal(bToEncrypt)
		return String(bCipherText)
	}
}