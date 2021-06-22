#include <iostream>

// поиск точки деления массива

int split (int* arr, int amount) {
    
    int k = arr[0];
    
    int indStart = 0;
    int indFin = amount - 1;
    
    while (indStart < indFin) {
        
        while (arr[indStart] < k && indStart < indFin) {
      
            indStart++;
        }
        
        while (arr[indFin] >= k && indStart < indFin) {
            
            indFin--;
        }
        
        if (indStart < indFin) {
            
            int temp = arr[indStart];
            arr[indStart] = arr[indFin];
            arr[indFin] = temp;
        }
    }
    
    if (indStart == 0) { // это значит, что выбранный k и есть минимальный элемент этого массива, и таким образом (прибавляя к его индексу 1) мы его отделяем в отдельный отсортированный массив из одного элемента
        
        return indStart+1; // или return 1;
    }
    
    return indStart;
}

// собственно сортировка

void quickSort (int* arr, int amount) {
    
    if (amount == 1) {
        
        return;
    }
    
    int ind = split(arr, amount);
    
    quickSort(arr, ind);
    quickSort(arr + ind, amount - ind);
    
    
}


int main(int argc, const char * argv[]) {
    
    int a = 0;
    std::cin >> a;
    
    int* array = new int [a];
    for (int i = 0; i < a; i++) {
        
        std::cin >> array[i];
    }
    
    quickSort(array, a);
    
    for (int i = 0; i < a; i++) {
        
        std::cout << array[i] << "\n";
    }

    return 0;
}
