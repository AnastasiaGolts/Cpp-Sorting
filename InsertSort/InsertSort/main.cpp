#include <iostream>

// Поиск индекса минимального элемента в неотсортированной части массива
// i - граница, от которой мы начинаем поиск минимального элемента, все, что до нее –– уже отсортировано

int minIndex (int* arr, int amount, int i) {
    
    int indexOfNumber = i;
    
    for (int y = i+1; y < amount; y++) {
        
        if (arr[y] < arr[indexOfNumber]) {
            
            indexOfNumber = y;
        }
    }
    
    return indexOfNumber;
}

void insertSort (int* arr, int amount) {
    
    for (int i = 0; i < amount; i++) {
        
        int a = minIndex(arr, amount, i);
        
        int temp = arr[a];
        arr[a] = arr[i];
        arr[i] = temp;
    }
}

int main(int argc, const char * argv[]) {
 
    int a = 0;
    std::cin >> a;
    
    int* array = new int [a];
    
    for (int i = 0; i < a; i++) {
        
        std::cin >> array[i];
    }
    
    insertSort(array, a);
    
    for (int i = 0; i < a; i++) {
        
        std::cout << array[i] << "\n";
    }
    
    return 0;
}
