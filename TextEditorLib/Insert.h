#pragma once
#include "UserCommand.h"

class Insert final : public UserCommand{
public:
    Insert(StringBuffer _strForInsert, size_t _position) noexcept;
    void undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept override;
    void redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept override;
private:
    StringBuffer strForInsert;
    size_t position;
    int positionOfInserted = { -1 };
};
