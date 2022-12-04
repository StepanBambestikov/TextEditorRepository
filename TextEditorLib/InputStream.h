#pragma once
#include <istream>

class InputStream final{
public:
    InputStream(std::unique_ptr<std::istream> _is);
    std::unique_ptr<std::istream> is;
};