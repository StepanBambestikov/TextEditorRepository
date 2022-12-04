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

class IncorrectArgumentsForCopyCreation final : public CopyCreatorException{
    const char *what() const noexcept override;
};

class PasteCreatorException : public CreatorException{};

class IncorrectArgumentsForPasteCreation final : public PasteCreatorException{
    const char *what() const noexcept override;
};

class InsertCreatorException : public CreatorException{};

class IncorrectArgumentsForInsertCreation final : public InsertCreatorException{
    const char *what() const noexcept override;
};

class DeleteCreatorException : public CreatorException{};

class IncorrectArgumentsForDeleteCreation final : public DeleteCreatorException{
    const char *what() const noexcept override;
};

class StringEditorException : public std::exception{};

class UndoEditorException final : public StringEditorException{
    const char *what() const noexcept override;
};

class RedoEditorException final : public StringEditorException{
    const char *what() const noexcept override;
};


