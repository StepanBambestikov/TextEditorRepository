#pragma once
#include "CommandCreator.h"
#include "Copy.h"

#include <array>

template<IteratorToString Iterator>
class CopyCreator final : public CommandCreator<Iterator>{
public:
    CopyCreator(Iterator _beginIt, Iterator _endIt) noexcept;
    ~CopyCreator() override = default;

    [[nodiscard]] std::shared_ptr<CommandInterface> createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer> _buffer) const override;
private:
    size_t begin;
    size_t end;
};

template <IteratorToString Iterator>
CopyCreator<Iterator>::CopyCreator(Iterator _beginIt, Iterator _endIt) noexcept: CommandCreator<Iterator>(_beginIt, _endIt){
    std::array<size_t, 2> _args{};
    int currentArgNum;
    size_t count = 0;
    for (auto it = _beginIt; it != _endIt; ++it){
        if (count > 2){
            break;
        }
        if ((currentArgNum = this->tryStoi(*it)) == -1){
            return;
        }
        _args[count] = static_cast<size_t>(currentArgNum);
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
std::shared_ptr<CommandInterface> CopyCreator<Iterator>::createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer> _buffer) const{
    if (!this->isValid){
        throw IncorrectArgumentsForCopyCreation();
    }
    return std::make_shared<Copy>(std::move(str), std::move(_buffer), begin, end);
}