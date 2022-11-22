#include "Parser.h"

Parser::Parser(std::istream& _is) noexcept : is(_is) {}

bool Parser::eof() const noexcept{ return is.eof(); }

std::optional<std::vector<std::string>> Parser::getSplitString() noexcept{
    std::vector<std::string> partsOfString;
    std::string str;
    std::string word;
    std::getline(is, str);
    std::stringstream stream(str);
    while ( std::getline(stream, word, ' ') ){
        partsOfString.push_back(word);
    }
    return partsOfString;
}
