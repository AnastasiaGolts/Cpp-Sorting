#include <iostream>

void merge (int* arr1, int* arr2, int amount1, int amount2, int* arrFin, int amountFin);

void mergeSort (int* arr, int amount) {
    
    if (amount == 1) {
        
        return;
    }
    
    int ind = amount / 2; // точка деления массива
    
    mergeSort(arr, ind);
    mergeSort(arr+ind, amount-ind); // arr+ind –– сдвиг указателя на ind значений вперед
    
    int* finArray = new int [amount];
    
    merge(arr, arr+ind, ind, amount-ind, finArray, amount);
    
    for (int i = 0; i < amount; i++) {
        
        arr[i] = finArray[i];
    }
}

void merge (int* arr1, int* arr2, int amount1, int amount2, int* arrFin, int amountFin) {
    
    int i = 0; // индекс первого массива
    int y = 0; // индекс второго массива
    int x = 0; // индекс итогового массива
    
    for (int z = 0; z < amountFin; z++) {
        
        if (i == amount1) {
            
            arrFin[x] = arr2[y];
            x++;
            y++;
        } else if (y == amount2) {
            
            arrFin[x] = arr1[i];
            x++;
            i++;
        } else { if (arr1[i] < arr2[y]) {
            
            arrFin[x] = arr1[i];
            x++;
            i++;
        } else {
            
            arrFin[x] = arr2[y];
            x++;
            y++;
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
    
    mergeSort(array, a);
    
    for (int i = 0; i < a; i++) {
        
        std::cout << array[i] << "\n";
    }
    
    return 0;
}

