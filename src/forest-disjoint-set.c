#include <stdlib.h>
#include <stdint.h>

#include "forest-disjoint-set.h"

ForestElement *make_forest_set(int32_t value) {
    ForestElement *element = (ForestElement*)malloc(sizeof(ForestElement));
    element->parent = element;
    element->value = value;
    element->rank = 0;

    return element;
}

ForestElement *find_forest_set(ForestElement *element) {
    ForestElement *current = element;
    while (current->parent != current) 
        current = current->parent;

    return current;
}

ForestElement *rank_find_forest_set(ForestElement *element) {
    if (element->parent != element)
        element->parent = rank_find_forest_set(element->parent);

    return element->parent;
}

void union_forest_sets(ForestElement *extended_representative, ForestElement *discarded_representative) {
    ForestElement *extended_root = find_forest_set(extended_representative);
    ForestElement *discarded_root = find_forest_set(discarded_representative);
    discarded_root->parent = extended_root;
}

void by_rank_union_forest_sets(ForestElement *left_representative, ForestElement *right_representative) {
    link_forest_sets(rank_find_forest_set(left_representative), rank_find_forest_set(right_representative));
}

void link_forest_sets(ForestElement *left_representative, ForestElement *right_representative) {
    if (left_representative->rank > right_representative->rank) {
        right_representative->parent = left_representative;
    } else {
        left_representative->parent = right_representative;

        if (left_representative->rank == right_representative->rank)
            right_representative->rank += 1;
    }
}