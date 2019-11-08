#include "qsort.h"

/* 交换A,B的值 */
static inline void swap(int* a, int* b){
  (*a) = (*a) ^ (*b);
  (*b) = (*a) ^ (*b);
  (*a) = (*a) ^ (*b);
}

/* 比较方法 */
static inline int compare(int a, int b, int (*cmp) (int a, int b)) {
  return cmp ? cmp(a, b) : a < b;
}

/* 快速排序算法 */
void Qsort(int list[], int len, int (*cmp) (int a, int b)) {
  if (len <= 2){
    if (len == 2 && compare(list[1], list[0], cmp))
      swap(&list[0], &list[1]);
    return;
  }
  int left = 1, right = len - 1;
  while (left != right) {
    if (compare(list[0], list[right], cmp)){
      right--;
      continue;
    }
    if (compare(list[left], list[0], cmp)) {
      left++;
      continue;
    }
    swap(&list[left], &list[right]);
  }
  swap(&list[0], &list[left]);
  return Qsort(list, left + 1, cmp), Qsort(list + left, len - left, cmp);
}