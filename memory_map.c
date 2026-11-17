#include <stdio.h>
#include <stdlib.h>

int global_init = 42;
int global_uninit;

static int static_init = 84;
static int static_uninit;

const char *str_literal = "ELF Memory Map";

void sample_function(void)
{
    /* Function located in .text segment */
}

int main(void)
{
    int local_var = 100;
    int *heap_var = malloc(sizeof(int));

    if (heap_var == NULL) {
        return 1;
    }

    *heap_var = 200;

    printf("Code/function:           %p\n", (void *)sample_function);
    printf("String literal:          %p\n", (void *)str_literal);
    printf("Global initialized:      %p\n", (void *)&global_init);
    printf("Static initialized:      %p\n", (void *)&static_init);
    printf("Global uninitialized:    %p\n", (void *)&global_uninit);
    printf("Static uninitialized:    %p\n", (void *)&static_uninit);
    printf("Heap allocation:         %p\n", (void *)heap_var);
    printf("Stack/local:             %p\n", (void *)&local_var);

    free(heap_var);

    return 0;
}
