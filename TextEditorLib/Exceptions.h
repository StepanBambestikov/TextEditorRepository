#pragma once
#include <exception>

class StringBufferException : public std::exception{};

class IncorrectArgumentsGetStringInRange final : public StringBufferException{
    const char *what() const noexcept override;
};

class IncorrectArgumentsPasteInPosition final : public StringBufferException{
    const char *what() const noexcept override;
};

class IncorrectArgumentsdeleteStringInRange final : public StringBufferException{
    const char *what() const noexcept override;
};

class CommandException : public std::exception{};

class CopyException : public CommandException{};

class IncorrectArgumentsInCopyRedo final : public CopyException{
    const char *what() const noexcept override;
};

class PasteException : public CommandException{};

class IncorrectArgumentsInPasteRedo final : public PasteException{
    const char *what() const noexcept override;
};

class CreatorException : public std::exception{};

class IncorrectArgumentsInCreateCreator final : public CreatorException{
    const char *what() const noexcept override;
};

class CopyCreatorException : public CreatorException{};

class InvalidDTOForCopyCreator final : public CopyCreatorException{
    const char *what() const noexcept override;
};

class IncorrectArgumentsForCopyCreation final : public CopyCreatorException{
    const char *what() const noexcept override;
};

class PasteCreatorException : public CreatorException{};

class InvalidDTOForPasteCreator final : public PasteCreatorException{
    const char *what() const noexcept override;
};

class IncorrectArgumentsForPasteCreation final : public PasteCreatorException{
    const char *what() const noexcept override;
};

class InsertCreatorException : public CreatorException{};

class InvalidDTOForInsertCreator final : public InsertCreatorException{
    const char *what() const noexcept override;
};

class IncorrectArgumentsForInsertCreation final : public InsertCreatorException{
    const char *what() const noexcept override;
};

class DeleteCreatorException : public CreatorException{};

class InvalidDTOForDeleteCreator final : public DeleteCreatorException{
    const char *what() const noexcept override;
};

class IncorrectArgumentsForDeleteCreation final : public DeleteCreatorException{
    const char *what() const noexcept override;
};

class StringEditorException : public std::exception{};

class NullPtrCommandException final : public StringEditorException{
    const char *what() const noexcept override;
};

class UndoEditorException final : public StringEditorException{
    const char *what() const noexcept override;
};

class RedoEditorException final : public StringEditorException{
    const char *what() const noexcept override;
};

class CommandListExecutorException : public std::exception{};

class InvalidCreatorException final : public CommandListExecutorException{
    const char *what() const noexcept override;
};

class UndoCreatorException : public CreatorException{};

class InvalidDTOForUndoCreator final : public UndoCreatorException{
    const char *what() const noexcept override;
};

class RedoCreatorException : public CreatorException{};

class InvalidDTOForRedoCreator final : public RedoCreatorException{
    const char *what() const noexcept override;
};