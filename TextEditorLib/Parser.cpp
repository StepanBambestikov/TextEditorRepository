#include "Parser.h"

namespace {
    std::unique_ptr<CommandDTO> parseStreamToCopyDTO(InputStream& stream){
        int idx1 = 0;
        int idx2 = 0;
        if (!(*stream.is >> idx1)){
            return {};
        }
        if (!(*stream.is >> idx2)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::COPY);
        DTOptr->setIdx1(idx1);
        DTOptr->setIdx2(idx2);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToPasteDTO(InputStream& stream){
        int idx = 0;
        if (!(*stream.is >> idx)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::PASTE);
        DTOptr->setIdx1(idx);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToInsertDTO(InputStream& stream){
        std::string word;
        int idx = 0;
        *stream.is >> word;
        if (word.empty()){
            return {};
        }
        if (!(*stream.is >> idx)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::INSERT);
        DTOptr->setString(StringBuffer(word));
        DTOptr->setIdx1(idx);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToDeleteDTO(InputStream& stream){
        int idx1 = 0;
        int idx2 = 0;
        if (!(*stream.is >> idx1)){
            return {};
        }
        if (!(*stream.is >> idx2)){
            return {};
        }
        auto DTOptr = std::make_unique<CommandDTO>(Commands::DELETE);
        DTOptr->setIdx1(idx1);
        DTOptr->setIdx2(idx2);
        return DTOptr;
    }

    std::unique_ptr<CommandDTO> parseStreamToUndoDTO(InputStream& stream){
        return std::make_unique<CommandDTO>(Commands::UNDO);
    }

    std::unique_ptr<CommandDTO> parseStreamToRedoDTO(InputStream& stream){
        return std::make_unique<CommandDTO>(Commands::REDO);
    }
}

std::unique_ptr<CommandDTO> Parser::parseStringToDTO(){
    auto strStream = getStringStream();
    std::string nameOfType;
    *strStream.is >> nameOfType;
    //tryUndo, tryRedo
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

std::unordered_map<Commands, std::string> Parser::createCommandNamesMap(){
    std::unordered_map<Commands, std::string> _commandNamesMap;
    _commandNamesMap[Commands::REDO] = "redo";
    _commandNamesMap[Commands::UNDO] = "undo";
    _commandNamesMap[Commands::COPY] = "copy";
    _commandNamesMap[Commands::PASTE] = "paste";
    _commandNamesMap[Commands::INSERT] = "insert";
    _commandNamesMap[Commands::DELETE] = "delete";
    return _commandNamesMap;
}

Parser::Parser(InputStream& _is) noexcept : is(_is) {}

std::unordered_map<Commands, std::string> Parser::commandNamesMap = createCommandNamesMap();

bool Parser::eof() const noexcept{
    return is.is->eof();
}

InputStream Parser::getStringStream() noexcept{
    std::string str;
    std::getline(*is.is, str);
    return {std::make_unique<std::stringstream>(str)};
}