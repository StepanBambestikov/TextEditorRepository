#pragma once
#include <istream>

class InputStream final{
public:
    InputStream(std::istream& _is);
    std::istream& is;
};