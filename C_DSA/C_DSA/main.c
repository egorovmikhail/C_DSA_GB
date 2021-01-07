//
//  main.c
//  C_DSA
//
//  Created by Михаил Егоров on 04.01.2021.
//

#include <stdio.h>
#include <stdlib.h>

void fillArray(int* a, int len){
  int i;
  for(i = 0; i < len; i++){
    a[i] = rand() % 100;
  }
}

void printArray(int* a, int len){
  int i;
  for(i = 0; i < len; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int linearSearch(int* a, int len, int value){
  int i = 0;
  while (i < len && a[i] != value) i++;
  return i == len ? -1 : i;
}

void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int* a, int len){
  int i;
  int j;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(&a[j], &a[j + 1]);
      }
    }
  }
}

void pickSort(int* a, int len){
  int i;
  int j;
  for (i = 0; i < len; i++) {
    int flag = i;
    for (j = i + 1; j < len - 1; j++){
      if (a[j] < a[flag]) {
        flag = j;
      }
    }
    swap(&a[i], &a[flag]);
  }
}

int binSearch(int* a, int len, int value){
  int left = 0;
  int right = len - 1;
  int mid = (left + right) / 2;
  while (left < right && a[mid] != value) {
    if(a[mid] < value){
      left = mid;
    } else {
      right = mid;
    }
    mid = (left + right) / 2;
  }
  return a[mid] == value ? mid : - 1;
}

int main(int argc, const char * argv[]) {
  const int SIZE = 25;
  int arr[SIZE];
  fillArray(arr, SIZE);
  printArray(arr, SIZE);
  printf("linear %d search: %d\n", 23, linearSearch(arr, SIZE, 23));
//  bubbleSort(arr, SIZE);
  pickSort(arr, SIZE);
  printArray(arr, SIZE);
  printf("binary %d search: %d\n", 23, binSearch(arr, SIZE, 23));
  printf("binary %d search: %d\n", 2, binSearch(arr, SIZE, 2));
  return 0;
}
