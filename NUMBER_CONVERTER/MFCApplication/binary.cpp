#include "pch.h"
#include "binary.h"

#include <sstream>
#include <vector>
#include <iostream>


std::string sub_operation::strip(std::string value, int start, int end) {
    std::stringstream temp;
    for (int i = start; i <= end; i++)
        temp << value[i];
    return temp.str();
}

float sub_operation::divide_ffraction(float value, int* integral) {
    std::stringstream temp; temp << (value < 0 ? std::to_string(-value) : std::to_string(value));
    std::string temp2;
    std::getline(temp, temp2, '.');
    *integral = stoi(temp2);
    std::getline(temp, temp2);
    float fractional = stoi(temp2) / pow(10, temp2.length());
    return fractional;
}

double sub_operation::divide_dfraction(double value, int* integral) {
    std::stringstream temp; temp << (value < 0 ? std::to_string(-value) : std::to_string(value));
    std::string temp2;
    std::getline(temp, temp2, '.');
    *integral = stoi(temp2);
    std::getline(temp, temp2);
    float fractional = stoi(temp2) / pow(10, temp2.length());
    return fractional;
}

bool sub_operation::is_number(std::string value) {
    int dot = 0;
    for (int i = 0; i < value.length(); i++) {
        if (dot && value[i] == '.') return 0;
        if (!dot && value[i] == '.') { dot++; continue;}
        if (!std::isdigit(value[i])) return 0;
    }
    return 1;
}


//=========================================================================================================
std::string binary::build_binary(bool* start, bool* end) {
    std::stringstream out;
    bool* temp = start;
    while (temp != end) {
        out << std::to_string(*temp);
        temp++;
    }
    return out.str();
}

std::string binary::build_binary(std::vector<bool> arr) {
    std::stringstream out;
    for (auto i : arr)
        out << std::to_string(i);

    return out.str();
}

std::string binary::build_binary(std::string value, int bits) {
    int length = value.length();
    std::string result = value;
    if (length < bits) {
        std::stringstream out(value);
        for (int i = 0; i < bits - length; i++) {
            out << "0";
        }
        out << value;
        result = out.str();
    }

    if (length > bits) result.erase(result.begin() + bits, result.end());

    for (int i = 0; i < result.length(); i++) {
        if (result[i] != '0') {
            if (result[i] != '1') {
                std::stringstream out(value);
                for (int i = 0; i < result.length(); i++) {
                    out << "0";
                }
                result = out.str();
                break;
            }
        }
    }
    return result;
}

std::string binary::add(std::string a, std::string b) {
    std::string result = "";
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;
    while (size_a >= 0 || size_b >= 0 || temp == 1) {
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
        result = char(temp % 2 + '0') + result;
        temp /= 2;
        size_a--; size_b--;
    }
    return result;
}

std::string binary::ones_complement(std::string value) {
    if (value[0] == '1') {
        for (int i = 1; i < value.length(); i++)
            value[i] = (value[i] == '1' ? '0' : '1');
    }
    return value;
}

std::string binary::twos_complement(std::string value) {
    std::string result = ones_complement(value);
    result = add(result, "1");
    return result;
}

std::string binary::binary_get(int dec, int bit) {
    std::stringstream out;
    for (int i = bit - 1; i >= 0; i--) {
        out << ((dec >> i) & 1);
    }
    std::string result;
    return result = out.str();
}

std::string binary::binary_get(int dec) {
    std::stringstream out;
    std::vector<int> i;
    while (dec) {
        i.push_back(dec % 2);
        dec /= 2;
    }
    for (int j = i.size() - 1; j >= 0; j--)
        out << i[j];
    return out.str();
}

std::string binary::binary_get(float value) {
    std::stringstream bin;
    int integral; float fractional;
    fractional = _operation.divide_ffraction(value, &integral);

    std::string integral_bin = binary_get(integral);
    bin << integral_bin << '.';
    int iter = 1;
    while (fractional != 1.0f && iter != 23) {
        fractional *= 2.0f;
        bin << (fractional >= 1);
        fractional = _operation.divide_ffraction(fractional, &integral);
        iter++;
    }
    return bin.str();
}

std::string binary::binary_get(double value) {
    std::stringstream bin;
    int integral; double fractional;
    fractional = _operation.divide_dfraction(value, &integral);

    std::string integral_bin = binary_get(integral);
    bin << integral_bin << '.';
    int iter = 1;
    while (fractional != 1.0f && iter != 52) {
        fractional *= 2.0f;
        bin << (fractional >= 1);
        fractional = _operation.divide_dfraction(fractional, &integral);
        iter++;
    }
    return bin.str();

}

unsigned int binary::decimal_get(std::string bin, int start_pos, int end_pos) {
    unsigned int out = 0;
    for (int i = end_pos; i >= start_pos; i--) {
        out += (bin[i] == '1') * pow(2, end_pos - i);
    }
    return out;
}

void binary::print(std::string bin) {
    int j = 1;
    for (int i = 0; i < bin.length(); i++) {
        std::cout << bin[i];
        if (j == 8) { j = 0; std::cout << " "; }
        j++;
    }
}

std::string binary::format(const std::string& bin) {
    std::stringstream out;
    int j = 1;
    for (int i = 0; i < bin.length(); i++) {
        out << bin[i];
        if (j == 8) { j = 0; out << " "; }
        j++;
    }
    return out.str();
}