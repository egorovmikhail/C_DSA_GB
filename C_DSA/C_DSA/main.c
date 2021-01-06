//
//  main.c
//  C_DSA
//
//  Created by Михаил Егоров on 04.01.2021.
//

#include <stdio.h>

void cycle(int a, int b){
  while (a < b) {
    printf("%d", a);
    a++;
  }
  printf(" r%d", a);
}

void loop(int a, int b){
  printf("%d", a);
  a++;
  if (a < b)
    loop(a, b);
  printf(" r%d", a);
}

// 5! = 1 * 2 * 3 * 4 * 5
int Fc(int n){
  int result = 1;
  while (n > 0) {
    result *= n--;
  }
  return result;
}

// F(0) = 1;
// F(1) = 1;
// F(2) = 2;
// F(3) = 6;
// F(4) = 24;
// F(n) = F(n -1) * n; если n > 0;

int F(int n){
  if(n == 0)
    return 1;
  else
    return F(n - 1) * n;
}

int operations = 0;
void put(int from, int to){
  printf("%d -> %d | ", from, to);
  if (++operations % 7 == 0) {
    printf("\n");
  }
}

void hanoi(int from, int to, int n){
  int temp = from ^ to;
  if (n == 1) {
    put(from, to);
  }
  else {
    hanoi(from, temp, n - 1);
    put(from, to);
    hanoi(temp, to, n - 1);
  }
}

int main(int argc, const char * argv[]) {
  cycle(1, 5);
  printf("\n");
  loop(1, 5);
  printf("\n");
  printf("%d \n", Fc(5));
  hanoi(1, 3, 4);
  printf("\n");
  return 0;
}

