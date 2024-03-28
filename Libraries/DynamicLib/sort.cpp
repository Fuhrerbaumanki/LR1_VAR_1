#include <iostream>
#include <random>
#include <vector>

// Спецификация extern "C" для предотвращения искажения имен
extern "C" {

void bubbleSort(std::vector<int> &arr) {
  int n = arr.size();
  bool swapped;
  for (int i = 0; i < n - 1; ++i) {
    swapped = false;
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        // обмен значениями
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    // Если внутренний цикл не совершал обмена, значит массив уже отсортирован
    if (!swapped)
      break;
  }
}

// Функция вывода массива
void printArray(int A[], int size) {
  for (int i = 0; i < size; i++)
    std::cout << A[i] << " ";
  std::cout << std::endl;
}

// Функция генерации псевдо случайного числа
int rand_int(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(min, max);
  return dist(gen);
}

} // extern "C"
