#ifndef SORT_H
#define SORT_H

void printArray(char arr[], int size, const char *label);
bool letters_in_order(char a, char b);
bool numbers_ascending(char a, char b);
bool pair_is_in_order(char a, char b);
void swap(char *a, char *b);
void bubble_sort(char arr[], int size, bool (*pair_is_in_order)(char, char));
void sort(char arr[], int size);

// Macro to automatically pass array size every time it receives a new arr array
#define SORT(arr) sort(arr, sizeof(arr) / sizeof((arr)[0]))

#endif // SORT_H
