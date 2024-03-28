#ifndef SORT_H
#define SORT_H

#include <vector>

// Спецификация extern "C" для предотвращения искажения имен
extern "C" {

// Объявление функции сортировки пузырьком
void bubbleSort(std::vector<int> &arr);

// Объявление функции вывода массива
void printArray(int A[], int size);

// Объявление функции генерации псевдо случайного числа
int rand_int(int min, int max);

} // extern "C"

#endif // SORT_H
