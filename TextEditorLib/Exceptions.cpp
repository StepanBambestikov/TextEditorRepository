#include "Exceptions.h"

const char* IncorrectArgumentsGetStringInRange::what() const noexcept {
    return "Incorrect arguments for member getSubStringInRange(begin, end) ";
}

const char* IncorrectArgumentsPasteInPosition::what() const noexcept {
    return "Incorrect arguments for member pasteInPosition(position) ";
}

const char* IncorrectArgumentsdeleteStringInRange::what() const noexcept {
    return "Incorrect arguments for member deleteStringInRange(begin, end) ";
}

const char* IncorrectArgumentsInCopyRedo::what() const noexcept {
    return "Incorrect arguments for member Copy::tryRedo(begin, end) ";
}

const char* IncorrectArgumentsInPasteRedo::what() const noexcept {
    return "Incorrect arguments for member Paste::tryRedo(position) ";
}

const char*IncorrectArgumentsInCreateCreator::what() const noexcept {
    return "Cannot downcast given value to known Commands";
}

const char*IncorrectArgumentsForCopyCreation::what() const noexcept {
    return "Incorrect arguments for copy creation in CopyCreator ";
}

const char*IncorrectArgumentsForPasteCreation::what() const noexcept {
    return "Incorrect arguments for paste creation in CopyCreator ";
}

const char*IncorrectArgumentsForInsertCreation::what() const noexcept {
    return "Incorrect arguments for insert creation in CopyCreator ";
}

const char*IncorrectArgumentsForDeleteCreation::what() const noexcept {
    return "Incorrect arguments for delete creation in DeleteCreator ";
}

const char*NullPtrCommandException::what() const noexcept {
    return "Command ptr in StringEditor::tryAddAndExecuteCommand(std::unique_ptr<CommandInterface>) must be valid";
}

const char*UndoEditorException::what() const noexcept {
    return "All commands is already canceled ";
}

const char*RedoEditorException::what() const noexcept {
    return "No command for tryRedo";
}

const char*InvalidCreatorException::what() const noexcept {
    return "invalid creator provided in CommandListExecutor::runAllAndGetString()";
}
/**/
const char*InvalidDTOForCopyCreator::what() const noexcept {
    return "Invalid DTO in CopyCreator::CopyCreator(CommandDTO dto)";
}

const char*InvalidDTOForPasteCreator::what() const noexcept {
    return "Invalid DTO in PasteCreator::PasteCreator(CommandDTO dto)";
}

const char*InvalidDTOForInsertCreator::what() const noexcept {
    return "Invalid DTO in InsertCreator::InsertCreator(CommandDTO dto)";
}

const char*InvalidDTOForDeleteCreator::what() const noexcept {
    return "Invalid DTO in DeleteCreator::DeleteCreator(CommandDTO dto)";
}

const char*InvalidDTOForUndoCreator::what() const noexcept {
    return "Invalid DTO in UndoCreator::UndoCreator(CommandDTO dto)";
}

const char*InvalidDTOForRedoCreator::what() const noexcept {
    return "Invalid DTO in RedoCreator::RedoCreator(CommandDTO dto)";
}

