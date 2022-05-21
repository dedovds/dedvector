#ifndef ded_vector
#define ded_vector

typedef struct Vector {
    int size;
    int capacity;
    int* data;
} Vector;

typedef enum {
    ESUCCESS = 0,
    EMALLOC,
    EEMPTY,
    EINDEX,
    EINVARG
} VECTOR_ERR;
#endif

