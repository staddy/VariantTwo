#include "replace.h"

Replace::Replace(const std::string& old_, const std::string& new_, size_t position_) :
    Remove(old_, position_), Insert(new_, position_) { }

void Replace::apply(std::string &text_) const {
    Remove::apply(text_);
    Insert::apply(text_);
}

void Replace::undo(std::string &text_) const {
    Insert::undo(text_);
    Remove::undo(text_);
}
