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
    init_allocator(virtual_heap, 16, 10);
    void* data1 =virtual_malloc(virtual_heap,1);
    void* data2 =virtual_malloc(virtual_heap,6000);
    void* data3 =virtual_malloc(virtual_heap,2000);
    virtual_info(virtual_heap); 
    return 0;
}
