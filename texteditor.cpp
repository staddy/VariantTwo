#include "texteditor.h"

#include <iostream>

#include "remove.h"
#include "insert.h"
#include "replace.h"

TextEditor::TextEditor() { }

void TextEditor::remove(size_t position_, size_t length_) {
    if ((position_ + length_ > m_text.size()) || (length_ == 0)) {
        std::cerr << "Invalid remove\n";
        return;
    }
    m_redoStack.clear();
    applyOperation(std::make_shared<Remove>(m_text.substr(position_, length_), position_));
}

void TextEditor::insert(const std::string &text_, size_t position_) {
    if ((position_ > m_text.size()) || text_.empty()) {
        std::cerr << "Invalid insert\n";
        return;
    }
    m_redoStack.clear();
    applyOperation(std::make_shared<Insert>(text_, position_));
}

void TextEditor::replace(const std::string &new_, size_t position_, size_t length_) {
    if ((position_ + length_ > m_text.size()) || new_.empty()) {
        std::cerr << "Invalid replace\n";
        return;
    }
    m_redoStack.clear();
    applyOperation(std::make_shared<Replace>(m_text.substr(position_, length_), new_, position_));
}

void TextEditor::undo() {
    if (m_undoStack.empty()) {
        std::cerr << "Unable to undo\n";
        return;
    }
    auto operation = m_undoStack.top();
    m_undoStack.pop();
    operation->undo(m_text);
    m_redoStack.push(std::move(operation));
}

void TextEditor::redo() {
    if (m_redoStack.empty()) {
        std::cerr << "Unable to redo\n";
        return;
    }
    auto operation = m_redoStack.top();
    m_redoStack.pop();
    operation->apply(m_text);
    m_undoStack.push(std::move(operation));
}

const std::string &TextEditor::text() const {
    return m_text;
}

void TextEditor::applyOperation(std::shared_ptr<ITextOperation>&& operation_) {
    operation_->apply(m_text);
    m_undoStack.push(std::move(operation_));
}
