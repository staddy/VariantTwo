#include "insert.h"

Insert::Insert(const std::string& text_, size_t position_)
    : TextOperation(text_, position_) { }

void Insert::apply(std::string &text_) const {
    text_.insert(m_position, m_text);
}

void Insert::undo(std::string &text_) const {
    text_.erase(m_position, m_text.size());
}
