/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
         arr[i] = rand() % 100;
    }
}

int main(){
    int array[10];
    srand(time(NULL));
    fill_random_array(array, 10);
    printf("Згенерований масив: \n[ ");
    for (int i = 0; i < 10; i++) {
         printf("%d ", array[i]);
    }
    printf("]\n");
    
    return 0;
}