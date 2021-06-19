#ifndef KPO_TASK2_H
#define KPO_TASK2_H

template<typename T>
T averageArr(T *arr, const unsigned int size) {
    T sum = 0;
  for (auto i = 0; i < size; ++i){
      sum += arr[i];
  }
    return sum/size;
}


#endif //KPO_TASK2_H
