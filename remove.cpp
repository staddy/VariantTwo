#include "remove.h"

Remove::Remove(const std::string& text_, size_t position_) : TextOperation(text_, position_) { }

void Remove::apply(std::string &text_) const {
    text_.erase(m_position, m_text.size());
}

void Remove::undo(std::string &text_) const {
    text_.insert(m_position, m_text);
}
