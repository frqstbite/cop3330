#ifndef _EVALUATE_RPN_HPP
#define _EVALUATE_RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Stack.h"

template <typename T>
T evaluateRPN(const std::string& expr) {
	Stack<T> operands;	// The stack we use for the algorithm

	// Tokenize by consuming from a string-based stream
	std::istringstream stream(expr);
	std::string token;
	while (stream >> token) {
		// Handle operators
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			T rhs = operands.pop();
			T lhs = operands.pop();
			T result;

			//std::cout << "PERFORMING OPERATION " << lhs << ' ' << token.at(0)
			//		  << ' ' << rhs << " = ";

			switch (token.at(0)) {
				case '+':
					result = lhs + rhs;
					break;
				case '-':
					result = lhs - rhs;
					break;
				case '*':
					result = lhs * rhs;
					break;
				case '/':
					result = lhs / rhs;
					break;
			}

			//std::cout << result << std::endl;

			operands.push(result);
			continue;
		}

		// We can use stringstream to handle the conversion between std::string
		// and T. This is kind of stupid, but it's the easiest way.
		std::istringstream cast_stream(token);
		T converted;
		cast_stream >> converted;
		operands.push(converted);
	}

	return operands.top();
}

#endif
