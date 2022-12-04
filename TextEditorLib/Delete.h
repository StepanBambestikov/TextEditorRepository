#pragma once
#include "CommandInterface.h"

class Delete final : public CommandInterface{
public:
    Delete(size_t begin, size_t end) noexcept;
    void undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override;
    void redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override;
private:
    StringBuffer deletedStr;
    size_t positionOfDeleted;
    size_t begin;
    size_t end;
};