#include "DTOProviderFromParser.h"

DTOProviderFromParser::DTOProviderFromParser(std::unique_ptr<Parser> _parserPtr) noexcept : parserPtr(std::move(_parserPtr)){}

std::unique_ptr<CommandDTO> DTOProviderFromParser::getDTO() noexcept{
    return parserPtr->parseWhileNotDTO();
}