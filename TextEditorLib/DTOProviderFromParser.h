#pragma once
#include "DTOProvider.h"
#include "Parser.h"

class DTOProviderFromParser final : public DTOProvider {
public:
    DTOProviderFromParser(std::unique_ptr<Parser> _parser) noexcept;
    std::unique_ptr<CommandDTO> getDTO() noexcept override;
    [[nodiscard]] bool hasNext() const noexcept override;
private:
    std::unique_ptr<Parser> parserPtr;
};
