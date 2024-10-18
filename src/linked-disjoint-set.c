#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#include "linked-disjoint-set.h"

LinkedElement *make_linked_set(int32_t value) {
    LinkedElement *element = (LinkedElement*)malloc(sizeof(LinkedElement));
    LinkedSet *set = (LinkedSet*)malloc(sizeof(LinkedSet));
    element->value = value;
    element->next = NULL;
    element->owner = set;

    set->head = element;
    set->tail = element;
    set->length = 1;

    return element;
}

LinkedElement *find_linked_set(LinkedElement *element) {
    return element->owner->head;
}

void union_linked_sets(LinkedElement* extended_representative, LinkedElement* discarded_representative) {
    extended_representative->owner->tail->next = find_linked_set(discarded_representative);
    extended_representative->owner->tail = discarded_representative->owner->tail;
    LinkedSet *discarded_set = discarded_representative->owner;

    LinkedElement *element = find_linked_set(discarded_representative);
    while (element != NULL) {
        element->owner = extended_representative->owner;
        element = element->next;
    }

    free(discarded_set);
}

void weighted_union_linked_sets(LinkedElement* left_representative, LinkedElement* right_representative) {
    LinkedSet *discarded_set;
    LinkedSet *extended_set;

    if (left_representative->owner->length < right_representative->owner->length) {
        discarded_set = left_representative->owner;
        extended_set = right_representative->owner;
    } else {
        discarded_set = right_representative->owner;
        extended_set = left_representative->owner;
    }

    extended_set->length += discarded_set->length;
    extended_set->tail->next = discarded_set->head;

    LinkedElement *element = discarded_set->head;
    while (element != NULL) {
        element->owner = extended_set;
        element = element->next;
    }

    free(discarded_set);
}