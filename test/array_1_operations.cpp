#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array arr){
    int i;
    for (i = 0; i < arr.length; i++){
        printf("%i\n", arr.A[i]);
    }
}

void append(struct Array *arr, int item){
    arr -> A[arr -> length] = item;
    arr -> length++;
}

bool insert(struct Array *arr, int index, int item){
    // 0. 삽입할 자리 있는지, index 범위 맞는지 확인
    if (arr -> length == arr -> size || index < 0 || index > arr -> size - 1){
        return false;
    }

    // 1. 삽입할 곳 뒤에 위치한 아이템 한 칸씩 뒤로 이동
    for (int i = arr -> length; i > index; i--){
        arr -> A[i] = arr -> A[i - 1];
    }
    
    // 2. 삽입
    arr -> A[index] = item;
    
    // 3. length 업데이트  
    arr -> length++;
    return true;
}

int delete_item(struct Array *arr, int index){
    if (index < 0 || index > arr -> length - 1)
        return -1;
    
    // 0. 삭제할 아이템 따로 빼두기
    int deleted_item = arr -> A[index];

    // 1. 삭제할 곳 뒤에 위치한 아이템 한 칸씩 앞으로 이동
    for (int i = index; i < arr -> length - 1; i++){
        arr -> A[i] = arr -> A[i + 1];
    }

    // 2. length 업데이트
    arr -> length--;

    // 3. 삭제한 아이템 반환
    return deleted_item;
}

int linear_search(struct Array *arr, int item){
    for (int i = 0; i < arr -> length; i++){
        if (arr -> A[i] == item){
            return i;
        }
    }
    return -1;
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int transposition_search(struct Array *arr, int item){
    for (int i = 0; i < arr -> length; i++){
        if (arr -> A[i] == item){
            swap(&arr -> A[i], &arr -> A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

int move_front_search(struct Array *arr, int item){
    for (int i = 0; i < arr -> length; i++){
        if (arr -> A[i] == item){
            swap(&arr -> A[i], &arr -> A[0]);
            return 0;
        }
    }
    return -1;
}

int bin_search_loop(struct Array arr, int item){
    int lowest = 0;
    int highest = arr.length - 1;
    int middle;

    while(lowest <= highest){
        middle = (lowest + highest) / 2;
        if (item == arr.A[middle]){
            return middle;
        }
        else if (item < arr.A[middle]){
            highest = middle - 1;
        }
        else {
            lowest = middle + 1;
        }
    }
    return -1;
}

int bin_search_recursion(struct Array arr, int lowest, int highest, int item){
    int middle;
    if (lowest < highest){
        middle = (lowest + highest) / 2;
        if (item == arr.A[middle]){
            return middle;
        }
        else if (item < arr.A[middle]){
            return bin_search_recursion(arr, lowest, middle - 1, item);
        }
        else {
            return bin_search_recursion(arr, middle + 1, highest, item);
        }
    }
    return -1;
}

int get(struct Array arr, int index){
    if (index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void set(struct Array *arr, int index, int num){
    if (index >= 0 && index < arr -> length){
        arr -> A[index] = num;
    }
    printf("Index error");
}

int max(struct Array arr){
    int maxnumber = arr.A[0];
    for (int i = 1; i < arr.length; i++){
        if (arr.A[i] > maxnumber){
            maxnumber = arr.A[i];
        }
    }
    return maxnumber;
}

int sum_loop(struct Array arr){
    int sum = 0;
    for (int i = 0; i < arr.length; i++){
        sum += arr.A[i];
    }
    return sum;
}

int sum_recursion(struct Array arr, int last_index){
    if (last_index < 0){
        return 0;
    } else {
        return sum_recursion(arr, last_index - 1) + arr.A[last_index];
    }
}

int avg(struct Array arr){
    int sum = 0;
    for (int i = 0; i < arr.length; i++){
        sum += arr.A[i];
    }
    return sum / arr.length;
}

void reverseA(struct Array *arr){
    int *B;
    B = (int *)malloc(arr -> length * sizeof(int));

    for (int i = arr->length-1, j=0; i>=0; i--, j++){
        B[j] = arr -> A[i];
    }

    for (int i = 0; i < arr -> length; i++){
        arr -> A[i] = B[i];
    }
}

void reverseB(struct Array *arr){
    for (int i = 0, j = arr->length - 1; i < j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}

void left_rotate(struct Array *arr){
    int first = arr -> A[0];
    for (int i = 0; i < arr->length; i++){
        arr -> A[i] = arr -> A[i + 1];
    }
    arr -> A[arr -> length - 1] = first;
}

void right_rotate(struct Array *arr){
    int last = arr -> A[arr -> length - 1];
    for (int i = arr->length - 1; i >= 0; i--){
        arr -> A[i] = arr -> A[i - 1];
    }
    arr -> A[0] = last;
}

void sortInsert(struct Array *arr, int item){
    int i = arr -> length - 1;
    while(arr -> A[i] > item){
        arr -> A[i + 1] = arr -> A[i];
        i--;
    }
    arr -> A[i + 1] = item;
}

bool isSorted(struct Array arr){
    int len = arr.length;
    for(int i = 0; i < len - 1; i++){
       if (arr.A[i] > arr.A[i+1]){
           return false;
       } 
    }
    return true;
}

void sort(struct Array *arr){
    int i = 0;
    int j = arr -> length - 1;

    while (i < j){
        while (arr -> A[i] < 0){
            i++;
        }
        while (arr -> A[j] >= 0){
            j--;
        }
        if (i < j){
            swap(&arr->A[i], &arr->A[j]);
        }
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


int main(void){
   struct Array arr1;
   int ch;
   int x, index;
   printf("Enter size of Array");
   scanf("%d", &arr1.size);
   arr1.A = (int *)malloc(arr1.size * sizeof(int));
   arr1.length = 0;

   do {
    printf("\n\nMenu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("enter you choice ");
    scanf("%d",&ch);

    switch(ch){
       case 1: printf("Enter an element and index: ");
       scanf("%d %d", &x, &index);
       insert(&arr1, index, x);
       break;

       case 2: printf("Enter index: ");
       scanf("%d", &index);
       x = delete_item(&arr1, index);
       printf("Deleted element is %d", x);
       break;

       case 3: printf("Enter element to search: ");
       scanf("%d", &x);
       index = bin_search_loop(arr1, x);

       case 5: display(arr1);
    }
   } while (ch < 6);
   return 0;
}