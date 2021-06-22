#include <iostream>

// Bubble sort

void bubbleSort (int* arr, int amount) {
    
    // Перебор всех возможных пар
    
    for (int i = 0; i < amount; i++) {
        
        for (int y = 0; y < amount; y++) {
            
            if (arr[i] < arr[y]) {
                
                int temp = arr[i];
                arr[i] = arr[y];
                arr[y] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
 
    int a = 0;
    std::cin >> a;
    
    int* array = new int [a];
    
    for (int i = 0; i < a; i++) {
        
        std::cin >> array[i];
    }
    
    bubbleSort(array, a);
    
    for (int i = 0; i < a; i++) {
        
        std::cout << array[i] << "\n";
    }
    
    return 0;
}
