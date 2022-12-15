#pragma once
#include "ServiceCommand.h"

class Undo final : public ServiceCommand{
public:
    Undo() noexcept = default;
    void redo(StringEditor& editor) const override;
};