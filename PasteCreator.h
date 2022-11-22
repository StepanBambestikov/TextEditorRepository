#pragma once
#include "CommandCreator.h"
#include "Paste.h"

template<IteratorToString Iterator>
class PasteCreator final : public CommandCreator<Iterator>{
public:
    PasteCreator(Iterator _beginIt, Iterator _endIt) noexcept;
    ~PasteCreator() noexcept override = default;

    [[nodiscard]] std::shared_ptr<CommandInterface> createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer> _buffer) const override;
private:
    size_t position;
};

template<IteratorToString Iterator>
PasteCreator<Iterator>::PasteCreator(Iterator _beginIt, Iterator _endIt) noexcept: CommandCreator<Iterator>(_beginIt, _endIt) {
    int currentArgNum;
    auto it = _beginIt;
    if (it == _endIt || ++it != _endIt){
        this->isValid = false;
        return;
    }
    if ((currentArgNum = this->tryStoi(*_beginIt)) == -1){
        return;
    }
    position = static_cast<size_t>(currentArgNum);
    this->isValid = true;
}

template <IteratorToString Iterator>
std::shared_ptr<CommandInterface> PasteCreator<Iterator>::createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer> _buffer) const{
    if (!this->isValid){
        throw IncorrectArgumentsForPasteCreation();
    }
    return std::make_shared<Paste>(std::move(str), std::move(_buffer), position);
}