#pragma once
#include "CommandDTO.h"

class DeleteDTO final : public CommandDTO{
public:
    DeleteDTO(size_t _idx1, size_t _idx2);
    [[nodiscard]] size_t getIdx1() const;
    [[nodiscard]] size_t getIdx2() const;
private:
    size_t idx1;
    size_t idx2;

    void unusedFunc() override{}
};