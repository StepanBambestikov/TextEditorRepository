#include "Parser.h"

namespace {
    std::unique_ptr<CommandDTO> parseStreamToCopyDTO(std::istream& stream){
        int idx1 = 0;
        int idx2 = 0;
        if (!(stream >> idx1)){
            return {};
        }
        if (!(stream >> idx2)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::COPY);
        DTOptr->setIdx1(idx1);
        DTOptr->setIdx2(idx2);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToPasteDTO(std::istream& stream){
        int idx = 0;
        if (!(stream >> idx)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::PASTE);
        DTOptr->setIdx1(idx);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToInsertDTO(std::istream& stream){
        std::string word;
        int idx = 0;
        stream >> word;
        if (word.empty()){
            return {};
        }
        if (!(stream >> idx)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::INSERT);
        DTOptr->setString(StringBuffer(word));
        DTOptr->setIdx1(idx);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToDeleteDTO(std::istream& stream){
        int idx1 = 0;
        int idx2 = 0;
        if (!(stream >> idx1)){
            return {};
        }
        if (!(stream >> idx2)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::DELETE);
        DTOptr->setIdx1(idx1);
        DTOptr->setIdx2(idx2);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToUndoDTO(std::istream& stream){
        return std::make_unique<CommandDTO>(Commands::UNDO);
    }

    std::unique_ptr<CommandDTO> parseStreamToRedoDTO(std::istream& stream){
        return std::make_unique<CommandDTO>(Commands::REDO);
    }
}

std::unique_ptr<CommandDTO> Parser::parseStringToDTO(){
    std::string str;
    std::getline(is, str);
    if (str.empty()){
        return {};
    }
    auto strStream = std::stringstream(str);
    std::string nameOfType;
    strStream >> nameOfType;
    if (nameOfType == commandNamesMap[Commands::REDO]){
        return parseStreamToRedoDTO(strStream);
    }
    else if (nameOfType == commandNamesMap[Commands::UNDO]){
        return parseStreamToUndoDTO(strStream);
    }
    else if (nameOfType == commandNamesMap[Commands::COPY]) {
        return parseStreamToCopyDTO(strStream);
    }
    else if (nameOfType == commandNamesMap[Commands::PASTE]){
        return parseStreamToPasteDTO(strStream);
    }
    else if (nameOfType == commandNamesMap[Commands::INSERT]){
        return parseStreamToInsertDTO(strStream);
    }
    else if (nameOfType == commandNamesMap[Commands::DELETE]){
        return parseStreamToDeleteDTO(strStream);
    }
    else{
        return {};
    }
}

std::unique_ptr<CommandDTO> Parser::parseWhileNotDTO(){
    while (!is.eof()){
        auto ptr = parseStringToDTO();
        if (ptr){
            return ptr;
        }
    }
    return {};
}

std::unordered_map<Commands, std::string> Parser::createCommandNamesMap() noexcept{
    std::unordered_map<Commands, std::string> _commandNamesMap;
    _commandNamesMap[Commands::REDO] = "redo";
    _commandNamesMap[Commands::UNDO] = "undo";
    _commandNamesMap[Commands::COPY] = "copy";
    _commandNamesMap[Commands::PASTE] = "paste";
    _commandNamesMap[Commands::INSERT] = "insert";
    _commandNamesMap[Commands::DELETE] = "delete";
    return _commandNamesMap;
}

Parser::Parser(std::istream& _is) noexcept : is(_is) {}

std::unordered_map<Commands, std::string> Parser::commandNamesMap = createCommandNamesMap();
