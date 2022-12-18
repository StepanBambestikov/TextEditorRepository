#pragma once
#include "UserCommand.h"

class Insert final : public UserCommand{
public:
    Insert(StringBuffer _strForInsert, size_t _position) noexcept;
    void undo(std::shared_ptr<StringBuffer> str) override;
    void redo(std::shared_ptr<StringBuffer> str) override;
private:
    StringBuffer strForInsert;
    size_t position;
    bool insertHappened = { false };
};
