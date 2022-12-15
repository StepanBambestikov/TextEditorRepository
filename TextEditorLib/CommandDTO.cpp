#include "CommandDTO.h"

CommandDTO::CommandDTO(Commands _command)  noexcept : commandName(_command) {}

void CommandDTO::setString(StringBuffer _string) noexcept{
    string = std::move(_string);
}

void CommandDTO::setIdx1(size_t _idx1) noexcept{
    idx1 = _idx1;
}
void CommandDTO::setIdx2(size_t _idx2) noexcept{
    idx2 = _idx2;
}

Commands CommandDTO::getCommandName() const noexcept{
    return commandName;
}

std::optional<StringBuffer> CommandDTO::getString() const noexcept{
    return string;
}
std::optional<size_t> CommandDTO::getIdx1() const noexcept{
    return idx1;
}
std::optional<size_t> CommandDTO::getIdx2() const noexcept{
    return idx2;
}