#include "../../virtual_alloc.h"

#define MEMORY_CAPACITY 9000000
char global_mem[MEMORY_CAPACITY] = {0};
void * virtual_heap =  &global_mem;
void * virtual_break = &global_mem;
void * virtual_sbrk(int32_t increment) {
    void* ret_address = virtual_break;
    virtual_break += increment;
    return  ret_address;
}

int main() {
    // Your own testing code here
    init_allocator(virtual_heap, 14, 10);
    void* data1 =virtual_malloc(virtual_heap,7000);
    int status = virtual_free(virtual_heap,data1+1);
    printf("%d\n",status);
    return 0;
}
