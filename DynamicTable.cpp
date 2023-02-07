
#include "DynamicTable.h"

void DynamicTable::insert(int value, bool dummy_version) {

  if (last == size){
    if (dummy_version == true) {
        resize_dummy();
    }

    else {
        resize();
    }
  }
  table[last] = value;
  last++;
}

void DynamicTable::resize_dummy() {
    n_resize_called++;
    int* newDtable = new int [size*2];
    for (int i = 0; i < size; i++){
        newDtable[i] = table[i];
    }
    delete[] table;
    table = newDtable;
    size = size + 1;    
}

void DynamicTable::resize() {
    n_resize_called++;
    int* newDtable = new int[size*2];
    for (int i = 0; i < size; i++){
        newDtable[i] = table[i];
    }
    delete [] table;
    table = newDtable;
    size = size*2;
}
