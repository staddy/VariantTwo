#ifndef REMOVE_H
#define REMOVE_H

#include "textoperation.h"

class Remove : public TextOperation {
public:
    Remove(const std::string& text_, size_t position_);
    void apply(std::string& text_) const override;
    void undo(std::string& text_) const override;
};

#endif // REMOVE_H
