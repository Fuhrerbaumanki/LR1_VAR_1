#include <dlfcn.h>
#include <iostream>
#include <vector>

typedef void (*BubbleSortFunction)(std::vector<int> &);
typedef int (*RandIntFunction)(int, int);

int main(int argc, char *argv[]) {
  void *handle = dlopen("../DynamicLib/libsort.so", RTLD_LAZY);
  if (!handle) {
    std::cerr << "Не удалось загрузить библиотеку: " << dlerror() << std::endl;
    return 1;
  }

  // Загрузка функций из библиотеки
  BubbleSortFunction bubbleSort =
      (BubbleSortFunction)dlsym(handle, "bubbleSort");
  RandIntFunction rand_int = (RandIntFunction)dlsym(handle, "rand_int");
  if (!bubbleSort || !rand_int) {
    std::cerr << "Не удалось найти функции: " << dlerror() << std::endl;
    dlclose(handle);
    return 1;
  }

  std::vector<int> array;
  int n = rand_int(5, 25);

  // Заполнение вектора с использованием push_back()
  for (int i = 0; i < n; i++)
    array.push_back(rand_int(-1000, 1000));

  std::cout << "Исходный массив: " << std::endl;
  for (auto const i : array)
    std::cout << i << " ";

  // Вызов функции сортировки из динамически загруженной библиотеки
  bubbleSort(array);

  std::cout << "\nОтсортированный массив: " << std::endl;
  for (const auto i : array)
    std::cout << i << " ";

  // Закрытие дескриптора библиотеки
  dlclose(handle);

  return 0;
}
