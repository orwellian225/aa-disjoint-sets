#pragma once

#include <stddef.h>
#include <stdint.h>

typedef struct LinkedSet LinkedSet;
typedef struct LinkedElement LinkedElement;

struct LinkedSet {
    LinkedElement *head;
    LinkedElement *tail;
    size_t length;
};

struct LinkedElement {
    int32_t value;
    LinkedElement *next;
    LinkedSet *owner;
};

LinkedElement *make_linked_set(int32_t value);
LinkedElement *find_linked_set(LinkedElement *element);

void union_linked_sets(LinkedElement* extended_representative, LinkedElement* discarded_representative);
void weighted_union_linked_sets(LinkedElement* left_representative, LinkedElement* right_representative);