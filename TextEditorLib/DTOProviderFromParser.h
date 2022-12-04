#pragma once
#include "DTOProvider.h"
#include "Parser.h"
#include "CommandParser.h"

class DTOProviderFromParser final : public DTOProvider {
public:
    DTOProviderFromParser(std::unique_ptr<Parser> _parser);
    std::unique_ptr<CommandDTO> getDTO() override;
    [[nodiscard]] bool hasNext() const override;
private:
    std::unique_ptr<Parser> parserPtr;
};
