#pragma once
#include <sstream>
#include <istream>
#include <string>
#include <unordered_map>
#include "CommandDTO.h"
#include "Command.h"

class Parser final{
public:
    explicit Parser(std::istream& _is) noexcept;
    std::unique_ptr<CommandDTO> parseWhileNotDTO();
private:
    static std::unordered_map<Commands, std::string> createCommandNamesMap() noexcept;
    std::unique_ptr<CommandDTO> parseStringToDTO();
    static std::unordered_map<Commands, std::string> commandNamesMap;
    std::istream& is;
};