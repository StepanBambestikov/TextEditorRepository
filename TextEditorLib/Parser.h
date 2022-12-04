#pragma once
#include <sstream>
#include <istream>
#include <string>
#include "InputStream.h"


class Parser final{
public:
    explicit Parser(InputStream& _is) noexcept;
    InputStream getStringStream() noexcept;
    [[nodiscard]] bool eof() const noexcept;
private:
    InputStream& is;
};