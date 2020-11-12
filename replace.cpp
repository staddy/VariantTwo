#include "replace.h"

Replace::Replace(const std::string& old_, const std::string& new_, size_t position_) :
    m_remove(old_, position_), m_insert(new_, position_) { }

void Replace::apply(std::string &text_) const {
    m_remove.apply(text_);
    m_insert.apply(text_);
}

void Replace::undo(std::string &text_) const {
    m_insert.undo(text_);
    m_remove.undo(text_);
}
