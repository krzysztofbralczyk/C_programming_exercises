#include "doubly_linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct doubly_linked_list_t* dll_create(){
    struct doubly_linked_list_t* list = (struct doubly_linked_list_t*)malloc(sizeof(struct doubly_linked_list_t));
    if(list == NULL) return list;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int dll_push_back(struct doubly_linked_list_t* dll, int value){
    if(dll == NULL) return 1;
    struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
    if(node == NULL) return 2;
    node->data = value;
    node->next = NULL;
    node->prev = dll->tail;

    if(dll->tail == NULL){
        dll->head = node;
        dll->tail = node;
        return 0;
    }
    
    dll->tail->next = node;
    dll->tail = node;
    return 0;
}
int dll_push_front(struct doubly_linked_list_t* dll, int value){
    if(dll == NULL) return 1;
    struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
    if(node == NULL) return 2;
    node->data = value;
    node->next = dll->head;
    node->prev = NULL;
    
    if(dll->head == NULL){
        dll->head = node;
        dll->tail = node;
        return 0;
    }
    dll->head->prev = node;
    dll->head = node;
    return 0;
}
int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code){
    if(dll == NULL || dll->head == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    int to_be_returned = dll->head->data;

    if(dll_size(dll) == 1){
        free(dll->head);
        dll->tail = NULL;
        dll->head = NULL;
        if(err_code != NULL)*err_code = 0;
        return to_be_returned;
    }

    struct node_t* to_be_deallocated = dll->head;
    dll->head->next->prev = NULL;
    dll->head = dll->head->next;
    free(to_be_deallocated);
    if(err_code != NULL)*err_code = 0;
    return to_be_returned;
}
int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code){
    if(dll == NULL || dll->tail == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    int to_be_returned = dll->tail->data;

    if(dll_size(dll) == 1){
        free(dll->tail);
        dll->tail = NULL;
        dll->head = NULL;
        if(err_code != NULL)*err_code = 0;
        return to_be_returned;
    }

    struct node_t* to_be_deallocated = dll->tail;
    dll->tail->prev->next = NULL;
    dll->tail = dll->tail->prev;
    free(to_be_deallocated);
    if(err_code != NULL)*err_code = 0;
    return to_be_returned;
}
int dll_back(const struct doubly_linked_list_t* dll, int *err_code){
    if(dll == NULL || dll->tail == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    if(err_code != NULL)*err_code = 0;
    return dll->tail->data;
}
int dll_front(const struct doubly_linked_list_t* dll, int *err_code){
    if(dll == NULL || dll->head == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    if(err_code != NULL)*err_code = 0;
    return dll->head->data;
}

struct node_t* dll_begin(struct doubly_linked_list_t* dll){
    if(dll == NULL) return NULL;
    return dll->head;
}
struct node_t* dll_end(struct doubly_linked_list_t* dll){
    if(dll == NULL) return NULL;
    return dll->tail;
}
int dll_size(const struct doubly_linked_list_t* dll){
    if(dll == NULL) return -1;
    struct node_t* copy = dll->head;
    int counter = 0;
    while(copy != NULL){
        counter++;
        copy = copy->next;
    }
    return counter;
}
int dll_is_empty(const struct doubly_linked_list_t* dll){
    if(dll == NULL) return -1;
    if(dll->head == NULL) return 1;
    return 0;
}

int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int *err_code){
    if(dll == NULL){if(err_code != NULL)*err_code = 1; return 777;}
    if((int)index > dll_size(dll)-1){if(err_code != NULL)*err_code = 1; return 777;}

    struct node_t* node = dll->head;
    for(unsigned int i = 0; i < index; i++){
        node = node->next;
    }
    if(err_code != NULL)*err_code = 0;
    if(node!=NULL)return node->data;
    return 666;
}

int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value){
    if(dll == NULL) return 1;
    if(dll_size(dll) < (int)index) return 1;
    if((int)index < 0) return 1;

    struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
    if(node == NULL) return 2;
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    
    if(dll->head == NULL){
        dll->head = node;
        dll->tail = node;
        return 0;
    }
    if(index == 0){
        free(node);
        dll_push_front(dll, value);
        return 0;
    }
    if((int)index == dll_size(dll)){
        free(node);
        dll_push_back(dll,value);
        return 0;
    }

    struct node_t* prev_copy = dll->head;
    struct node_t* copy = dll->head;
  
    for(unsigned int i = 0; i < index; i++){
        prev_copy = copy;
        copy = copy->next;
    }
    node->next = copy;
    node->prev = prev_copy;
    prev_copy->next = node;
    node->next->prev = node;

    return 0;
}
int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int *err_code){
    if(dll == NULL || dll->head == NULL){if(err_code!=NULL)*err_code = 1; return 776;}
    if(index > (unsigned)dll_size(dll)-1) {if(err_code!=NULL)*err_code = 1; return 778;}

    if(dll_size(dll) == 1){
        int to_be_returned = dll->head->data;
        free(dll->head);
        dll->head = NULL;
        dll->tail = NULL;
        if(err_code != NULL) *err_code = 0;
        return to_be_returned;
    }

    if(index == 0){
        if(err_code != NULL) *err_code = 0;
        return dll_pop_front(dll,err_code);
    }

    if((int)index == dll_size(dll)-1){
        if(err_code != NULL) *err_code = 0;
        return dll_pop_back(dll,err_code);
    }

    struct node_t* previous = dll->head;
    for(unsigned int i = 0; i < index-1; i++){
        previous = previous->next;
    }
    struct node_t* to_be_deleted = previous->next;

    previous->next = previous->next->next;
    previous->next->prev = previous;

    int to_be_returned = to_be_deleted->data;
    free(to_be_deleted);
    if(err_code != NULL) *err_code = 0;
    return to_be_returned;
}
void dll_clear(struct doubly_linked_list_t* dll){
    if(dll == NULL || dll->head == NULL) return;
    struct node_t* node = dll->head;
    while(node != NULL) {
        struct node_t* temp = node;
        node = node->next;
        free(temp);
    }
    dll->head = NULL;
    dll->tail = NULL;
}

void dll_display(const struct doubly_linked_list_t* dll){
    if(dll == NULL || dll->head == NULL) return;
    struct node_t* node = dll->head;
    while(node != NULL) {
        printf("%d ",node->data);
        node = node->next;
    }
}
void dll_display_reverse(const struct doubly_linked_list_t* dll){
    if(dll == NULL || dll->tail == NULL) return;
    struct node_t* node = dll->tail;
    while(node != NULL) {
        printf("%d ",node->data);
        node = node->prev;
    }
}
