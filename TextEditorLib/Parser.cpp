#include "Parser.h"


Parser::Parser(InputStream& _is) noexcept : is(_is) {}

bool Parser::eof() const noexcept{ return is.is->eof(); }

InputStream Parser::getStringStream() noexcept{
    std::string str;
    std::getline(*is.is, str);
    return {std::make_unique<std::stringstream>(str)};
}
