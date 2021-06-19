# **Ex03** Исследование библиотечных методов сортировки С и С++



## Задача №1

```
    Изучить программу, измеряющую время работы функции qsort и алгоритма sort из стандартной библиотеки
```


### Текст программы

```cpp
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t LARGE_SIZE = 100000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp( const void* a, const void* b ) {
    return ( *( int* )a - *( int* )b );
}

int main() {
    int arr[LARGE_SIZE];
    int arr_copy[LARGE_SIZE];
    // Рандомизация по таймеру
    srand(time(nullptr));
    // генерируем случайные данные
    generate( arr, arr + LARGE_SIZE, rnd() );
    copy( arr, arr + LARGE_SIZE, arr_copy );
    // засекаем время
    time_t start = clock();
    // выполняем сортировку, используя функцию qsort
    qsort( arr, LARGE_SIZE, sizeof( int ), comp );
    cout << "C quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    // снова засекаем время
    start = clock();
    // выполняем сортировку, используя алгоритм С++
    sort( arr_copy, arr_copy + LARGE_SIZE );
    cout << "C++ quick-sort time elapsed: " << static_cast<double>( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}
```

Приведенная выше программа, замеряет время работы двух средств сортировки и выводит время для массива, заданного размера.

## Задача №2

```
Используя программу, приведенную в задании 1, выполнить не менее 50 измерений для массива разной длины и определить зависимость времени выполнения от размера массива
```

Необходимо построить графики функции для **qsort** и **sort**, используя накопленные данные и прокомментировать их. 



### Состав программы

Программа должна состоять из 3-х файлов:

- **task1.h** - заголовочный файл, содержащий заголовок **comp**
- **task1.cpp** - файл, содержащий реализацию функций
- **main1.cpp** - файл, содержащий **main**
- **results.png** - файл с графиками
- **results.txt** - файл с выводами


