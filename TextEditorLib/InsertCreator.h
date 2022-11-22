#pragma once
#include "CommandCreator.h"
#include "Insert.h"

template<IteratorToString Iterator>
class InsertCreator final : public CommandCreator<Iterator>{
public:
    InsertCreator(Iterator _beginIt, Iterator _endIt) noexcept;
    ~InsertCreator() noexcept override = default;

    [[nodiscard]] std::shared_ptr<CommandInterface> createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer> _buffer) const override;
private:
    StringBuffer strForInsert;
    size_t position;
};

template<IteratorToString Iterator>
InsertCreator<Iterator>::InsertCreator(Iterator _beginIt, Iterator _endIt) noexcept
: CommandCreator<Iterator>(_beginIt, _endIt) {
    int currentArgNum;
    auto it = _beginIt;
    if (it == _endIt || ++it == _endIt || ++it != _endIt){
        this->isValid = false;
        return;
    }
    strForInsert = StringBuffer(*_beginIt);
    ++_beginIt;
    if ((currentArgNum = this->tryStoi(*_beginIt)) == -1){
        return;
    }
    position = static_cast<size_t>(currentArgNum);
    this->isValid = true;
}

template <IteratorToString Iterator>
std::shared_ptr<CommandInterface> InsertCreator<Iterator>::createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer>) const{
    if (!this->isValid){
        throw IncorrectArgumentsForInsertCreation();
    }
    return std::make_shared<Insert>(std::move(str), strForInsert, position);
}
