#pragma once
#include "ServiceCommand.h"

class Redo final : public ServiceCommand{
public:
    Redo() noexcept = default;
    void redo(StringEditor& editor) const noexcept override;
};

