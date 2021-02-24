#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct link
{
    char *buf;
    struct link *next;
};

struct link *dup_list(const struct link *list)
{

    struct link *dup = NULL, *p = NULL, *prev;

    while (list != NULL)
    {
        p = (struct link*)malloc(sizeof(struct link));

        strcpy(p->buf, list->buf);
        
        if (!dup)
            dup = p;
        else
            prev->next = p;
        prev = p;
        list = list->next;
    }
    prev->next = NULL;

   
    return dup;

}

void free_list(struct link *list)
{
    struct link *tmp;

    while (list != NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void print_list(const struct link *list)
{
    while (list != NULL)
    {
        printf(" %s \n", list->buf);
        list = list->next;
    }
}

int main()
{

    struct link *l1, *l2, *l3;

    l1 = (struct link *)malloc(sizeof(struct link));
    l2 = (struct link *)malloc(sizeof(struct link));
    l3 = (struct link *)malloc(sizeof(struct link));

    l1->buf = strdup("Ottawa, Ontario");
    l2->buf = strdup("Ontario, Canada");
    l3->buf = strdup("Canada, North America");

    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;

    print_list(l1);

    struct link *dup = dup_list(l1);

    printf("Content of the original list:");
    print_list(l1);

    printf("content of the duplicated list:");
    print_list(dup);

    //free_list(dup);
    //free_list(l1);

    return 0;
}
