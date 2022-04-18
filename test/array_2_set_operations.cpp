#include <stdio.h>
#include <stdlib.h>

struct Array {
 int A[10];
 int size;
 int length;
};

void display(struct Array arr){
    int i;
    for (i = 0; i < arr.length; i++){
        printf("%i\n", arr.A[i]);
    }
}

struct Array* merge(struct Array *a, struct Array *b){

    int i, j, k;
    i = j = k = 0;

    struct Array *c = (struct Array *)malloc(sizeof(struct Array));

    while(i < a->length && j < b->length){
        if (a->A[i] < b->A[j]){
            c->A[k++] = a->A[i++];
        } else {
            c->A[k++] = b->A[j++];
        }
    }
    for (;i < a->length; i++){
        c->A[k++] = a->A[i];
    }
    for (;j < b->length; j++){
        c->A[k++] = b->A[j];
    }
    c->length = a->length + b->length;
    c->size = 10;

    return c;
}

struct Array* Union(struct Array *a, struct Array *b){

    int i, j, k;
    i = j = k = 0;

    struct Array *c = (struct Array *)malloc(sizeof(struct Array));

    while(i < a->length && j < b->length){
        if (a->A[i] < b->A[j]){
            c->A[k++] = a->A[i++];
        } else if (b->A[j] < a->A[i]){
            c->A[k++] = b->A[j++];
        } else {
            c->A[k++] = a->A[i++];
            j++;
        }
    }
    for (;i < a->length; i++){
        c->A[k++] = a->A[i];
    }
    for (;j < b->length; j++){
        c->A[k++] = b->A[j];
    }
    c->length = k;
    c->size = 10;

    return c;
}

struct Array* Intersection(struct Array *a, struct Array *b){

    int i, j, k;
    i = j = k = 0;

    struct Array *c = (struct Array *)malloc(sizeof(struct Array));

    while(i < a->length && j < b->length){
        if (a->A[i] < b->A[j]){
            i++;
        } else if (b->A[j] < a->A[i]){
            j++;
        } else {
            c->A[k++] = a->A[i++];
            j++;
        }
    }
    c->length = k;
    c->size = 10;

    return c;
}

struct Array* Difference(struct Array *a, struct Array *b){

    int i, j, k;
    i = j = k = 0;

    struct Array *c = (struct Array *)malloc(sizeof(struct Array));

    while(i < a->length && j < b->length){
        if (a->A[i] < b->A[j]){
            c->A[k++] = a->A[i++];
        } else if (b->A[j] < a->A[i]){
            j++;
        } else {
            i++;
            j++;
        }
    }
    for (;i < a->length; i++){
        c->A[k++] = a->A[i];
    }
    c->length = k;
    c->size = 10;

    return c;
}


int main(){
 struct Array arr1={{2,9,21,28,35},10,5};
 struct Array arr2={{2,3,16,18,28},10,5};
 struct Array *arr3; 
arr3=Difference(&arr1,&arr2);
display(*arr3);

return 0;
}