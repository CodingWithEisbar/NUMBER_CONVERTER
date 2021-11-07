#pragma once

#include <string>
#include <vector>

class sub_operation {
public:
    std::string strip(std::string, int, int);
    float divide_ffraction(float, int*);
	double divide_dfraction(double, int*);
	bool is_number(std::string);
};

class binary {
private:
    sub_operation _operation;
public:
	std::string build_binary(bool*, bool*);
	std::string build_binary(std::vector<bool>);
	std::string build_binary(std::string, int);
	std::string add(std::string, std::string);
	std::string ones_complement(std::string);
	std::string twos_complement(std::string);
	std::string binary_get(int, int);
	std::string binary_get(int);
	std::string binary_get(float);
	std::string binary_get(double);
	unsigned int decimal_get(std::string, int, int);
	static void print(std::string);
	static std::string format(const std::string&);
};


