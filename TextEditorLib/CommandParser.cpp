#include "CommandParser.h"


static std::optional<std::unique_ptr<CommandDTO>> parseStreamToCopyDTO(InputStream stream){
    int idx1;
    int idx2;
    if (!stream.is >> idx1){
        return {};
    }
    if (!stream.is >> idx2){
        return {};
    }
    return {CopyDTO(idx1, idx2)};
}

static std::optional<std::unique_ptr<CommandDTO>> parseStreamToPasteDTO(InputStream stream){
    int idx;
    if (!stream.is >> idx){
        return {};
    }
    return {PasteDTO(idx)};
}

static std::optional<std::unique_ptr<CommandDTO>> parseStreamToInsertDTO(InputStream stream){
    std::string word;
    int idx;
    stream.is >> word;
    if (word.empty()){
        return {};
    }
    if (!stream.is >> idx){
        return {};
    }
    return {InsertDTO(word, idx)};
}

static std::optional<std::unique_ptr<CommandDTO>> parseStreamToDeleteDTO(InputStream stream){
    int idx1;
    int idx2;
    if (!stream.is >> idx1){
        return {};
    }
    if (!stream.is >> idx2){
        return {};
    }
    return {DeleteDTO(idx1, idx2)};
}


std::optional<std::unique_ptr<CommandDTO>> parseStreamToDTO(InputStream stream){
    std::string nameOfType;
    stream.is >> nameOfType;
    if (nameOfType == "Copy") {
        return parseStreamToCopyDTO(stream);
    }
    else if (nameOfType == "Paste"){
        return parseStreamToPasteDTO(stream);
    }
    else if (nameOfType == "Insert"){
        return parseStreamToInsertDTO(stream);
    }
    else if (nameOfType == "Delete"){
        return parseStreamToDeleteDTO(stream);
    }
    else{
        return {};
    }
}
