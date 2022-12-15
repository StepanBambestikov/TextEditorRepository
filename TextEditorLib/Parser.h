#pragma once
#include <sstream>
#include <istream>
#include <string>
#include <unordered_map>
#include "CommandDTO.h"
#include "Command.h"
#include "InputStream.h"

class Parser final{
public:
    explicit Parser(InputStream& _is) noexcept;
    std::unique_ptr<CommandDTO> parseStringToDTO();
    [[nodiscard]] bool eof() const noexcept;
private:
    static std::unordered_map<Commands, std::string> createCommandNamesMap();
    static std::unordered_map<Commands, std::string> commandNamesMap;
    InputStream& is;
    InputStream getStringStream() noexcept;
};