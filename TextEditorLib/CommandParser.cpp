#include "CommandParser.h"


static std::unique_ptr<CommandDTO> parseStreamToCopyDTO(InputStream& stream){
    int idx1 = 0;
    int idx2 = 0;
    if (!(*stream.is >> idx1)){
        return {};
    }
    if (!(*stream.is >> idx2)){
        return {};
    }
    return std::make_unique<CopyDTO>(idx1, idx2);
}

static std::unique_ptr<CommandDTO> parseStreamToPasteDTO(InputStream& stream){
    int idx = 0;
    if (!(*stream.is >> idx)){
        return {};
    }
    return std::make_unique<PasteDTO>(idx);
}

static std::unique_ptr<CommandDTO> parseStreamToInsertDTO(InputStream& stream){
    std::string word;
    int idx = 0;
    *stream.is >> word;
    if (word.empty()){
        return {};
    }
    if (!(*stream.is >> idx)){
        return {};
    }
    return std::make_unique<InsertDTO>(StringBuffer(word), idx);
}

static std::unique_ptr<CommandDTO> parseStreamToDeleteDTO(InputStream& stream){
    int idx1 = 0;
    int idx2 = 0;
    if (!(*stream.is >> idx1)){
        return {};
    }
    if (!(*stream.is >> idx2)){
        return {};
    }
    return std::make_unique<DeleteDTO>(idx1, idx2);
}

static std::unique_ptr<CommandDTO> parseStreamToUndoDTO(InputStream& stream){
    return std::make_unique<UndoDTO>();
}

static std::unique_ptr<CommandDTO> parseStreamToRedoDTO(InputStream& stream){
    return std::make_unique<RedoDTO>();
}


std::unique_ptr<CommandDTO> parseStreamToDTO(InputStream stream){
    std::string nameOfType;
    *stream.is >> nameOfType;
    if (nameOfType == "redo"){
        return parseStreamToRedoDTO(stream);
    }
    else if (nameOfType == "undo"){
        return parseStreamToUndoDTO(stream);
    }
    else if (nameOfType == "copy") {
        return parseStreamToCopyDTO(stream);
    }
    else if (nameOfType == "paste"){
        return parseStreamToPasteDTO(stream);
    }
    else if (nameOfType == "insert"){
        return parseStreamToInsertDTO(stream);
    }
    else if (nameOfType == "delete"){
        return parseStreamToDeleteDTO(stream);
    }
    else{
        return {};
    }
}
