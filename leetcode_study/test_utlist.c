#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utlist.h"

#define     BUFLEN  20;

typedef struct element_strcut element_t;
struct element_strcut
{
    char*       name;
    element_t   *prev;
    element_t   *next;
};

struct element_list_struct
{
    element_t* head;
    int        count;
};


#define     BUFLEN  20
typedef struct el {
    char    bname[BUFLEN];
    struct  el* next, * prev;
} el;

int namecmp(el* a, el* b) {
    return strcmp(a->bname, b->bname);
}

el* head = NULL; /* important- initialize to NULL! */


void
test()
{
    el* name, * elt, * tmp, etmp;

    char    linebuf[BUFLEN];
    int     count;
    FILE*   file;
    if((file = fopen("test11.dat", "r")) == NULL) {
        perror("can't open: ");
        exit(-1);
    }

    while(fgets(linebuf, BUFLEN, file) != NULL) {
        if((name = (el*)malloc(sizeof * name)) == NULL) exit(-1);
        strcpy(name->bname, linebuf);
        DL_APPEND(head, name);
    }
    //???ĺ???ָ??
    DL_SORT(head, namecmp);

    DL_FOREACH(head, elt) printf("%s", elt->bname);
    DL_COUNT(head, elt, count);
    printf("%d number of elements in list\n", count);

    memcpy(&etmp.bname, "WES\n", 5);
    DL_SEARCH(head, elt, &etmp, namecmp);
    if(elt) printf("found %s\n", elt->bname);

    /* now delete each element, use the safe iterator */
    DL_FOREACH_SAFE(head, elt, tmp) {
        DL_DELETE(head, elt);
        free(elt);
    }
    fclose(file);

    return 0;
}