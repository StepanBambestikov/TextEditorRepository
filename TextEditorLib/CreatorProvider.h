#pragma once
#include "DTOProvider.h"
#include "CommandCreator.h"

class CreatorProvider{
public:
    CreatorProvider() noexcept = default;
    virtual ~CreatorProvider() noexcept = default;
    virtual std::unique_ptr<CommandCreator> getCreator() = 0;
};
