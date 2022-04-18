#include <iostream>

using namespace std;
class Array{
    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);
    public:
        Array(){
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz){
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array(){
            delete [ ]A;
        }
        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int Delete(int index);
        int LinearSearch(int key);
        int BinarySearch(int key);
        int Get(int index);
        void Set(int index, int x);
        void Reverse();
        void SortInsert(int x);
        void SortPlusMinus();
        bool IsSorted();
        Array* Merge(Array a);
        Array* Union(Array a);
        Array* Intersection(Array a);
        Array* Difference(Array a);
};

void Array::Display(){
    for (int i = 0; i < length; i++){
        cout << A[i] << endl;
    }
}

void Array::Append(int x){
    if (length >= size){
        cout << "Not enough space" << endl;
    }
    A[length++] = x;
}

void Array::Insert(int index, int x){
    if (index >= 0 && index <= length){
        for (int i = length - 1; i >= index; i--){
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
    else {
        cout << "Invalid index" << endl;
    }
}

int Array::Delete(int index){
    int deleted_item = -1;
    if (index >= 0 && index < length){
        deleted_item = A[index];
        for (int i = index; i < length - 1; i++){
            A[i] = A[i + 1];
        }
        length--;
    }
    return -1;
}

int Array::LinearSearch(int key){
    for (int i = 0; i < length; i++){
        if (A[i] == key){
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key){
    int l = 0;
    int h = length - 1;
    int m;

    while (l <= h){
        int m = (l + h) / 2;
        if (A[m] == key){
            return m;
        }
        else if (A[m] < key){
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
    return -1;
}

int Array::Get(int index){
    if (index >= 0 && index < length){
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x){
    if (index >= 0 && index < length){
        A[index] = x;
    }
    else {
        cout << "Invalid index" << endl;
    }
}

void Array::swap(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void Array::Reverse(){
    for (int i = 0, j = length - 1; i < j; i++, j--){
        swap(&A[i], &A[j]);
    }
}

void Array::SortInsert(int x){
    int i = length - 1;
    if (length == size){
        cout << "Array is full. Cannot insert a new item." << endl;
        return;
    }
    while (A[i] > x){
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

void Array::SortPlusMinus(){
    int i, j;
    i = 0; 
    j = length - 1;

    while (i < j){
        while(A[i] < 0){
            i++;
        }
        while(A[j]>=0){
            j--;
        }
        if (i < j){
            swap(&A[i], &A[j]);
        }
    }
}

bool Array::IsSorted(){
    for (int i = 0; i < length - 1; i++){
        if (A[i] > A[i + 1]){
            return false;
        }
    }
    return true;
}


int main(){
    Array *arr;
    arr = new Array(10);
    arr->Append(1);
    arr->Append(2);
    arr->Append(3);
    arr->Append(6);
    arr->Display();
    
    Array *arrToMerge;
    arrToMerge = new Array(10);
    arr->Append(4);
    arr->Append(5);
    arr->Append(100);
    arr->Merge(*arrToMerge);
    return 0;
}