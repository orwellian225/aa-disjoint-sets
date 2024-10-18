#pragma once

#include <stddef.h>
#include <stdint.h>

typedef struct ForestElement ForestElement;

struct ForestElement {
    int32_t value;
    ForestElement *parent;

    size_t rank;
};

ForestElement *make_forest_set(int32_t value);
ForestElement *find_forest_set(ForestElement *element);
ForestElement *rank_find_forest_set(ForestElement *element);

void union_forest_sets(ForestElement *merged_representative, ForestElement* discarded_representative);
void by_rank_union_forest_sets(ForestElement *left_representative, ForestElement* right_representative);
    void link_forest_sets(ForestElement *left_representative, ForestElement *right_representative);