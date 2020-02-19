# Radix Sort
#####Задача: 
Реализовать алгоритм поразрядной сортировки (radix sort).

#####Входные данные:
 количество 16ричных чисел, далее в каждой следующей строке по одному такому числу.

#####Результат: 
необходимо вывести подробный лог работы алгоритма (см. пример).

#####Комментарии:
 никакие строки в данном логе не заканчиваются пробелами, но есть пустые строки между этапами сортировки

####Sample Input:

6
1DA
FFFFFFFF
24
100000B
5
17
####Sample Output:

Sorting by 7 digit:
24
5
17
1DA
100000B
FFFFFFFF

Sorting by 6 digit:
5
100000B
17
24
1DA
FFFFFFFF

Sorting by 5 digit:
5
17
24
100000B
1DA
FFFFFFFF

Sorting by 4 digit:
5
17
24
1DA
100000B
FFFFFFFF

Sorting by 3 digit:
5
17
24
1DA
100000B
FFFFFFFF

Sorting by 2 digit:
5
17
24
1DA
100000B
FFFFFFFF

Sorting by 1 digit:
5
17
24
1DA
100000B
FFFFFFFF

Sorting by 0 digit:
5
17
24
1DA
100000B
FFFFFFFF