#include "CommandCreator.h"
#include "Creators.h"

std::unique_ptr<CommandCreator> CommandCreator::createCreator(std::unique_ptr<CommandDTO> _DTOptr){
    if (!_DTOptr){
        throw IncorrectArgumentsInCreateCreator();
    }
    else if (auto copyPtr = dynamic_cast<CopyDTO*>(_DTOptr.get())){
        return std::make_unique<CopyCreator>(*copyPtr);
    }
    else if (auto pastePtr = dynamic_cast<PasteDTO*>(_DTOptr.get())){
        return std::make_unique<PasteCreator>(*pastePtr);
    }
    else if (auto insertPtr = dynamic_cast<InsertDTO*>(_DTOptr.get())){
        return std::make_unique<InsertCreator>(*insertPtr);
    }
    else if (auto deletePtr = dynamic_cast<DeleteDTO*>(_DTOptr.get())){
        return std::make_unique<DeleteCreator>(*deletePtr);
    }
    else if (auto undoPtr = dynamic_cast<UndoDTO*>(_DTOptr.get())){
        return std::make_unique<UndoCreator>(*undoPtr);
    }
    else if (auto redoPtr = dynamic_cast<RedoDTO*>(_DTOptr.get())){
        return std::make_unique<RedoCreator>(*redoPtr);
    }
    else{
        throw IncorrectArgumentsInCreateCreator();
    }
}
