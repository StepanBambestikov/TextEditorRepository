#pragma once
#include <istream>

class InputStream final{
public:
    InputStream(std::unique_ptr<std::istream> _is) noexcept;
    std::unique_ptr<std::istream> is;
};