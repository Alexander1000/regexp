#ifndef H_REGEXP_UTILS_INCLUDE
#define H_REGEXP_UTILS_INCLUDE

#include <io-buffer.h>

#define RESET_TOKEN_READER(token) \
    do { \
        auto reader = (IOBuffer::IOMemoryBuffer*) token->getReader(); \
        reader->setPosition(0); \
    } while(0);

#endif
