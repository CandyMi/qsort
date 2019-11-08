#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define qsort_log(fmt, ...) {fprintf(stdout, fmt, ##__VA_ARGS__); fflush(stdout);}

/* 打印数组 */
static inline void array_dump(int* list, int len) {
  qsort_log("list = { ");
  for (int index = 0; index < len; index ++){
    qsort_log("%d", list[index]);
    if (index + 1 != len)
      qsort_log(", ");
  }
  qsort_log(" }\n");
}

/* 验证升序数组 */
static inline int asc_verify_sort(int* list, int len) {
  for (int index = 0; index < len - 1; index ++) {
    if (list[index] > list[index + 1])
      return -1;
  }
  return 0;
}

/* 验证降序数组 */
static inline int desc_verify_sort(int* list, int len) {
  for (int index = 0; index < len - 1; index ++) {
    if (list[index] < list[index + 1])
      return -1;
  }
  return 0;
}

void Qsort(int array[], int array_len, int (*cmp) (int, int));

