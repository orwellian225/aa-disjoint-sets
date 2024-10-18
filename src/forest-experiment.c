#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "forest-disjoint-set.h"

int main(int argc, char **argv) {
    srand(0);

    size_t n = 100;
    size_t m = n - 1;

    if (argc == 3) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }

    ForestElement **standard_elements = (ForestElement**)malloc(n * sizeof(ForestElement*));
    ForestElement **by_rank_elements = (ForestElement**)malloc(n * sizeof(ForestElement*));

    clock_t standard_start = clock();
        for (size_t i = 0; i < n; ++i)
            standard_elements[i] = make_forest_set(rand() % (10 * n));

        // Worst Case merges
        for (size_t i = 0; i < m; ++i)
            union_forest_sets(standard_elements[i + 1], standard_elements[0]);

    clock_t standard_end = clock();
    double standard_duration = (double)(standard_end - standard_start) / CLOCKS_PER_SEC;
    for (size_t i = 0; i < n; ++i) {
        free(standard_elements[i]);
    }

    clock_t by_rank_start = clock();
        for (size_t i = 0; i < n; ++i)
            by_rank_elements[i] = make_forest_set(rand() % (10 * n));

        // Worst Case merges
        for (size_t i = 0; i < m; ++i)
            by_rank_union_forest_sets(by_rank_elements[i + 1], by_rank_elements[0]);

    clock_t by_rank_end = clock();
    double by_rank_duration = (double)(by_rank_end - by_rank_start) / CLOCKS_PER_SEC;
    for (size_t i = 0; i < n; ++i) {
        free(by_rank_elements[i]);
    }

    // Format: n,set_type,heuristic_type,duration_seconds
    printf("%ld,Forest,None,%lf\n", n, standard_duration);
    printf("%ld,Forest,Rank,%lf\n", n, by_rank_duration);
}