#include <stdio.h>
#include <stdlib.h>

int missingElementFormula(int *arr, int length){
    int n = arr[length - 1];
    int formulaSum = (n * (n+1))/2;
    int arrSum = 0;
    for (int i = 0; i < length; i++){
        arrSum += arr[i];
    }
    return formulaSum - arrSum;
}

int missingElementFormula2(int *arr, int length){
    int diff = arr[0];
    int highest = arr[length - 1];
    int n = length;

    for (int i = 0; i < length; i++){
        if (arr[i] - i != diff){
            while(diff < arr[i] - i){
                printf("%d\n", i + diff);
                diff++;
            }
        }
    }

    return 0;
}

void missingSeveralElementFormula(int *arr, int length){
    int diff = arr[0];
    int highest = arr[length - 1];

    for (int i = 0; i < length; i++){
        if (arr[i] - i != diff){
            while(diff < arr[i] - i){
                printf("%i\n", i + diff);
                diff++;
            }
        }
    }
}

void missingElementHash(int *arr, int length, int l, int h){
    int H[length];
    for (int i = 0; i < length; i++){
        H[arr[i]] = 1;
    }
    for (int i = l; i <= h; i++){
        if (H[i] == 0){
            printf("%i\n", i);
        }
    }
}

void findDuplicates(int *arr, int length){
    int lastDuplicate = 0;
    for (int i = 0; i < length; i++){
        if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate){
            lastDuplicate = arr[i];
            printf("%i\n", lastDuplicate);
        }
    }
}

void findDuplicateNumber(int *arr, int length){
    for (int i = 0; i < length - 1; i++){
        if (arr[i] == arr[i + 1]){
            int j = i + 1;
            while(arr[j] == arr[i]){
                j++;
            }
            printf("%d is appearing %d times\n", arr[i], j-i);
            i = j - 1;
        }
    }
}

void findDuplicateHash(int *arr, int length){
    int l = arr[0];
    int h = arr[length - 1];
    // 변수로 배열 생성 안됨
    int H[21] = {};
    for (int i = 0; i < length; i++){
        int index = arr[i];
        H[index] += 1;
    }
    for (int i = l; i <= h; i++){
        if (H[i] > 1){
            printf("%i is appearing %i times\n", i, H[i]);
        }
    }
}

void countDuplicateUnsorted(int *arr, int length){
    for (int i = 0; i < length - 1; i++){
        int count = 1;
        if (arr[i] != -1){
            for (int j = i + 1; j < length; j++){
                if (arr[i] == arr[j]){
                    count++;
                    arr[j] = -1;
                }
            }
            if (count > 1){
                printf("%i is appearing %i times\n", arr[i], count);
            }
        }
    } 
}

void findDuplicateHashUnsorted(int *arr, int length){
    // 변수로 배열 생성 안됨
    int H[21] = {};
    for (int i = 0; i < length; i++){
        int index = arr[i];
        H[index] += 1;
    }
    for (int i = 0; i < 21; i++){
        if (H[i] > 1){
            printf("%i is appearing %i times\n", i, H[i]);
        }
    }
}

void findpairsUnsorted(int *arr, int length, int k){
    int H[16] = {};
    for (int i = 0; i < length; i++){
        int numToFind = k - arr[i];
        if (H[numToFind] == 1){
            printf("%i, %i\n", arr[i], numToFind);
        }
        H[arr[i]] = 1; 
    }
}

void findpairsSorted(int *arr, int length, int k){
    // j 먼저 decrement, i는 페어 찾았을 때만 increment
    int i = 0;
    int j = length - 1;
    while(i < j){
        int numToFind = k - arr[i];
        if (arr[j] == numToFind){
            printf("%i, %i\n", arr[i], arr[j]);
            i++;
            j--;
        }
        else {
            if (numToFind < arr[j]){
                j--;
            }
            else {
                i++;
            }
        }
    }
}

void findMinMax(int *arr, int length){
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < length; i++){
        if (arr[i] < min){
            min = arr[i];
        } else if (max < arr[i]){
            max = arr[i];
        }
    }

    printf("%i\n", min);
    printf("%i\n", max);
}

int main(){
    int A[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int length = 10;
    findMinMax(A, length);

}