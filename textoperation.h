#ifndef TEXTOPERATION_H
#define TEXTOPERATION_H

#include "itextoperation.h"

class TextOperation : public ITextOperation {
public:
    TextOperation(const std::string& text_, size_t position_);
protected:
    std::string m_text;
    size_t m_position{0};
};

#endif // TEXTOPERATION_H
