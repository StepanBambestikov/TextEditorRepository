#pragma once
#include <optional>
#include "StringBuffer.h"
#include "Command.h"

class CommandDTO final{
public:
    CommandDTO(Commands _command) noexcept;

    void setString(StringBuffer _str) noexcept;
    void setIdx1(size_t _idx1) noexcept;
    void setIdx2(size_t _idx2) noexcept;

    [[nodiscard]] Commands getCommandName() const noexcept;
    [[nodiscard]] std::optional<StringBuffer> getString() const noexcept;
    [[nodiscard]] std::optional<size_t> getIdx1() const noexcept;
    [[nodiscard]] std::optional<size_t> getIdx2() const noexcept;
private:
    Commands commandName;
    std::optional<StringBuffer> string;
    std::optional<size_t> idx1;
    std::optional<size_t> idx2;
};