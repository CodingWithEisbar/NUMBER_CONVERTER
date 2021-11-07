#include "pch.h"
#include "ieee754.h"
#include "binary.h"
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

long double ieee754::binary_to_float(const std::string& value) {
	this->_bin_value = value;
    unsigned int sign = (_bin_value[0] == '1'), exponnet = _operator.decimal_get(value, 1, 8);
    std::string  mantissa = _sub_operator.strip(_bin_value, 9, 32);
    long double out = 1;
    int str_len = mantissa.length();
    for (int i = 0; i < str_len; i++) {
        out += (mantissa[i] == '1' ? 1 : 0) * pow(2, -(i + 1));
    }
    out *= pow(2, exponnet - 127);
    return (sign ? -out : out);
}

long double ieee754::binary_to_double(const std::string& value) {
    this->_bin_value = value;
    unsigned int sign = (_bin_value[0] == '1'), exponnet = _operator.decimal_get(value, 1, 11);
    std::string  mantissa = _sub_operator.strip(_bin_value, 12, 64);
    long double out = 1;
    int str_len = mantissa.length();
    for (int i = 0; i < str_len; i++) {
        out += (mantissa[i] == '1' ? 1 : 0) * pow(2, -(i + 1));
    }
    long double pow_value = pow(2, exponnet - 1023);
    out *= pow_value;
    return (sign ? -out : out);
}

std::string ieee754::float_to_binary(const float& value) {
    this->_i32_value = value;
    std::string temp = _operator.binary_get(_i32_value);
    //get exponent
    int iter = 0; int length = temp.length();
    while (temp[iter] != '.' && iter < length) {
        iter++;
    }
    int exponent = iter - 1 + 127;
    // generate ieee 754
    std::stringstream out; out << (_i32_value < 0) << _operator.binary_get(exponent, 8);
    //add mantissa
    iter = 1;
    while (iter < length) {
        if (temp[iter] == '.') { iter++; continue; }
        out << temp[iter];
        iter++;
    }
    std::string result = out.str();

    if (result.length() < 32)
        while (result.length() != 32) { out << 0; result = out.str(); }
    else
        if (result.length() > 32) result.erase(result.begin() + 32, result.end());

    return result;
}

std::string ieee754::double_to_binary(const double& value) {
    this->_i64_value = value;
    std::string temp = _operator.binary_get(_i64_value);
    //get exponent
    int iter = 0; int length = temp.length();
    while (temp[iter] != '.' && iter < length)
        iter++;

    int exponent = iter - 1 + 1023;
    // generate ieee 754
    std::stringstream out; out << (_i64_value < 0) << _operator.binary_get(exponent, 11);
    //add mantissa
    iter = 1;
    while (iter < length) {
        if (temp[iter] == '.') { iter++; continue; }
        out << temp[iter];
        iter++;
    }
    std::string result = out.str();
    if (result.length() < 64)
        while (result.length() != 64) { out << 0; result = out.str(); }
    else
        if (result.length() > 64) result.erase(result.begin() + 64, result.end());

    return result;
}