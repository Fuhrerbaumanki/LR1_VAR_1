#include "../StaticLib/sort.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> array;
  int n = rand_int(5, 25);

  // Заполнение вектора с использованием push_back()
  for (int i = 0; i < n; i++)
    array.push_back(rand_int(-1000, 1000));

  std::cout << "Исходный массив: " << std::endl;
  for (auto const i : array)
    std::cout << i << " ";

  bubbleSort(array);

  std::cout << "\nОтсортированный массив: " << std::endl;
  for (const auto i : array)
    std::cout << i << " ";

  return 0;
}
