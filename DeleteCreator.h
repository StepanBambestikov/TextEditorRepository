#pragma once
#include "CommandCreator.h"
#include "Delete.h"
#include <array>

template<IteratorToString Iterator>
class DeleteCreator final : public CommandCreator<Iterator>{
public:
    DeleteCreator(Iterator _beginIt, Iterator _endIt) noexcept;
    ~DeleteCreator() override = default;

    [[nodiscard]] std::shared_ptr<CommandInterface> createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer> _buffer) const override;
private:
    size_t begin;
    size_t end;
};

template<IteratorToString Iterator>
DeleteCreator<Iterator>::DeleteCreator(Iterator _beginIt, Iterator _endIt) noexcept : CommandCreator<Iterator>(_beginIt, _endIt) {
    std::array<size_t, 2> _args{};
    int currentAngNum;
    size_t count = 0;
    for (auto it = _beginIt; it != _endIt; ++it){
        if (count > 2){
            break;
        }
        if ((currentAngNum = this->tryStoi(*it)) == -1){
            return;
        }
        _args[count] = static_cast<size_t>(currentAngNum);
        ++count;
    }
    if (count != 2){
        this->isValid = false;
        return;
    }
    this->isValid = true;
    begin = _args[0];
    end = _args[1];
}

template <IteratorToString Iterator>
std::shared_ptr<CommandInterface> DeleteCreator<Iterator>::createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer>) const{
    if (!this->isValid){
        throw IncorrectArgumentsForDeleteCreation();
    }
    return std::make_shared<Delete>(std::move(str), begin, end);
}