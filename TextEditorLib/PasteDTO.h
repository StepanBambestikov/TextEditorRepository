#pragma once
#include "CommandDTO.h"

class PasteDTO final : public CommandDTO{
public:
    PasteDTO(size_t _position);
    [[nodiscard]] size_t getPosition() const;
private:
    size_t position;

    void unusedFunc() override{}
};