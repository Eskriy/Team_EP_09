#include "teamvec.h"
#include <stdio.h>
#include <stdlib.h>

struct teamvec {
    Team **data;
    int size;
    int capacity;
};

TeamVec *tv_create(void) {
    TeamVec *tv = malloc(sizeof(TeamVec));
    if (tv == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    tv->size = 0;
    tv->capacity = 4;
    tv->data = malloc(tv->capacity * sizeof(Team *));
    if (tv->data == NULL) {
        free(tv);
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    if (tv->size == tv->capacity) {
        int new_capacity = tv->capacity * 2;
        Team **temp = realloc(tv->data, new_capacity * sizeof(Team *));
        if (temp == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        tv->data = temp;
        tv->capacity = new_capacity;
    }

    tv->data[tv->size] = t;
    tv->size++;
}

int tv_size(TeamVec *tv) {
    return tv->size;
}

Team *tv_get(TeamVec *tv, int i) {
    if (i < 0 || i >= tv->size)
        return NULL;
    return tv->data[i];
}

void tv_free(TeamVec *tv) {
    if (tv == NULL)
        return;

    for (int i = 0; i < tv->size; i++)
        team_free(tv->data[i]);
    free(tv->data);
    free(tv);
}
