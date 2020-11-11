#ifndef REPLACE_H
#define REPLACE_H

#include "remove.h"
#include "insert.h"

class Replace : public ITextOperation, private Remove, private Insert {
public:
    Replace(const std::string& old_, const std::string& new_, size_t position_);
    void apply(std::string& text_) const override;
    void undo(std::string& text_) const override;
};

#endif // REPLACE_H
