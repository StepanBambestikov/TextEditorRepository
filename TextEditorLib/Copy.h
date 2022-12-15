#pragma once
#include "UserCommand.h"

class Copy final : public UserCommand{
public:
    Copy(size_t _begin, size_t _end) noexcept;
    void undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept override;
    void redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override;
private:
    size_t begin;
    size_t end;
};


