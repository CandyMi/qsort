#include "qsort.h"

/* 升序比较函数 */
static int asc(int a, int b){
  return a < b;
}

/* 降序比较函数 */
static int desc(int a, int b) {
  return a > b;
}

void test_asc_qsort() {

  {
    int len = 9;
    int array[] = {4, 1, 9, 6, 5, 3, 2, 8, 0};
    Qsort(array, len, asc);
    int ret = asc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "asc_array_1 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  {
    int len = 9;
    int array[] = {7, 9, 1, 4, 2, 8, 5, 3, 6};
    Qsort(array, len, asc);
    int ret = asc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "asc_array_2 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  {
    int len = 9;
    int array[] = {6, 9, 2, 4, 8, 1, 7, 5, 3};
    Qsort(array, len, asc);
    int ret = asc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "asc_array_3 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  {
    int len = 9;
    int array[] = {2, 9, 1, 7, 4, 6, 3, 5, 8};
    Qsort(array, len, asc);
    int ret = asc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "asc_array_4 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  qsort_log("** 固定数据(升序)排序测试完成 ** \n");
}

void test_desc_qsort() {

  {
    int len = 9;
    int array[] = {4, 1, 9, 6, 5, 3, 2, 8, 7};
    Qsort(array, len, desc);
    int ret = desc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "desc_array_1 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  {
    int len = 9;
    int array[] = {7, 9, 1, 4, 2, 8, 5, 3, 6};
    Qsort(array, len, desc);
    int ret = desc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "desc_array_2 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  {
    int len = 9;
    int array[] = {6, 9, 2, 4, 8, 1, 7, 5, 3};
    Qsort(array, len, asc);
    int ret = asc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "desc_array_3 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  {
    int len = 9;
    int array[] = {2, 9, 1, 7, 4, 6, 3, 5, 8};
    Qsort(array, len, desc);
    int ret = desc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "desc_array_4 排序出错.");
      array_dump(array, len);
      return _exit(0);
    } 
  };

  qsort_log("** 固定数据(降序)排序测试完成 ** \n");
}

void random_test_sort() {

  int max_times = 5000;

  srand((unsigned)time(NULL));

  for (int index = 0; index < max_times; index ++) {
    int len = 9;
    int array[len];
    for (int i = 0; i < len ; i ++)
      array[i] = rand();
    Qsort(array, len, asc);
    int ret = asc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "random_array_sort 排序出错.");
      array_dump(array, len);
      return _exit(0);      
    }
  }

  qsort_log("** 随机数据(升序)排序测试完成 ** \n");

    for (int index = 0; index < max_times; index ++) {
    int len = 9;
    int array[len];
    for (int i = 0; i < len ; i ++)
      array[i] = rand();
    Qsort(array, len, desc);
    int ret = desc_verify_sort(array, len);
    if (ret){
      qsort_log("%s\n", "random_array_sort 排序出错.");
      array_dump(array, len);
      return _exit(0);      
    }
  }

  qsort_log("** 随机数据(降序)排序测试完成 ** \n");
}

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