package testcase.rule.security.WeakXmlTransformersSecurityChecker

import javax.xml.XMLConstants
import javax.xml.transform.Transformer
import javax.xml.transform.TransformerFactory

object TestCase {
	fun violation1() {
		val transformer = TransformerFactory.newInstance().newTransformer()
		transformer.transform(input, result)			// @violation
	}

	fun violation2() {
		val factory1 = TransformerFactory.newInstance()
		factory1.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "")
		factory1.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "")

		val factory2 = TransformerFactory.newInstance()

		val transformer = factory2.newTransformer()
		transformer.transform(input, result)			// @violation
	}

	fun violation3() {
		val factory = TransformerFactory.newInstance()
		factory.setAttribute(XMLConstants.XML_NS_URI, "")

		val transformer = factory.newTransformer()
		transformer.transform(input, result)			// @violation
	}

	fun good1() {
		val factory = TransformerFactory.newInstance()
		factory.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "")
		factory.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "")

		val transformer = factory.newTransformer()
		transformer.transform(input, result)			// good
	}

	fun good2() {
		val factory = TransformerFactory.newInstance()
		factory.setFeature(XMLConstants.FEATURE_SECURE_PROCESSING, true)

		val transformer = factory.newTransformer()
		transformer.transform(input, result)			// good
	}
}