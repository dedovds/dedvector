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

int size(Vector* v, VECTOR_ERR* err) {
  check_null_v_return_zero(v, err);
  success(err);
  return v->size;
}

int capacity(Vector* v, VECTOR_ERR* err) {
  check_null_v_return_zero(v, err);
  success(err);
  return v->capacity;
}

void clear(Vector* v, VECTOR_ERR* err) {
  check_null_v(v, err);
  v->size = 0;
  v->capacity = 0;
  success(err);
}

void push_back(Vector* v, VECTOR_ERR* err, int element) {
  check_null_v(v, err);
  if (v->capacity <= v->size + 1) {
    VECTOR_ERR own_err;
		extend(v, &own_err);
    if (own_err == EMALLOC)
        if (err != NULL)
            *err = EMALLOC;
        return;
  } 
  v->data[v->size] = element;
  ++v->size;
  success(err);
}

void pop_back(Vector* v, VECTOR_ERR* err) {
  check_null_v(v, err);
  if (v->size == 0) {
    if (err != NULL)
    	*err = EEMPTY;
    return;
  }
  --v->size;
  success(err);
}

int at(Vector* v, VECTOR_ERR* err, int index) {
  check_null_v_return_zero(v, err);
	if (index >= 0 && v->size <= index) {
    if (err != NULL)
    	*err = EINDEX;
    return 0;
  }
  success(err);
  return v->data[index];
}

void print(Vector* v, VECTOR_ERR* err) {
  check_null_v(v, err);
  for (int i = 0; i < v->size; ++i) {
    printf("%d ", v->data[i]);
  }
  printf("\n");
  success(err);
}

int find(Vector* v, VECTOR_ERR* err, int elem) {
  check_null_v(v, err);
  success(err);
  for	(int i = 0; i < v->size; ++i) {
    if (v->data[i] == elem) {
      return i;
    }
  }
  return -1;
}

int back(Vector* v, VECTOR_ERR* err) {
  check_null_v_return_zero(v, err);
  if (v->size == 0) {
    if (err != NULL)
    	*err = EEMPTY;
    return 0;
  }
  success(err);
  return v->data[v->size-1];
}

int empty(Vector* v, VECTOR_ERR* err) {
  check_null_v_return_zero(v, err);
  return v->size == 0;
}