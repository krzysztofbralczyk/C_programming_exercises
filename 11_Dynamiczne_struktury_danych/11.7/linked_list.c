#include "linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct linked_list_t* ll_create(){
    struct linked_list_t* list = (struct linked_list_t*)malloc(sizeof(struct linked_list_t));
    if(list == NULL) return list;
    list->head = NULL;
    list->tail = NULL;
    return list;
}
int ll_push_back(struct linked_list_t* ll, int value){
    if(ll == NULL) return 1;
    struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
    if(node == NULL) return 2;
    node->data = value;
    node->next = NULL;

    if(ll->tail == NULL){
        ll->head = node;
        ll->tail = node;
        return 0;
    }
    
    ll->tail->next = node;
    ll->tail = node;
    return 0;
}
int ll_push_front(struct linked_list_t* ll, int value){
    if(ll == NULL) return 1;
    struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
    if(node == NULL) return 2;
    node->data = value;
    node->next = ll->head;

    if(ll->head == NULL){
        ll->head = node;
        ll->tail = node;
        return 0;
    }

    ll->head = node;
    return 0;
}
int ll_pop_front(struct linked_list_t* ll, int *err_code){
    if(ll == NULL || ll->head == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    int to_be_returned = ll->head->data;

    if(ll_size(ll) == 1){
        free(ll->head);
        ll->tail = NULL;
        ll->head = NULL;
        if(err_code != NULL)*err_code = 0;
        return to_be_returned;
    }

    struct node_t* to_be_deallocated = ll->head;
    ll->head = ll->head->next;
    free(to_be_deallocated);
    if(err_code != NULL)*err_code = 0;
    return to_be_returned;
}
int ll_pop_back(struct linked_list_t* ll, int *err_code){
    if(ll == NULL || ll->tail == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    int to_be_returned = ll->tail->data;

    if(ll_size(ll) == 1){
        free(ll->tail);
        ll->tail = NULL;
        ll->head = NULL;
        if(err_code != NULL)*err_code = 0;
        return to_be_returned;
    }

    struct node_t* copy = ll->head;
    struct node_t* prev_copy = copy;
    while(copy->next != NULL){
        prev_copy = copy;
        copy = copy->next; 
    }
    ll->tail = prev_copy;
    ll->tail->next = NULL;
    free(copy);

    if(err_code != NULL)*err_code = 0;
    return to_be_returned;
}
int ll_back(const struct linked_list_t* ll, int *err_code){
    if(ll == NULL || ll->tail == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    if(err_code != NULL)*err_code = 0;
    return ll->tail->data;

}
int ll_front(const struct linked_list_t* ll, int *err_code){
    if(ll == NULL || ll->head == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    if(err_code != NULL)*err_code = 0;
    return ll->head->data;
}
struct node_t* ll_begin(struct linked_list_t* ll){
    if(ll == NULL) return NULL;
    return ll->head;
}
struct node_t* ll_end(struct linked_list_t* ll){
    if(ll == NULL) return NULL;
    return ll->tail;
}
int ll_size(const struct linked_list_t* ll){
    if(ll == NULL) return -1;
    struct node_t* copy = ll->head;
    int counter = 0;
    while(copy != NULL){
        counter++;
        copy = copy->next;
    }
    return counter;
}
int ll_is_empty(const struct linked_list_t* ll){
    if(ll == NULL) return -1;
    if(ll->head == NULL) return 1;
    return 0;
}
int ll_at(const struct linked_list_t* ll, unsigned int index, int *err_code){
    if(ll == NULL){if(err_code != NULL)*err_code = 1; return 777;}
    if((int)index > ll_size(ll)-1){if(err_code != NULL)*err_code = 1; return 777;}

    struct node_t* node = ll->head;
    for(unsigned int i = 0; i < index; i++){
        node = node->next;
    }
    if(err_code != NULL)*err_code = 0;
    if(node!=NULL)return node->data;
    return 666;
}
int ll_insert(struct linked_list_t* ll, unsigned int index, int value){
    if(ll == NULL) return 1;
    if(ll_size(ll) < (int)index) return 1;
    if((int)index < 0) return 1;

    struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
    if(node == NULL) return 2;
    node->data = value;
    node->next = NULL;
    
    if(ll->head == NULL){
        ll->head = node;
        ll->tail = node;
        return 0;
    }

    if(index == 0){
        free(node);
        ll_push_front(ll, value);
        return 0;
    }
    if((int)index == ll_size(ll)){
        free(node);
        ll_push_back(ll,value);
        return 0;
    }

    struct node_t* prev_copy = ll->head;
    struct node_t* copy = ll->head;
  
    for(unsigned int i = 0; i < index; i++){
        prev_copy = copy;
        copy = copy->next;
    }
    node->next = copy;
    prev_copy->next = node;

    return 0;
}
int ll_remove(struct linked_list_t* ll, unsigned int index, int *err_code){
    if(ll == NULL || ll->head == NULL){if(err_code!=NULL)*err_code = 1; return 776;}
    if(index > (unsigned)ll_size(ll)-1) {if(err_code!=NULL)*err_code = 1; return 778;}

    if(ll_size(ll) == 1){
        int to_be_returned = ll->head->data;
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
        if(err_code != NULL) *err_code = 0;
        return to_be_returned;
    }

    if(index == 0){
        if(err_code != NULL) *err_code = 0;
        return ll_pop_front(ll,err_code);
    }

    if((int)index == ll_size(ll)-1){
        if(err_code != NULL) *err_code = 0;
        return ll_pop_back(ll,err_code);
    }

    struct node_t* previous = ll->head;
    for(unsigned int i = 0; i < index-1; i++){
        previous = previous->next;
    }
    struct node_t* to_be_deleted = previous->next;

    previous->next = previous->next->next;
    int to_be_returned = to_be_deleted->data;
    free(to_be_deleted);
    if(err_code != NULL) *err_code = 0;
    return to_be_returned;
}
void ll_clear(struct linked_list_t* ll){
    if(ll == NULL || ll->head == NULL) return;
    struct node_t* node = ll->head;
    while(node != NULL) {
        struct node_t* temp = node;
        node = node->next;
        free(temp);
    }
    ll->head = NULL;
    ll->tail = NULL;
}
void ll_display(const struct linked_list_t* ll){
    if(ll == NULL || ll->head == NULL) return;
    struct node_t* node = ll->head;
    while(node != NULL) {
        printf("%d ",node->data);
        node = node->next;
    }
}
