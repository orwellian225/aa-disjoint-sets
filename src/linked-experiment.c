#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "linked-disjoint-set.h"

int main(int argc, char **argv) {
    srand(0);

    size_t n = 100;
    size_t m = n - 1;

    if (argc == 3) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }

    LinkedElement **standard_elements = (LinkedElement**)malloc(n * sizeof(LinkedElement*));
    LinkedElement **weighted_elements = (LinkedElement**)malloc(n * sizeof(LinkedElement*));

    clock_t standard_start = clock();
        for (size_t i = 0; i < n; ++i)
            standard_elements[i] = make_linked_set(rand() % (10 * n));

        // Worst Case merges
        for (size_t i = 0; i < m; ++i)
            union_linked_sets(standard_elements[i + 1], standard_elements[i]);

    clock_t standard_end = clock();
    double standard_duration = (double)(standard_end - standard_start) / CLOCKS_PER_SEC;
    LinkedSet *standard_set = find_linked_set(standard_elements[n - 1])->owner;
    for (size_t i = 0; i < n; ++i) {
        free(standard_elements[i]);
    }
    free(standard_set);

    clock_t weighted_start = clock();
        for (size_t i = 0; i < n; ++i)
            weighted_elements[i] = make_linked_set(rand() % (10 * n));

        // Worst Case merges
        for (size_t i = 0; i < m; ++i)
            weighted_union_linked_sets(weighted_elements[i + 1], weighted_elements[i]);

    clock_t weighted_end = clock();
    double weighted_duration = (double)(weighted_end - weighted_start) / CLOCKS_PER_SEC;
    LinkedSet *weighted_set = find_linked_set(weighted_elements[n - 1])->owner;
    for (size_t i = 0; i < n; ++i) {
        free(weighted_elements[i]);
    }
    free(weighted_set);

    // Format: n,set_type,heuristic_type,duration_seconds
    printf("%ld,Linked,None,%lf\n", n, standard_duration);
    printf("%ld,Linked,Weighted,%lf\n", n, weighted_duration);
}