#ifndef REPLACE_H
#define REPLACE_H

#include "remove.h"
#include "insert.h"

class Replace : public ITextOperation {
public:
    Replace(const std::string& old_, const std::string& new_, size_t position_);
    void apply(std::string& text_) const override;
    void undo(std::string& text_) const override;
private:
    Remove m_remove;
    Insert m_insert;
};

#endif // REPLACE_H
