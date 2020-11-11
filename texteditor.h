#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "stack.h"
#include "textoperation.h"

class TextEditor {
public:
    TextEditor();
    void remove(size_t position_, size_t length_);
    void insert(const std::string& text_, size_t position_);
    void replace(const std::string& new_, size_t position_, size_t length_);
    void undo();
    void redo();
    const std::string& text() const;
private:
    std::string m_text;
    Stack<std::shared_ptr<ITextOperation> > m_undoStack;
    Stack<std::shared_ptr<ITextOperation> > m_redoStack;
    void applyOperation(std::shared_ptr<ITextOperation>&& operation_);
};

#endif // TEXTEDITOR_H
