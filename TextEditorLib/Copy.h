#pragma once
#include "UserCommand.h"

class Copy final : public UserCommand{
public:
    Copy(size_t _begin, size_t _end) noexcept;
    void undo(std::shared_ptr<StringBuffer> str) noexcept override;
    void redo(std::shared_ptr<StringBuffer> str) override;
private:
    size_t begin;
    size_t end;
};


