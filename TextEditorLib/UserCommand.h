#pragma once
#include <memory>
#include "EditorBuffer.h"
#include "StringBuffer.h"

class UserCommand {
public:
    explicit UserCommand() noexcept = default;
    virtual ~UserCommand() noexcept = default;

    virtual void undo(std::shared_ptr<StringBuffer> str) = 0;
    virtual void redo(std::shared_ptr<StringBuffer> str) = 0;
};