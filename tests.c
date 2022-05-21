#include "vector.h"
#include <stdio.h>

#define test_error(err, expected, number) \
do { \
  fprintf(stdout, "Test_%d\t->\t", number); \
  if (err != expected) \
        fprintf(stdout, "FAILED\n"); \
    else \
        fprintf(stdout, "PASSED\n"); \
} while (0)

int main() {
  Vector *vec = NULL;
  VECTOR_ERR err;
  
  vec = init_v(&err, -1);
  test_error(err, EINVARG, 1); // EINVARG - ожидаемое значение ошибки, 1 - номер теста
  
  vec = init_v(&err, 25);
  test_error(err, ESUCCESS, 2);
}

