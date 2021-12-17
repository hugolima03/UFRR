#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  FloatVector *vec = create(10);

  append(vec, 4.6);
  append(vec, 22.4);
  append(vec, 8.5);

  print(vec);
  
  remove_element(vec, 1);
  // clear(vec);
  print(vec);


  FloatVector *CloneArray = copy(vec);
  print(CloneArray);

  return 0;
}