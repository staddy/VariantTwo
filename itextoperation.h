#ifndef ITEXTOPERATION_H
#define ITEXTOPERATION_H

#include <string>

class ITextOperation {
public:
    virtual void apply(std::string& text_) const = 0;
    virtual void undo(std::string& text_) const = 0;
    virtual ~ITextOperation() = default;
};

#endif // ITEXTOPERATION_H
