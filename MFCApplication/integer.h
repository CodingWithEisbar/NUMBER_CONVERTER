#pragma once

#include <string>
#include "binary.h"

class integer {
private:
	binary _operator;
	std::string _bin_value;
	int _i32_value;
	int16_t _i16_value;
	int8_t _i8_value;
public:
	std::string integer_to_binary(const int&);
	std::string short_to_binary(const int16_t&);
	std::string char_to_binary(const int8_t&);
	std::string unsigned_int_to_binary(const int&, int);
	int binary_to_integer(const std::string&);
	int16_t binary_to_short(const std::string&);
	int8_t binary_to_char(const std::string&);
	unsigned int binary_to_unsigned_int(const std::string&, int);
};