#ifndef H_REGEXP_TOKEN_INCLUDE
#define H_REGEXP_TOKEN_INCLUDE

namespace RegExp
{
    class Token
    {
    public:
        Token(int, const char*);
    private:
        int id;
        const char* value;
    };
}

#endif
