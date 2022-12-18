#include "CommandCreator.h"
#include "Creators.h"

std::unique_ptr<CommandCreator> CommandCreator::createCreator(std::unique_ptr<CommandDTO> _dtoPtr){
    if (!_dtoPtr){
        throw IncorrectArgumentsInCreateCreator();
    }
    auto commandName = _dtoPtr->getCommandName();

    switch (commandName){
        case Commands::DELETE:
            return std::make_unique<DeleteCreator>(*_dtoPtr);
        case Commands::INSERT:
            return std::make_unique<InsertCreator>(*_dtoPtr);
        case Commands::PASTE:
            return std::make_unique<PasteCreator>(*_dtoPtr);
        case Commands::COPY:
            return std::make_unique<CopyCreator>(*_dtoPtr);
        case Commands::UNDO:
            return std::make_unique<UndoCreator>(*_dtoPtr);
        case Commands::REDO:
            return std::make_unique<RedoCreator>(*_dtoPtr);
        default:
            throw IncorrectArgumentsInCreateCreator();
    }
}
