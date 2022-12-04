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
    return "Incorrect arguments for member Copy::redo(begin, end) ";
}

const char* IncorrectArgumentsInPasteRedo::what() const noexcept {
    return "Incorrect arguments for member Paste::redo(position) ";
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

const char*UndoEditorException::what() const noexcept {
    return "All commands is already canceled ";
}

const char*RedoEditorException::what() const noexcept {
    return "No command for redo";
}

