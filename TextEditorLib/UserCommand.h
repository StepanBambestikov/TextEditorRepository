#pragma once
#include <memory>
#include "StringBuffer.h"

class UserCommand {
public:
    explicit UserCommand() noexcept = default;
    virtual ~UserCommand() noexcept = default;

    virtual void undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) = 0;
    virtual void redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) = 0;
};