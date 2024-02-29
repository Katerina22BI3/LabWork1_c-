#include <iostream>
#include <cstdlib> 
#include <vector>

//создание динамического массива
int* createDynamicArray(int size) {
    int* array = new int[size];
    return array;
}


//рандом заполнение динамического массива
void RandArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i != size; i++) {
        arr[i] = 1 + rand() % 100;
    }
}

//Quick Sort
//разброс элементов, меньших pivot влево, больших - вправо
int part(int arr[], int low, int high)
{
    int pivot = arr[high]; //pivot элемент - крайний элемент в массиве 
    int i = low; //фиксируем индекс первого элемента 
    int j = low;
    while (i <= high)
    {
        if (arr[i] > pivot) {
            i++;
        }
        else {
            std::swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
    return (j - 1);
}

//выбор рандомного pivot элемента из массива и обмен его с последним элементоимв массиве
int part_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    std::swap(arr[random], arr[high]);

    return part(arr, low, high);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = part_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Buble Sort
template<typename T>
void BubbleSort(std::vector<T>& arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Counting Sort
template <typename T>
void countingSort(std::vector<T>& arr, int size) {
    T maxElement = *std::max_element(arr.begin(), arr.end()); //нахождение максимального элемента массива
    std::vector<T> count(maxElement + 1, 0); //создание массива-счётчика
    std::vector<T> output(size); //создание массива для вывода

    for (int i = 0; i < size; i++) { //цикл для заполнения массива-счётчика, где будет количество раз повторился определённый индекс
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxElement; i++) { //цикл для изменения массива-счётчика 
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) { //заполнение выходного массива
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++) { //замена исходного массива отсортированным
        arr[i] = output[i];
    }
}

 //рандом заполнение вектора
 std::vector<int> RandVector(int size) {
     std::vector<int> randVec;
     srand(time(NULL));
     for (int i = 0; i < size; ++i) {
         randVec.push_back(rand()%100);
     }
     return randVec;
 }

//печать массива/вектора на экран
template <typename T>
void printArray(T arr, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() 
{
    //введение размера массива с клавиатуры и создание динамического массива
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    /* //WORK WITH ARRAY AND QUICK SORT WITH ARRAY
    //создание и заполнение массива
    int * array = createDynamicArray(size);
    RandArray(array, size);
   
    //вывод сгенерированного массива
    std::cout << "Random array: " << std::endl;
    printArray(array, size);
    std::cout << std::endl;
    
    //вывод отсортированного массива сортировкой QuickSort
    quickSort(array, 0, size - 1);
    std::cout << "Quick_Sorted array: " << std::endl;
    printArray(array, size);
    std::cout << std::endl;

    delete[] array;
    */

    //--------далее работа с векторами -------

    //генерация случайного вектора
    std::vector<int> vec = RandVector(size);

    //вывод сгенерированного вектора
    std::cout << "Random vector: " << std::endl;
    printArray(vec, size);
    std::cout << std::endl;

    /*
    //вывод отсортированного вектора сортировкой BubleSort
    BubbleSort(vec, size);
    std::cout << "Buble_Sorted array: " << std::endl;
    printArray(vec, size);
    */

    //вывод отсортированного вектора сортировкой CountingSort
    countingSort(vec, size);
    std::cout << "Counting_sorted array: " << std::endl;
    printArray(vec, size);
    
	return 0;
}
