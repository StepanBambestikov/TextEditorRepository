#pragma once
#include "string"
#include "Exceptions.h"

class StringBuffer final{
public:
    StringBuffer() noexcept;
    explicit StringBuffer(std::string _str) noexcept;
    [[nodiscard]] StringBuffer getSubStringInRange(size_t begin, size_t end) const;
    [[nodiscard]] const std::string& operator*() const noexcept;
    [[nodiscard]] const std::string& getString() const noexcept;
    [[nodiscard]] size_t size() const noexcept;
    void pasteInPosition(size_t position, const StringBuffer& strBuf);
    void deleteStringInRange(size_t begin, size_t end);
private:
    std::string str;
};