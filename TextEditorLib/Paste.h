#pragma once
#include "UserCommand.h"

class Paste final : public UserCommand{
public:
    Paste(size_t _position) noexcept;
    void undo(std::shared_ptr<StringBuffer> str) override;
    void redo(std::shared_ptr<StringBuffer> str) override;
private:
    size_t position;
    size_t len = { 0 };
};