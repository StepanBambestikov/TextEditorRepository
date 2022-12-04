#pragma once
#include "DTOProvider.h"
#include "CommandCreator.h"

class CreatorProvider{
public:
    CreatorProvider() = default;
    virtual ~CreatorProvider() = default;
    virtual std::unique_ptr<CommandCreator> getCreator() = 0;
    virtual bool hasNext() const = 0;
};
