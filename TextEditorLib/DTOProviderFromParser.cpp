#include "DTOProvider.h"

DTOProviderFromParser::DTOProviderFromParser(std::shared_ptr<Parser> _parserPtr) : parserPtr(_parserPtr){}

std::unique_ptr<CommandDTO> DTOProviderFromParser::getDTO(){
    if (!parserPtr->eof()){
        auto ptr = parseStreamToDTO(parserPtr->getStringStream());
        if (ptr){
            return {std::move(ptr)};
        }
    }
    return {};
}

bool DTOProviderFromParser::hasNext() const{
    return !parserPtr->eof();
}