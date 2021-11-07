#include"pch.h"
#include "binary.h"
#include "integer.h"

#include <string>

std::string integer::integer_to_binary(const int& value) {
	this->_i32_value = value;
	std::string bin = _operator.binary_get(_i32_value, 32);
	return bin;
}

std::string integer::short_to_binary(const int16_t& value) {
	this->_i16_value = value;
	std::string bin = _operator.binary_get(_i16_value, 16);
	return bin;
}

std::string integer::char_to_binary(const int8_t& value) {
	this->_i8_value = value;
	std::string bin = _operator.binary_get(_i8_value, 8);
	return bin;
}

std::string integer::unsigned_int_to_binary(const int& value, int bits) {
	this->_i32_value = value;
	if (_i32_value < 0) _i32_value = 0;
	std::string bin = _operator.binary_get(_i32_value, bits);
	return bin;
}

int integer::binary_to_integer(const std::string& value) {
	this->_bin_value = value;
	if (_bin_value[0] == '1') _bin_value = _operator.twos_complement(_bin_value);
	int result = _operator.decimal_get(_bin_value, 1,31);
	return (_bin_value[0] == '1' ? -result : result);
}

int16_t integer::binary_to_short(const std::string& value) {
	this->_bin_value = value;
	if (_bin_value[0] == '1') _bin_value = _operator.twos_complement(_bin_value);
	int result = _operator.decimal_get(_bin_value, 1, 15);
	return (_bin_value[0] == '1' ? -result : result);
}

int8_t integer::binary_to_char(const std::string& value) {
	this->_bin_value = value;
	if (_bin_value[0] == '1') _bin_value = _operator.twos_complement(_bin_value);
	int result = _operator.decimal_get(_bin_value, 1, 7);
	return (_bin_value[0] == '1' ? -result : result);
}

unsigned int integer::binary_to_unsigned_int(const std::string& value, int bits) {
	this->_bin_value = value;
	int result = _operator.decimal_get(_bin_value, 0, bits - 1);
	return result;
}