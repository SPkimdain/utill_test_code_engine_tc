//@checker NAMESPACE_IN_HEADER_SHOULD_BE_NAMED

#ifndef _NAMESPACE_IN_HEADER_SHOULD_BE_NAMED_HPP_
#define _NAMESPACE_IN_HEADER_SHOULD_BE_NAMED_HPP_

namespace { //@violation NAMESPACE_IN_HEADER_SHOULD_BE_NAMED
	int x;
}

#endif /* _NAMESPACE_IN_HEADER_SHOULD_BE_NAMED_HPP_ */
