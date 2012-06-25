#ifndef _LIST_H_
#define _LIST_H_

#include <pthread.h>
#include <stdlib.h>

struct _list_node {
    struct _list_node * next;
    void              * item;
};

typedef struct _list_node list_node;

typedef struct {
    pthread_mutex_t * mutex;
    list_node       * HEAD;
} list_st;

extern int    list_init ( list_st ** );
extern int    list_push ( list_st *, void * );
extern void * list_pop  ( list_st * );

#endif
