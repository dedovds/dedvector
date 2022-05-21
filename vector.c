#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

Vector* init_v(VECTOR_ERR* err, int size) {
    if (size <= 0) {
        fprintf(stderr, "Invalig argument: size\n");
        if (err != NULL)
            *err = EINVARG;
        return NULL;
    }

    Vector *v = (Vector *) malloc(sizeof(Vector));
    if (v == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if (err != NULL)
            *err = EMALLOC;
        return NULL;
    }
    v->capacity = 1;
    while (v->capacity <= size) {
        v->capacity *= 2;
    }

    v->data = (int *) malloc(v->capacity * sizeof(int));
    if (v->data == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if (err != NULL)
            *err = EMALLOC;
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        v->data[i] = 0;
    }
    v->size = size;
    success(err);
    return v;
}

void remove_v(Vector* v, VECTOR_ERR* err) {
  check_null_v(v, err);
	if (v->data != NULL)
		free(v->data);
	free(v);
	success(err);
}

void extend(Vector* v, VECTOR_ERR* err) {
  check_null_v(v, err);
  v->capacity *= 2;
  void* ptr = realloc(v->data, v->capacity * sizeof(int));
  if (ptr == NULL) {
    if (err != NULL)
			*err = EMALLOC;
    return;
  }
  v->data = ptr;
  success(err);
}