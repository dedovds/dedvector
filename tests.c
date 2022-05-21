#include "ded_vector.h"
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
}
