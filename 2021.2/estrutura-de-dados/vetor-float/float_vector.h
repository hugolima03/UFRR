typedef struct
{
  int capacity; // n máximo de elementos
  int size;     //     qtd de elementos armazenados
  float *data;
} FloatVector;

FloatVector* create(int capacity);
void destroy(FloatVector** vec_ref);
int size(FloatVector* vec);
int capacity(FloatVector* vec);
float get(FloatVector* vec, int index);
void append(FloatVector* vec, float val);
void set(FloatVector* vec, int index, float val);
void print(FloatVector* vec);
void remove_element(FloatVector* vec, int index);
FloatVector* copy(FloatVector* vec);