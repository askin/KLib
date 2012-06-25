#include "list.h"

// listeyi ilkle
int list_init ( list_st ** list ) {
    list_st * new_list;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

    new_list = (list_st *)malloc(sizeof(list));
    if (new_list == NULL) return -1; // yer ayrilamadi

    new_list->HEAD  = NULL;
    new_list->mutex = &m;

    *list = new_list;
    return 1;
}

int list_push ( list_st * list, void * item ) {

    pthread_mutex_lock(list->mutex);
    list_node * ln = (list_node *)malloc(sizeof(list_node));
    list_node * tmp_node;

    if ( ln == NULL ) {
        pthread_mutex_unlock(list->mutex);
        return -1; // yer ayrilamadi
    }

    ln->next = NULL;
    ln->item = item;

    if ( list->HEAD == NULL ) {
        list->HEAD = ln;
        pthread_mutex_unlock(list->mutex);
        return 1;
    }

    // bir sonraki node null oluncaya kadar ara
    tmp_node = list->HEAD;
    while ( tmp_node->next != NULL ) {
        tmp_node = tmp_node->next;
    }

    tmp_node->next = ln;
    pthread_mutex_unlock(list->mutex);
    return 1;

}

void * list_pop (list_st * list) {
    list_node * tmp_node;

    pthread_mutex_lock(list->mutex);

    if ( list->HEAD == NULL ) {
        pthread_mutex_unlock(list->mutex);
        return NULL;
    }

    tmp_node = list->HEAD;
    list->HEAD = tmp_node->next;

    pthread_mutex_unlock(list->mutex);
    return tmp_node->item;
}
