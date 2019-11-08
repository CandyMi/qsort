# Q-Sort algorithm.

  C 语言实现.

## 编译与运行

  * `make build`编译动态库.

  * `make demo`编译测试代码.

  * `make clean`清理编译文件.

## 快速排序算法

  包含:

  1. `dump`宏可快速打印数组内容, 方便调试与排查问题.

  2. `verify`宏可用于验证数组内容, 主要用来检查排序(升序/降序)后的数组是否正确.

## 代码片段

```C
/* 交换A,B的值 */
static inline void swap(int* a, int* b){
  (*a) = (*a) ^ (*b);
  (*b) = (*a) ^ (*b);
  (*a) = (*a) ^ (*b);
}
```

```C
/* 升序比较函数 */
static int asc(int a, int b){
  return a < b;
}

/* 降序比较函数 */
static int desc(int a, int b) {
  return a > b;
}
```

```C
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
```

```C
int main(int argc, char const *argv[])
{

  /* 测试升序排序 */
  test_asc_qsort();

  /* 测试降序排序 */
  test_desc_qsort();

 /* 测试随机数据排序 */
  random_test_sort();

  return 0;
}
```

## 测试

  查看`demo.c`代码后, 可自行编写更多的测试用例.

## 协议

  [LICENSE](https://github.com/CandyMi/qsort/blob/master/LICENSE)