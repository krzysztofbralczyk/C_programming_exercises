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
int dll_sort_asc(struct doubly_linked_list_t* dll) {
    if (dll == NULL || dll->head == NULL) return 1;
    int sorted = 0;
    
    while (!sorted) {
        sorted = 1;
        int triggered;
        struct node_t* copy = dll->head;
        
        while (copy->next != NULL) {
            triggered = 0;
            if (copy->data > copy->next->data) {
                triggered = 1;
                sorted = 0;
                if (copy == dll->head) dll->head = copy->next;
                if (copy->next == dll->tail) dll->tail = copy;
                

                struct node_t* temp = copy->next;
                if (copy->prev == NULL && temp->next == NULL) {
                    temp->prev = NULL;
                    copy->next = NULL;
                    copy->prev = temp;
                    temp->next = copy;
                }
                else if (copy->prev == NULL) {
                    temp->prev = NULL;
                    copy->prev = temp;
                    copy->next = temp->next;
                    temp->next->prev = copy;
                    temp->next = copy;
                }
                else if (temp->next == NULL) {
                    copy->prev->next = temp;
                    temp->prev = copy->prev;
                    copy->prev = temp;
                    copy->next = NULL;
                    temp->next = copy;
                }
                else {
                    copy->prev->next = copy->next;
                    copy->next->next->prev = copy;
                    copy->next->prev = copy->prev;
                    copy->prev = copy->next;
                    copy->next = copy->next->next;
                    copy->prev->next = copy;
                }
            }
            if(!triggered)copy = copy->next;
        }
    }
    return 0;
}
int dll_sort_desc(struct doubly_linked_list_t* dll){
   if (dll == NULL || dll->head == NULL) return 1;
    int sorted = 0;
    
    while (!sorted) {
        sorted = 1;
        int triggered;
        struct node_t* copy = dll->head;
        
        while (copy->next != NULL) {
            triggered = 0;
            if (copy->data < copy->next->data) {
                triggered = 1;
                sorted = 0;
                if (copy == dll->head) dll->head = copy->next;
                if (copy->next == dll->tail) dll->tail = copy;
                

                struct node_t* temp = copy->next;
                if (copy->prev == NULL && temp->next == NULL) {
                    temp->prev = NULL;
                    copy->next = NULL;
                    copy->prev = temp;
                    temp->next = copy;
                }
                else if (copy->prev == NULL) {
                    temp->prev = NULL;
                    copy->prev = temp;
                    copy->next = temp->next;
                    temp->next->prev = copy;
                    temp->next = copy;
                }
                else if (temp->next == NULL) {
                    copy->prev->next = temp;
                    temp->prev = copy->prev;
                    copy->prev = temp;
                    copy->next = NULL;
                    temp->next = copy;
                }
                else {
                    copy->prev->next = copy->next;
                    copy->next->next->prev = copy;
                    copy->next->prev = copy->prev;
                    copy->prev = copy->next;
                    copy->next = copy->next->next;
                    copy->prev->next = copy;
                }
            }
            if(!triggered)copy = copy->next;
        }
    }
    return 0;
}
