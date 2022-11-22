#pragma once
#include "CommandInterface.h"

class Delete final : public CommandInterface{
public:
    Delete(std::shared_ptr<StringBuffer> str, size_t begin, size_t end) noexcept;
    void undo() override;
    void redo() override;
private:
    StringBuffer deletedStr;
    size_t positionOfDeleted;
    size_t begin;
    size_t end;
};