#pragma once
#include "CommandInterface.h"

template<class Iterator>
concept IteratorToString = std::forward_iterator<Iterator> && requires(Iterator it){
    { *it } -> std::same_as<std::string&>;
};

template<IteratorToString Iterator>
class CopyCreator ;

template<IteratorToString Iterator>
class PasteCreator;

template<IteratorToString Iterator>
class InsertCreator;

template<IteratorToString Iterator>
class DeleteCreator;


template<IteratorToString Iterator>
class CommandCreator {
public:
    static std::shared_ptr<CommandCreator> createCreator(Iterator _beginIt, Iterator _endIt);

    explicit CommandCreator(Iterator beginIt, Iterator endIt) noexcept;
    virtual ~CommandCreator();

    explicit operator bool() const noexcept;
    [[nodiscard]] virtual std::shared_ptr<CommandInterface> createCommand(std::shared_ptr<StringBuffer> str, std::shared_ptr<StringBuffer> _buffer) const = 0;
    [[nodiscard]] bool getValidity() const noexcept;
protected:
    Iterator beginIt;
    Iterator endIt;
    bool isValid = { false };

    int tryStoi(const std::string& str) noexcept;
};

template<IteratorToString Iterator>
CommandCreator<Iterator>::CommandCreator(Iterator _beginIt, Iterator _endIt) noexcept : beginIt(_beginIt), endIt(_endIt){}

template<IteratorToString Iterator>
CommandCreator<Iterator>::~CommandCreator() = default;

template<IteratorToString Iterator>
bool CommandCreator<Iterator>::getValidity() const noexcept{
    return isValid;
}

template<IteratorToString Iterator>
CommandCreator<Iterator>::operator bool() const noexcept{
    return isValid;
}

template<IteratorToString Iterator>
std::shared_ptr<CommandCreator<Iterator>> CommandCreator<Iterator>::createCreator(Iterator _beginIt, Iterator _endIt){
    if (_beginIt == _endIt){
        throw IncorrectArgumentsInCreateCreator();
    }
    if (*_beginIt == "copy"){
        return std::make_shared<CopyCreator<Iterator>>(++_beginIt, _endIt);
    }
    else if(*_beginIt == "paste"){
        return std::make_shared<PasteCreator<Iterator>>(++_beginIt, _endIt);
    }
    else if(*_beginIt == "insert"){
        return std::make_shared<InsertCreator<Iterator>>(++_beginIt, _endIt);
    }
    else if(*_beginIt == "delete"){
        return std::make_shared<DeleteCreator<Iterator>>(++_beginIt, _endIt);
    }
    else{
        throw IncorrectArgumentsInCreateCreator();
    }
}

template<IteratorToString Iterator>
int CommandCreator<Iterator>::tryStoi(const std::string& str) noexcept{
    try{
        return std::stoi(str, nullptr);
    }
    catch(...){
        this->isValid = false;
        return -1;
    }
}