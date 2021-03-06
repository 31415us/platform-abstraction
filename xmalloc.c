#include "xmalloc.h"
#include "panic.h"

void* xmalloc(size_t size)
{
    void *result;

    if (size == 0) {
        PANIC("invalid alloc: zero byte");
    }

    result = malloc(size);

    if (result == NULL) {
        PANIC("out of memory!");
    }

    return result;
}

void xfree(void *p)
{
    free(p);
}

void* xrealloc(void *p, size_t size)
{
    void *result;

    result = realloc(p, size);

    if (result == NULL && size != 0) {
        PANIC("out of memory!");
    }

    return result;
}
