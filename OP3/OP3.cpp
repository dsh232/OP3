#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>

int int_input() {   //проверка корректного ввода чисел
    int input;
    while (!(std::cin >> input) || std::cin.peek() != '\n') {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Некорректный ввод. Повторите снова. " << std::endl;
    }
    return input;
}       

char char_input()       //проверка корректного ввода символов
{
    char input;
    while (!(std::cin >> input) || std::cin.peek() != '\n')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Некорректный ввод. Повторите снова. " << std::endl;
    }
    return input;
}

void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void quickSort(std::vector<int>& arr, int leftIndex, int rightIndex) {
    int i, j, mid, pivot;
    i = leftIndex;
    j = rightIndex;
    mid = leftIndex + (rightIndex - leftIndex) / 2;
    pivot = arr[mid];

    while (i<rightIndex || j>leftIndex) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            swap(arr, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < rightIndex)
                quickSort(arr, i, rightIndex);
            if (j > leftIndex)
                quickSort(arr, leftIndex, j);
            return;
        }
    }
}



void printArray(const std::vector<int>& arr) {      //вывод массива
    int arr_size = arr.size();
    if (arr_size > 23) {    //в случае, если размер массива больше 23, то выводятся первые 10 и последние 10 элементов
        std::cout << "\nПервые 10 элементов: ";
        for (int i = 0; i < 10; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Последние 10 элементов: ";
        for (int i = arr_size - 10; i < arr_size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else {      //иначе просто вывод каждого элемента массива
        for (int i = 0; i < arr_size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

std::vector<int> createRandomArray(int n) {     //заполнение вектора случайными числами
    std::vector<int> newVector;
    for (int i = 0; i < n; i++) {
        newVector.push_back(rand() % 1000); // Генерация случайных чисел от 0 до 99
    }
    return newVector;
}


int main() {
    setlocale(LC_ALL, "ru");
    bool is_need_next_run = true; //создание флага для повторного запуска программы
    while (is_need_next_run) {
        int arr_size;
        do
        {
            std::cout << "Введите размер массива (Положительное число): ";
            arr_size = int_input();

        } while (arr_size <= 0);

        std::vector<int> sortArr; // Инициализация вектора для хранения данных
        sortArr = createRandomArray(arr_size); // Заполнение вектора

        // Выводим исходный массив
        std::cout << "Исходный массив: ";
        printArray(sortArr);

        quickSort(sortArr, 0, arr_size - 1);
        std::cout << "Отсортированный массив: ";
        printArray(sortArr);

        bool is_need_processed = false;  // создание флага продолжить/нет программу
        do {
            std::cout << "Хотите продолжить? (Y/N):  ";
            char answer = char_input();
            if (answer == 'N') {
                std::cout << "Пока!" << std::endl;
                is_need_next_run = false;
                is_need_processed = true;
            }
            else if (answer == 'Y') {
                std::cout << "Продолжить? конечно!" << std::endl;
                is_need_processed = true;
            }

        } while (!is_need_processed);
    }
}