#pragma once

#include <string>
#include "binary.h"

class ieee754 {
private:
	binary _operator;
	sub_operation _sub_operator;
	std::string _bin_value;
	float _i32_value;
	double _i64_value;
public:
	float binary_to_float(const std::string&);
	double binary_to_double(const std::string&);
	std::string float_to_binary(const float&);
	std::string double_to_binary(const double&);
};