#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// --------------------------------------
// 1. Swap-funktioner
// --------------------------------------
void swap_char(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// --------------------------------------
// 2. "pair_is_in_order" funktioner
// --------------------------------------

// Bogstaver i orden (case-insensitiv)
bool letters_in_order(char a, char b) {
    char ca = (char)tolower((unsigned char)a);
    char cb = (char)tolower((unsigned char)b);
    return ca <= cb;
}

// Tal i stigende orden
bool numbers_in_ascending_order(int a, int b) {
    return a <= b;
}

// --------------------------------------
// 3. Bubble sort-implementering
// --------------------------------------
void bubble_sort_chars(char arr[], size_t n,
                       bool (*pair_is_in_order)(char a, char b)) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < n; ++i) {
            if (!pair_is_in_order(arr[i - 1], arr[i])) {
                swap_char(&arr[i - 1], &arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

void bubble_sort_ints(int arr[], size_t n,
                      bool (*pair_is_in_order)(int a, int b)) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < n; ++i) {
            if (!pair_is_in_order(arr[i - 1], arr[i])) {
                swap_int(&arr[i - 1], &arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

// --------------------------------------
// 4. Hjælpefunktioner til udskrift
// --------------------------------------
void print_chars(const char *label, const char arr[], size_t n) {
    printf("%s", label);
    for (size_t i = 0; i < n; ++i)
        printf("%c%s", arr[i], (i + 1 < n ? " " : ""));
    printf("\n");
}

void print_ints(const char *label, const int arr[], size_t n) {
    printf("%s", label);
    for (size_t i = 0; i < n; ++i)
        printf("%d%s", arr[i], (i + 1 < n ? " " : ""));
    printf("\n");
}

// --------------------------------------
// 5. main() - test af funktionerne
// --------------------------------------
int main(void) {
    char letter_arr[] = { 't', 'S', 's', 'a' };
    int number_arr[]  = { 4, -1, 2, 9 };

    size_t n_letters = sizeof(letter_arr) / sizeof(letter_arr[0]);
    size_t n_numbers = sizeof(number_arr) / sizeof(number_arr[0]);

    printf("=== Før sortering ===\n");
    print_chars("Bogstaver: ", letter_arr, n_letters);
    print_ints ("Tal:        ", number_arr, n_numbers);

    bubble_sort_chars(letter_arr, n_letters, letters_in_order);
    bubble_sort_ints(number_arr, n_numbers, numbers_in_ascending_order);

    printf("\n=== Efter sortering ===\n");
    print_chars("Bogstaver: ", letter_arr, n_letters);
    print_ints ("Tal:        ", number_arr, n_numbers);

    return 0;
}
