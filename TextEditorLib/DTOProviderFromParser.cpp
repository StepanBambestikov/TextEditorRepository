#include "DTOProviderFromParser.h"

DTOProviderFromParser::DTOProviderFromParser(std::unique_ptr<Parser> _parserPtr) noexcept : parserPtr(std::move(_parserPtr)){}

std::unique_ptr<CommandDTO> DTOProviderFromParser::getDTO() noexcept{
    while (!parserPtr->eof()){
        auto ptr = parserPtr->parseStringToDTO();
        if (ptr){
            return {std::move(ptr)};
        }
    }
    return {};
}

bool DTOProviderFromParser::hasNext() const noexcept{
    return !parserPtr->eof();
}