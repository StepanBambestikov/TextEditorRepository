#include "CommandCreator.h"
#include "Creators.h"

std::unique_ptr<CommandCreator> CommandCreator::createCreator(std::unique_ptr<CommandDTO> _dtoPtr){
    if (!_dtoPtr){
        throw IncorrectArgumentsInCreateCreator();
    }
    auto commandName = _dtoPtr->getCommandName();

    if (commandName == Commands::DELETE){
        return std::make_unique<DeleteCreator>(*_dtoPtr);
    }
    else if (commandName == Commands::INSERT){
        return std::make_unique<InsertCreator>(*_dtoPtr);
    }
    else if (commandName == Commands::PASTE){
        return std::make_unique<PasteCreator>(*_dtoPtr);
    }
    else if (commandName == Commands::COPY){
        return std::make_unique<CopyCreator>(*_dtoPtr);
    }
    else if (commandName == Commands::UNDO){
        return std::make_unique<UndoCreator>(*_dtoPtr);
    }
    else if (commandName == Commands::REDO){
        return std::make_unique<RedoCreator>(*_dtoPtr);
    }
    else{
        throw IncorrectArgumentsInCreateCreator();
    }
}
