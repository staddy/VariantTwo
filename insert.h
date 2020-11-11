#ifndef INSERT_H
#define INSERT_H

#include "textoperation.h"

class Insert : public TextOperation {
public:
    Insert(const std::string& text_, size_t position_);
    void apply(std::string& text_) const override;
    void undo(std::string& text_) const override;
};

#endif // INSERT_H
