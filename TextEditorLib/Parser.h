#pragma once
#include <sstream>
#include <istream>
#include <string>
#include <optional>
#include <vector>

class Parser final{
public:
    explicit Parser(std::istream& _is) noexcept;
    std::optional<std::vector<std::string>> getSplitString() noexcept;
    [[nodiscard]] bool eof() const noexcept;
private:
    std::istream& is;
};

