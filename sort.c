#include "sort.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

/* Funtion pointer that returns an int and takes an int as argument */
// int (*pair_is_in_order)(int arr[], int n);

// Function to print an array
void printArray(char arr[], int size, const char *label) {
  printf("%s", label);

  for (int i = 0; i < size; i++) {
    char c = arr[i];

    // Check if it’s a “printable letter”
    if (isprint(c) && ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
      printf(" %c", c);
    } else {
      // Otherwise treat as number
      printf(" %d", c);
    }
  }

  printf("\n");
}

/* In order to compare two characters value I convert both of them
to either lower or uppercase, so the ASCII follows the alphabet */
bool letters_in_order(char a, char b) { /* can be used as *pair_is_in_order */
  if (a >= 'A' && a <= 'Z') /* lowercase higher value than uppercase in ASCII */
    a += 'a' - 'A';         /* 32 between those in ASCII */
  if (b >= 'A' && b <= 'Z')
    b += 'a' - 'A';
  return a <= b;
}

/* can be used as *pair_is_in_order */
bool numbers_ascending(char a, char b) { return a <= b; }

/* Checks if the pair is in the alphabet or a number symbol between 0 - 9 */
bool(pair_is_in_order)(char a, char b) {

  /* Checks if the pair is in the alphabet or a number symbol between 0 - 9 */
  bool a_is_letter = isalpha(a);             // true if a is in the alphabet
  bool b_is_letter = isalpha(b);             // true if b is in the alphabet
  bool a_is_number = (a >= '0' && a <= '9'); // true if a = num between 0 - 9
  bool b_is_number = (b >= '0' && b <= '9'); // true if b = num between 0 - 9

  if (a_is_letter && b_is_letter) // if both letters compare if neeeded to swap
    return letters_in_order(a, b);
  else if (a_is_number && b_is_number)
    return numbers_ascending(a, b);
  else if (a_is_number && b_is_letter)
    return true; // if numbers come before letters
  else if (a_is_letter && b_is_number)
    return false; // letters come after numbers

  return a <= b; // fallback
}

// Swap two elements in an array
void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

/* Bubble Sort */
void bubble_sort(char arr[], int size, bool (*pair_is_in_order)(char, char)) { // bool (*pair_is_in_order)(char, char) — is a function pointer. It points to a function taking two char values and returning a bool
  for (int i = 0; i < size - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < size - i - 1; j++) { 
      if (!pair_is_in_order(arr[j], arr[j + 1])) {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break; // array already sorted (early exit improvement)
  }
}

// function that sorts an array with bubble sort algorithm
void sort(char arr[], int size) {

  printArray(arr, size, "before bubblesorting characters:");

  printf("size: %1d\n", size);

  bubble_sort(arr, size, pair_is_in_order);

  printArray(arr, size, "after bubblesorting characters:");

  puts(" ");
}
