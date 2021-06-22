#include <iostream>

// бинарный поиск в отсортированном массиве

int search (int* arr, int amount, int num) {
    
    if (amount == 0) {
        
        return 0;
    }
    
    if (amount == 1) {
        
        if (arr[0] < num) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int ind = amount / 2;
    
    if (arr[ind] < num) {
        
        return search(arr+ind, amount-ind, num);
    }
    
    if (arr[ind] > num) {
        
        return  search(arr, ind, num);
    }
    
    if (arr[ind] == num) {
        
        return ind;
    }
    
    return ind;
}

void insert (int* arr, int amount, int index, int num) {
    
    // сдвигаем массив для освобождения нужного индекса для вставки числа
    
    for (int i = amount-1; i >= index; i--) {
        
        arr[i+1] = arr[i];
    }
    
    // вставляем число
    
    arr[index] = num;
}

void selectSort (int* arr, int amount) {
    
    for (int i = 0; i < amount; i++) {
        
        int index = search(arr, i, arr[i]);
        
        insert(arr, i, index, arr[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    int a = 0;
    std::cin >> a;
    
    int* array = new int [a];
    
    for (int i = 0; i < a; i++) {
        
        std::cin >> array[i];
    }
    
    selectSort(array, a);
    
    for (int i = 0; i < a; i++) {
        
        std::cout << array[i] << "\n";
    }

    return 0;
}
