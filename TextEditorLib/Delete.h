#pragma once
#include "UserCommand.h"

class Delete final : public UserCommand{
public:
    Delete(size_t begin, size_t end) noexcept;
    void undo(std::shared_ptr<StringBuffer> str) override;
    void redo(std::shared_ptr<StringBuffer> str) override;
private:
    StringBuffer deletedStr;
    size_t begin;
    size_t end;
};