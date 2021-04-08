#include "heap.h"
#include "custom_unistd.h"
#include <string.h>

struct memory_manager_t memory_manager;

int calculate_checksum(void* memblock) {
    if(memblock == NULL) return 0;

    int sum = 0;
    unsigned char* p = (unsigned char *)memblock;
    unsigned int limit = sizeof(memory_chunk_t) - sizeof(long long int);
    for (unsigned int i = 0; i < limit; ++i) {
        sum += p[i];
    }

    return sum;
}
int heap_setup(void) {
    memory_manager.memory_start = custom_sbrk(0);
    if(memory_manager.memory_start == NULL) return -1;
    memory_manager.first_memory_chunk = NULL;
    memory_manager.memory_size = 0;
    return 0;
}
void heap_clean(void) {
    if(memory_manager.memory_start == NULL) return;

    custom_sbrk(-memory_manager.memory_size);
    memory_manager.first_memory_chunk = NULL;
    memory_manager.memory_start = NULL;
    memory_manager.memory_size = 0;
}
void* heap_malloc(size_t size) {
    if(size <= 0) return NULL;
    if(heap_validate() != 0) return NULL;
    struct memory_chunk_t* temp = memory_manager.first_memory_chunk;
    while (temp != NULL && (temp->size - 2 * PLOTEK_LENGTH < (long long)size || temp->free != 1))temp = temp->next;

    //jeśli nie znalazles wystarczajaco duzego bloku
    if (temp == NULL)
    {
        memory_chunk_t* temp2 = custom_sbrk(size + sizeof(memory_chunk_t) + 2*PLOTEK_LENGTH);
        //jeśli brak miejsca na stercie to zwróć null
        if( temp2 == (void*)-1) return NULL;

        else{
            //wystarczająco miejsca na stercie
            memory_manager.memory_size += size + sizeof(memory_chunk_t) + 2 * PLOTEK_LENGTH;

            if(memory_manager.first_memory_chunk == NULL){
                memory_chunk_t a = {NULL, NULL, size, 0, 0};
                a.checksum = calculate_checksum(&a);
                memory_manager.first_memory_chunk = temp2;
                *(memory_manager.first_memory_chunk) = a;
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(memory_chunk_t) + i) = '#';
                    *(char*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size) = '#';
                }
                return (void*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(struct memory_chunk_t) + PLOTEK_LENGTH);

            } else {
                memory_chunk_t* last = memory_manager.first_memory_chunk;
                while(last->next != NULL)last = last->next;
                last->next = temp2;
                last->checksum = calculate_checksum(last);
                memory_chunk_t a = {last, NULL, size, 0, 0};
                a.checksum = calculate_checksum(&a);
                *(struct memory_chunk_t*)(last->next) = a;
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)last->next + sizeof(memory_chunk_t) + i) = '#';
                    *(char*)((uint8_t*)last->next + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size) = '#';
                }
                return (void*)((uint8_t*)(last->next) + sizeof(struct memory_chunk_t) + PLOTEK_LENGTH);
            }
        }
    }

    else{
        //found free block of big enough size
        temp->free = 0;
        temp->size = size;

        for(int i = 0; i < PLOTEK_LENGTH; i++){
            *(char*)((uint8_t*)temp + sizeof(memory_chunk_t) + i) = '#';
            *(char*)((uint8_t*)temp + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size) = '#';
        }

        temp->checksum = calculate_checksum(temp);
        return (void*)((uint8_t*)temp + sizeof(memory_chunk_t) + PLOTEK_LENGTH);
    }
}
void* heap_calloc(size_t number, size_t size) {
    if(size <= 0 || number <= 0) return NULL;
    if(heap_validate() != 0) return NULL;
    size_t size_calloced = number * size;

    struct memory_chunk_t* temp = memory_manager.first_memory_chunk;
    while (temp != NULL && (temp->size - 2 * PLOTEK_LENGTH < (long long)size_calloced || temp->free != 1))temp = temp->next;

    //jeśli nie znalazles wystarczajaco duzego bloku
    if (temp == NULL)
    {
        memory_chunk_t* temp2 = custom_sbrk(size_calloced + sizeof(memory_chunk_t) + 2*PLOTEK_LENGTH);

        //jeśli brak miejsca na stercie to zwróć null
        if( temp2 == (void*)-1) return NULL;
        else{
            memset(temp2,0,size_calloced + sizeof(memory_chunk_t) + 2*PLOTEK_LENGTH);
            //wystarczająco miejsca na stercie
            memory_manager.memory_size += size_calloced + sizeof(memory_chunk_t) + 2 * PLOTEK_LENGTH;

            if(memory_manager.first_memory_chunk == NULL){
                memory_chunk_t a = {NULL, NULL, size_calloced, 0, 0};
                a.checksum = calculate_checksum(&a);
                memory_manager.first_memory_chunk = temp2;
                *(memory_manager.first_memory_chunk) = a;
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(memory_chunk_t) + i) = '#';
                    *(char*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size_calloced) = '#';
                }
                return (void*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(struct memory_chunk_t) + PLOTEK_LENGTH);

            } else {
                memory_chunk_t* last = memory_manager.first_memory_chunk;
                while(last->next != NULL)last = last->next;
                last->next = temp2;
                last->checksum = calculate_checksum(last);
                memory_chunk_t a = {last, NULL, size_calloced, 0, 0};
                a.checksum = calculate_checksum(&a);
                *(struct memory_chunk_t*)(last->next) = a;
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)last->next + sizeof(memory_chunk_t) + i) = '#';
                    *(char*)((uint8_t*)last->next + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size_calloced) = '#';
                }
                return (void*)((uint8_t*)(last->next) + sizeof(struct memory_chunk_t) + PLOTEK_LENGTH);
            }
        }
    }

    else{
        //found free block of big enough size
        temp->free = 0;
        temp->size = size_calloced;

        for(int i = 0; i < PLOTEK_LENGTH; i++){
            *(char*)((uint8_t*)temp + sizeof(memory_chunk_t) + i) = '#';
            *(char*)((uint8_t*)temp + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size_calloced) = '#';
        }

        temp->checksum = calculate_checksum(temp);
        return (void*)((uint8_t*)temp + sizeof(memory_chunk_t) + PLOTEK_LENGTH);
    }
}
void* heap_realloc(void* memblock, size_t count) {
    if(heap_validate() != 0) return NULL;
    if(memblock == NULL && count == 0) return NULL;
    if(memblock == NULL) return heap_malloc(count);
    if(get_pointer_type(memblock) != pointer_valid) return NULL;
    if(memblock != NULL && count == 0) {heap_free(memblock); return NULL;}


    memory_chunk_t* chunk = (memory_chunk_t*) ((uint8_t*)memblock - PLOTEK_LENGTH - sizeof(memory_chunk_t));

    if(chunk->size == (long long)count) return memblock; //bloki rowne

    else if(chunk->size > (long long)count){ //pomniejszamy blok

        for(int i = 0; i < PLOTEK_LENGTH; i++) {
            *(char*)((uint8_t*)memblock + count + i) = '#';
        }

        if(chunk->next == NULL){
            custom_sbrk(-(chunk->size - count));
            memory_manager.memory_size -= (chunk->size - count);
        }

        chunk->size = count;
        chunk->checksum = calculate_checksum(chunk);
        return memblock;
    }

    else { //powiekszamy blok
        if(chunk->next == NULL){
            if(custom_sbrk(count - chunk->size) == (void *) -1) return NULL;
            memory_manager.memory_size += count - chunk->size;
            chunk->size = count;
            chunk->checksum = calculate_checksum(chunk);

            for(int i = 0; i < PLOTEK_LENGTH; i++){
                *(char*)((uint8_t*)memblock + count + i) = '#';
            }
            return memblock;
        }
        else if(chunk->next->free == 0){ //Nastepny blok jest zajety
            // [XXXX##xxxx##....Uuuuu]
            unsigned long long free_space_after_chunk = ((uint8_t*)chunk->next) -
                    ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH);
            if(free_space_after_chunk >= count - chunk->size){
                chunk->size = count;
                chunk->checksum = calculate_checksum(chunk);
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)memblock + count + i) = '#';
                }
                return memblock;
            }
        }
        else if (chunk->next->free == 1){
            //[XXXX##xxxx##....FFFFffffffffffffUUUU##uuuu##]
            unsigned long long free_space_after_chunk =
                    (uint8_t*)(chunk->next->next) - sizeof(struct memory_chunk_t) - ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH);
            if(free_space_after_chunk >= count - chunk->size){
                int move_F_by = count - chunk->size - (((uint8_t*)chunk->next) -
                                                       ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH));
                chunk->next->size -= move_F_by;
                chunk->next->checksum = calculate_checksum(chunk->next);
                chunk->next = (struct memory_chunk_t*)memmove((uint8_t *)chunk->next + move_F_by,chunk->next,sizeof(memory_chunk_t));
                chunk->next->next->prev = chunk->next;
                chunk->next->next->checksum = calculate_checksum(chunk->next->next);
                chunk->size = count;
                chunk->checksum = calculate_checksum(chunk);
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)memblock + count + i) = '#';
                }
                return memblock;
            }
        }

        // przenosimy blok
        void* temp = heap_malloc(count);
        if(temp == NULL) return NULL;

        memcpy(temp,memblock,((memory_chunk_t*)((uint8_t*)memblock - PLOTEK_LENGTH - sizeof(memory_chunk_t)))->size);
        heap_free(memblock);
        return temp;
    }
}
void  heap_free(void* address) {
//    printf("\nStart");
    if( get_pointer_type(address) != pointer_valid ) {
        return;
    }
//    printf("\nEnd");
    memory_chunk_t* current_chunk_p = (memory_chunk_t*)((uint8_t*)address - sizeof(memory_chunk_t) - PLOTEK_LENGTH);
    memory_chunk_t* prev_chunk = current_chunk_p->prev;
    memory_chunk_t* next_chunk = current_chunk_p->next;

    if(prev_chunk != NULL && next_chunk != NULL){

        if(prev_chunk->free == 0 && next_chunk->free == 0){
            // [UuuuuuXxxxxxUuuuuu] [UuuuuuXxxx..Uuuuuu] [Uuu...Xxx...Uuuuuu]
            current_chunk_p->free = 1;
            current_chunk_p->size = (uint8_t*)(current_chunk_p->next) - ((uint8_t*)current_chunk_p + sizeof(struct memory_chunk_t));
            current_chunk_p->checksum = calculate_checksum(current_chunk_p);
        }

        else if(prev_chunk->free == 0 && next_chunk->free == 1){
            // [UuuuuuXxxxxxFfffffUuuuuu]
            current_chunk_p->free = 1;
            current_chunk_p->size = (uint8_t*)current_chunk_p->next->next - ((uint8_t*)current_chunk_p + sizeof(struct memory_chunk_t));
            current_chunk_p->next = current_chunk_p->next->next;
            current_chunk_p->checksum = calculate_checksum(current_chunk_p);

            current_chunk_p->next->prev = current_chunk_p;
            current_chunk_p->next->checksum = calculate_checksum(current_chunk_p->next);
        }

        else if(prev_chunk->free == 1 && next_chunk->free == 0){
            // [FfffffXxxxxxUuuuuu] [UuuuuuFfffffXxxxxxUuuuuu] [FfffffXxx...Uuuuuu] [UuuuuuFfffffXxx...Uuuuuu]
            current_chunk_p->prev->size = (uint8_t*)current_chunk_p->next - ((uint8_t*)current_chunk_p->prev + sizeof(struct memory_chunk_t));
            current_chunk_p->prev->next = current_chunk_p->next;
            current_chunk_p->prev->checksum = calculate_checksum(current_chunk_p->prev);

            current_chunk_p->next->prev = current_chunk_p->prev;
            current_chunk_p->next->checksum = calculate_checksum(current_chunk_p->next);
        }

        else if(prev_chunk->free == 1 && next_chunk->free == 1){
            // [FfffffXxx...FfffffUuuuuu]
            current_chunk_p->prev->size = (uint8_t*)current_chunk_p->next->next - ((uint8_t*)current_chunk_p->prev + sizeof(struct memory_chunk_t));
            current_chunk_p->prev->next = current_chunk_p->next->next;
            current_chunk_p->prev->checksum = calculate_checksum(current_chunk_p->prev);

            current_chunk_p->next->next->prev = current_chunk_p->prev;
            current_chunk_p->next->next->checksum = calculate_checksum(current_chunk_p->next->next);
        }

    }
    else if (prev_chunk == NULL && next_chunk != NULL){

        current_chunk_p->free = 1;

        if (next_chunk->free == 0){
            // [Xxx...Uuuuuu]
            current_chunk_p->size = (uint8_t*)(current_chunk_p->next) - ((uint8_t*)current_chunk_p + sizeof(struct memory_chunk_t));
            current_chunk_p->checksum = calculate_checksum(current_chunk_p);
        }
        else {
            // [Xxx...FfffffUuuuuu]
            current_chunk_p->size = (uint8_t*)(current_chunk_p->next->next) - ((uint8_t*)current_chunk_p + sizeof(struct memory_chunk_t));
            current_chunk_p->next = current_chunk_p->next->next;
            current_chunk_p->checksum = calculate_checksum(current_chunk_p);

            current_chunk_p->next->prev = current_chunk_p;
            current_chunk_p->next->checksum = calculate_checksum(current_chunk_p->next);
        }

    }
    else if (prev_chunk != NULL && next_chunk == NULL){
        // [Uuu...Xxxxxx]
        if (prev_chunk->free == 0){

            int size_to_be_deallocated = ((uint8_t*)current_chunk_p + sizeof(memory_chunk_t) + current_chunk_p->size + 2* PLOTEK_LENGTH) -
                    ((uint8_t *)current_chunk_p->prev + sizeof(memory_chunk_t) + current_chunk_p->prev->size + 2* PLOTEK_LENGTH);

            current_chunk_p->prev->next = NULL;
            current_chunk_p->prev->checksum = calculate_checksum(current_chunk_p->prev);
            custom_sbrk(-size_to_be_deallocated);
            memory_manager.memory_size -= size_to_be_deallocated;
        }
        else if (prev_chunk->free == 1){
            if (current_chunk_p->prev->prev != NULL){
                //[UuuuuuFfffffXxxxxx]

                int size_to_be_deallocated = ((uint8_t*)current_chunk_p + sizeof(memory_chunk_t) + current_chunk_p->size + 2* PLOTEK_LENGTH) -
                        ((uint8_t*) current_chunk_p->prev->prev + sizeof(memory_chunk_t) + current_chunk_p->prev->prev->size + 2*PLOTEK_LENGTH);

                current_chunk_p->prev->prev->next = NULL;
                current_chunk_p->prev->prev->checksum = calculate_checksum(current_chunk_p->prev->prev);
                custom_sbrk(-size_to_be_deallocated);
                memory_manager.memory_size -= size_to_be_deallocated;
            } else {
                // [FfffffXxxxxx]
                memory_manager.first_memory_chunk = NULL;
                custom_sbrk(-memory_manager.memory_size);
                memory_manager.memory_size = 0;
            }
        }
    }
    else {
        memory_manager.first_memory_chunk = NULL;
        custom_sbrk(-memory_manager.memory_size);
        memory_manager.memory_size = 0;
    }



}
size_t heap_get_largest_used_block_size(void) {
    if(memory_manager.memory_start == NULL) return 0;
    if(memory_manager.first_memory_chunk == NULL) return 0;
    if(heap_validate() != 0) return 0;

    int size = 0;

    for(memory_chunk_t* temp = memory_manager.first_memory_chunk; temp != NULL; temp = temp->next){
        if(temp->size > size && temp->free == 0) size = temp->size;
    }


    return size;
}
enum pointer_type_t get_pointer_type(const void* const pointer) {

    if(pointer == NULL) return pointer_null;

    if(heap_validate() != 0) return pointer_heap_corrupted;

    for(memory_chunk_t* temp = memory_manager.first_memory_chunk; temp != NULL; temp = temp->next){
        int idx = 0;
        uint8_t* temp_casted = (uint8_t*)temp;
        uint8_t* pointer_casted = (uint8_t*)pointer;
        for(unsigned int i = 0; i < sizeof(memory_chunk_t); ++i, ++idx)
        { //control structure
            if(temp_casted + idx == pointer_casted) return pointer_control_block;
        }
        if(temp->free == 0){
            for(unsigned int i = 0; i < PLOTEK_LENGTH; ++i, ++idx)
            { //first fence
                if(temp_casted + idx == pointer_casted) return pointer_inside_fences;
            }

            if(temp_casted + idx == pointer_casted) return pointer_valid;

            for(unsigned int i = 0; i < temp->size; ++i, ++idx){
                if(temp_casted + idx == pointer_casted) return pointer_inside_data_block;
            }

            for(int i = 0; i < PLOTEK_LENGTH; ++i, ++idx)
            { //second fence
                if(temp_casted + idx == pointer_casted) return pointer_inside_fences;
            }
        }

    }

    return pointer_unallocated;
}
int heap_validate(void){

    if( memory_manager.memory_start == NULL ) return 2;

    if( memory_manager.first_memory_chunk == NULL )
    {
        if(memory_manager.memory_size != 0) return 3;
        else return 0;
    }

    for(memory_chunk_t* temp = memory_manager.first_memory_chunk; temp != NULL; temp = temp->next){
        if(temp->checksum != calculate_checksum(temp)) return 3;
    }

    for(memory_chunk_t* temp = memory_manager.first_memory_chunk; temp != NULL; temp = temp->next){
        uint8_t* casted = (uint8_t*)temp + sizeof(memory_chunk_t);

        for(int i = 0; i < PLOTEK_LENGTH; ++i){
            if ((temp->free != 1) && (*(casted + i) != '#' || *(casted + PLOTEK_LENGTH + i + temp->size) != '#')) return 1;
        }
    }

    return 0;
}
void* heap_malloc_aligned(size_t size) {
    if(size <= 0) return NULL;
    if(heap_validate() != 0) return NULL;
    struct memory_chunk_t* temp = memory_manager.first_memory_chunk;
    while (temp != NULL && (temp->size - 2 * PLOTEK_LENGTH < (long long)size || temp->free != 1 || (((intptr_t)((uint8_t*)temp + sizeof(memory_chunk_t) + PLOTEK_LENGTH) & (intptr_t)(4096 - 1)) != 0)))temp = temp->next;

    //jeśli nie znalazles wystarczajaco duzego bloku
    if (temp == NULL)
    {
        memory_chunk_t* temp2 = custom_sbrk(size + sizeof(memory_chunk_t) + 2*PLOTEK_LENGTH);

        //jeśli brak miejsca na stercie to zwróć null
        if( temp2 == (void*)-1) return NULL;

        else{
            int aligning = ((((intptr_t)((uint8_t*)temp2 + sizeof(memory_chunk_t) + PLOTEK_LENGTH) + 4096 - 1) & ~(4096 - 1)) - (intptr_t)((uint8_t*)temp2 + sizeof(memory_chunk_t) + PLOTEK_LENGTH));
            if(aligning < (int)sizeof(memory_chunk_t) + PLOTEK_LENGTH) aligning += 4096;
            if(custom_sbrk(aligning) == (void*)-1) {
                custom_sbrk(-(size + sizeof(memory_chunk_t) + 2*PLOTEK_LENGTH));
                return NULL;
            }

            //wystarczająco miejsca na stercie
            memory_manager.memory_size += (size + sizeof(memory_chunk_t) + 2*PLOTEK_LENGTH + aligning);

            if(memory_manager.first_memory_chunk == NULL){
                memory_chunk_t a = {NULL, NULL, size, 0, 0};
                a.checksum = calculate_checksum(&a);
                memory_manager.first_memory_chunk = (memory_chunk_t*)((uint8_t*)temp2 + aligning);
                *(memory_manager.first_memory_chunk) = a;
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(memory_chunk_t) + i) = '#';
                    *(char*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size) = '#';
                }
                void* to_be_returned = (void*)((uint8_t*)memory_manager.first_memory_chunk + sizeof(struct memory_chunk_t) + PLOTEK_LENGTH);
                return to_be_returned;

            } else {
                memory_chunk_t* last = memory_manager.first_memory_chunk;
                while(last->next != NULL)last = last->next;
                last->next = (memory_chunk_t*)((uint8_t*)temp2 + aligning);
                last->checksum = calculate_checksum(last);
                memory_chunk_t a = {last, NULL, size, 0, 0};
                a.checksum = calculate_checksum(&a);
                *(struct memory_chunk_t*)(last->next) = a;
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)last->next + sizeof(memory_chunk_t) + i) = '#';
                    *(char*)((uint8_t*)last->next + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size) = '#';
                }
                return (void*)((uint8_t*)(last->next) + sizeof(struct memory_chunk_t) + PLOTEK_LENGTH);
            }
        }
    }

    else{
        //found free block of big enough size
        temp->free = 0;
        temp->size = size;

        for(int i = 0; i < PLOTEK_LENGTH; i++){
            *(char*)((uint8_t*)temp + sizeof(memory_chunk_t) + i) = '#';
            *(char*)((uint8_t*)temp + sizeof(memory_chunk_t) + PLOTEK_LENGTH + i + size) = '#';
        }

        temp->checksum = calculate_checksum(temp);
//        printf(" - Wsadzone w istniejący blok");
        return (void*)((uint8_t*)temp + sizeof(memory_chunk_t) + PLOTEK_LENGTH);
    }
}
void* heap_calloc_aligned(size_t number, size_t size) {
    long long int size_calloced = number * size;
    memory_chunk_t* chunk = heap_malloc_aligned(size_calloced);
    if(chunk == NULL) return NULL;
    for(int i = 0; i < size_calloced; i++){
        *((uint8_t*)chunk + i) = 0;
    }
    return chunk;
}
void* heap_realloc_aligned(void* memblock, size_t count) {
    if(heap_validate() != 0) return NULL;
    if(memblock == NULL && count == 0) return NULL;
    if(memblock == NULL) {
        return heap_malloc_aligned(count);
    }
    if(get_pointer_type(memblock) != pointer_valid) return NULL;
    if(memblock != NULL && count == 0) {
        heap_free(memblock); return NULL;
    }

    memory_chunk_t* chunk = (memory_chunk_t*) ((uint8_t*)memblock - PLOTEK_LENGTH - sizeof(memory_chunk_t));

    if(chunk->size == (long long)count) {/*printf(" - (7) Blok zajal tyle samo miejsca");*/ return memblock; } //bloki rowne

    else if(chunk->size > (long long)count){ //pomniejszamy blok

        for(int i = 0; i < PLOTEK_LENGTH; i++) {
            *(char*)((uint8_t*)memblock + count + i) = '#';
        }

        if(chunk->next == NULL){
            custom_sbrk(-(chunk->size - count));
            memory_manager.memory_size -= (chunk->size - count);
        }

        chunk->size = count;
        chunk->checksum = calculate_checksum(chunk);
//        printf(" - (6) Blok pomniejszony ");
        return memblock;
    }

    else { //powiekszamy blok
        if(chunk->next == NULL){
            if(custom_sbrk(count - chunk->size) == (void *) -1) return NULL;
            memory_manager.memory_size += count - chunk->size;
            chunk->size = count;
            chunk->checksum = calculate_checksum(chunk);

            for(int i = 0; i < PLOTEK_LENGTH; i++){
                *(char*)((uint8_t*)memblock + count + i) = '#';
            }
//            printf(" - (5) Blok powiększony (nastepny NULL)");
            return memblock;
        }

        else if(chunk->next->free == 0){ //Nastepny blok jest zajety
            // [XXXX##xxxx##....Uuuuu]
            unsigned long long free_space_after_chunk = ((uint8_t*)chunk->next) -
                                                        ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH);
            if(free_space_after_chunk >= count - chunk->size){
                chunk->size = count;
                chunk->checksum = calculate_checksum(chunk);
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)memblock + count + i) = '#';
                }
//                printf(" - (4) Nastepuje przesuniecie w przestrzen wolną przed blokiem zajętym");
                return memblock;
            }
        }
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        else if (chunk->next->free == 1){
            //[XXXX##xxxx##....FFFFffffffffffffUUUU##uuuu##]

            for(uint8_t* ptr = (uint8_t *)chunk->next + sizeof(memory_chunk_t) + PLOTEK_LENGTH + 1; ptr <= (uint8_t*)chunk->next->next - sizeof(memory_chunk_t) - PLOTEK_LENGTH; ++ptr){
                if(((intptr_t)ptr & (intptr_t)(4096 - 1)) == 0){
                    if(ptr - sizeof(memory_chunk_t) - PLOTEK_LENGTH - ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH) >= (long)count - chunk->size){
                        int move_F_by = ptr - sizeof(memory_chunk_t) - PLOTEK_LENGTH - (uint8_t*)chunk->next;
                        chunk->next->size -= move_F_by;
                        chunk->next->checksum = calculate_checksum(chunk->next);
                        chunk->next = (struct memory_chunk_t*)memmove((uint8_t *)chunk->next + move_F_by,chunk->next, sizeof(memory_chunk_t));
                        chunk->next->next->prev = chunk->next;
                        chunk->next->next->checksum = calculate_checksum(chunk->next->next);
                        chunk->size = count;
                        chunk->checksum = calculate_checksum(chunk);
                        for(int i = 0; i < PLOTEK_LENGTH; i++){
                            *(char*)((uint8_t*)memblock + count + i) = '#';
                        }
//                        printf(" - (3) Blok powiększony kosztem następnego bloku");
                        return memblock;
                    }
                }
            }

            if((uint8_t*)chunk->next->next - ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH) >= (long)count - chunk->size){
                chunk->next = chunk->next->next;
                chunk->next->prev = chunk;
                chunk->next->checksum = calculate_checksum(chunk->next);
                chunk->size = count;
                chunk->checksum = calculate_checksum(chunk);
                for(int i = 0; i < PLOTEK_LENGTH; i++){
                    *(char*)((uint8_t*)memblock + count + i) = '#';
                }
//                printf(" - (2) Blok powiększony z usunięciem następnego wolnego");
                return memblock;
            }
//            unsigned long long free_space_after_chunk = (uint8_t*)(chunk->next->next) - sizeof(struct memory_chunk_t) - ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH);
//
//            if(free_space_after_chunk >= count - chunk->size){
//                int move_F_by = count - chunk->size - (((uint8_t*)chunk->next) - ((uint8_t*)memblock + chunk->size + PLOTEK_LENGTH));
//                chunk->next->size -= move_F_by;
//                chunk->next->checksum = calculate_checksum(chunk->next);
//                chunk->next = (struct memory_chunk_t*)memmove((uint8_t *)chunk->next + move_F_by,chunk->next, sizeof(memory_chunk_t));
//                chunk->next->next->prev = chunk->next;
//                chunk->next->next->checksum = calculate_checksum(chunk->next->next);
//                chunk->size = count;
//                chunk->checksum = calculate_checksum(chunk);
//                for(int i = 0; i < PLOTEK_LENGTH; i++){
//                    *(char*)((uint8_t*)memblock + count + i) = '#';
//                }
//                printf(" - (2) Przesuniecie w glab nastepnego bloku");
//                return memblock;
//            }
        }

        // przenosimy blok
        void* temp = heap_malloc_aligned(count);
        if(temp == NULL) return NULL;

        memcpy(temp,memblock,((memory_chunk_t*)((uint8_t*)memblock - PLOTEK_LENGTH - sizeof(memory_chunk_t)))->size);
        heap_free(memblock);
//        printf(" - (1) Blok przesuniety na koniec sterty");
        return temp;
    }
}
