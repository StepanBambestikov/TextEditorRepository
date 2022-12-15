#pragma once
#include "StringEditor.h"

class ServiceCommand {
public:
    explicit ServiceCommand() noexcept = default;
    virtual ~ServiceCommand() noexcept = default;

    virtual void redo(StringEditor&) const = 0;
};