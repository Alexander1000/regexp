#include <regexp.h>
#include <syntax-tree-lib.h>
#include <io-buffer.h>

namespace RegExp::Token
{
    Token::Token(TokenType type, const char* data) : SyntaxTree::Token::Token(0, 0, nullptr)
    {
        this->type = type;
        this->data = data;
        auto ioWriter = new IOBuffer::IOMemoryBuffer(sizeof(char) * (strlen(data) + 1));
        ioWriter->write((char*) data, strlen(data));
        this->reader = ioWriter;
    }

    int Token::getType()
    {
        return this->type;
    }

    const char* Token::getData()
    {
        return this->data;
    }
}
