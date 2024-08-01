#include <stdio.h>
#include <stdlib.h>

struct my_array
{
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct my_array *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *) malloc(tSize * sizeof(int));
}

void show(struct my_array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void set_val (struct my_array *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter an element %d: ", i);
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

int main ()
{
    struct my_array marks;
    create_array(&marks, 10, 2);
    set_val(&marks);
    show(&marks);
    return 0;
}

// The code below is what I practiced: 

// void creates_arr (struct my_array *a, int t_size, int u_size)
// {
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *) malloc(tSize * sizeof(int));

    // The above code can written as:

//     a->total_size = t_size;
//     a->used_size = u_size;
//     a->ptr = (int *)malloc(t_size * sizeof(int));  
// }

// void call_struct (struct my_array *a)
// {
//     for (int i = 0; i < a->used_size; i++)
//     {
//         printf("%d\n", (a->ptr)[i]);
//     }
// }

// void setting_values (struct my_array *a)
// {
//     for (int i = 0; i < a->used_size; i++)
//     {
//         printf("Set a value for element %d :", i);
//         scanf("%d", (a->ptr)[i]);
//     }
// }