//
//  main.c
//  C_DSA
//
//  Created by Михаил Егоров on 04.01.2021.
//

#include <stdio.h>

int GCD(int x, int y){
  while (x != y){
    if (x > y){
      x = x - y;
    } else {
      y = y - x;
    }
  }
  return x;
}

int GCDiv(int a, int b){
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return a;
}

float average(int n){
  float sum = 0;
  int counter = 0;
  while (counter < n) {
    int in;
    scanf("%d", &in);
    sum += in;
    counter++;
  }
  return sum / (float) n;
}

void mean(){
  int counter = 0;
  float sum = 0;
  int in = 0;
  do {
    scanf("%d", &in);
    if(in == -1) break;;
    counter++;
  } while (in == -1);
  if(counter != 0) {
    printf("a = %.2f\n", (float) sum / counter );
  } else {
    printf("NO input");
  }
}

int turn(int in){
  int result = 0;
  while (in > 0) {
    result *= 10;
    result += in % 10;
    in /= 10;
  }
  return result;
}

int power(int base, int sign){
  int result = 1;
  int i;
  for (i = 0; i < sign; i++) {
    result *= base;
  }
  return result;
}

int powere(int base, int sign){
  int result = 1;
  while (sign != 0) {
    sign --;
    result *=base;
  }
  return result;
}

int powemproved(int base, int sign){
  int result = 1;
//  int i;
  while (sign != 0) {
    if (sign % 2) {
      result *= base;
      sign --;
    } else {
      sign /= 2;
      base *= base;
    }
  }
  return result;
}

int main(int argc, const char * argv[]) {
  printf("GCD: %d\n", GCD(12, 45));
  printf("GCDiv: %d\n", GCDiv(12, 45));
//  printf("average: %f\n", average(10));
//  mean();
  printf("turned: %d\n", turn(54321));
  printf("power: %d\n", power(2, 10));
  printf("powemproved: %d\n", powemproved(2, 10));
  return 0;
}
