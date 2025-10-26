#include "sort.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main() {

  /* declare arr1 an array of chars */
  /* defining and initializing arr1 with numbers */
  char arr1[] = {'z', 'S', 's', 'a', 4, -18, 2, 29};

  /* calling the function-like macro SORT that expands to sort() in the
   * headerfile.
   * Did this to make the function work without declaring the array
   * size in main.c */

  SORT(arr1);

  /* declare arr2 an array of chars */
  /* defining and initializing arr2 with letters */
  char arr2[] = {'z', 'S', 's', 'a'}; /* aSsz */

  /* again calling the function-like macro SORT that expands to sort() in the
   * headerfile */

  SORT(arr2);
}
