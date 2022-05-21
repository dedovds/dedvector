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
	
  vec = NULL;
  remove_v(vec, &err);
  test_error(err, EINVARG, 3);

  int a = size(vec, &err);
  test_error(err, EINVARG, 4);

  extend(vec, &err);
  test_error(err, EINVARG, 5);

  int b = capacity(vec, &err);
  test_error(err, EINVARG, 6);

  clear(vec, &err);
  test_error(err, EINVARG, 7);

  push_back(vec, &err, 5);
  test_error(err, EINVARG, 8);

  int c = at(vec, &err, 5);
  test_error(err, EINVARG, 9);

  pop_back(vec, &err);
  test_error(err, EINVARG, 10);

  print(vec, &err);
  tesr_error(err, EINVARG, 11);

  int d = find(vec, &err, 5);
  test_error(err, EINVARG, 12);

  int e = back(vec, &err);
  test_error(err, EINVARG, 13);

  int f = empty(vec, &err);
  test_error(err, EINVARG, 14);


}

