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

Vector* init_v(VECTOR_ERR* err, int size);

void remove_v(Vector* v, VECTOR_ERR* err);

void extend(Vector* v, VECTOR_ERR* err);

int size(Vector* v, VECTOR_ERR* err);

int capacity(Vector* v, VECTOR_ERR* err);

void clear(Vector* v, VECTOR_ERR* err);

void push_back(Vector* v, VECTOR_ERR* err, int element);

int at(Vector* v, VECTOR_ERR* err, int index);

void pop_back(Vector* v, VECTOR_ERR* err);

void print(Vector* v);

void find(Vector* v, VECTOR_ERR* err, int elem);

int empty(Vector* v, VECTOR_ERR* err);

int back(Vector* v, VECTOR_ERR* err);

#endif

