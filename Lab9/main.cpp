#include <stdio.h>
#include "Map.h"

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    

    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    
    m[20] = "result";
    

    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }


    printf("\n--- Testare Metode Suplimentare ---\n");
    
  
    m.Set(40, "NewValue");
    printf("Dupa Set(40), numărul de elemente este: %d\n", m.Count());

   
    const char* valOutput;
    if (m.Get(40, valOutput)) {
        printf("Get(40) a reusit! Valoarea este: %s\n", valOutput);
    }

  
    m.Delete(10);
    printf("Dupa Delete(10), noul numar de elemente este: %d\n", m.Count());


    Map<int, const char *> m2;
    m2[20] = "altceva";
    m2[30] = "Poo";

    if (m.Includes(m2)) {
        printf("Map m include toate cheile din m2!\n");
    } else {
        printf("Map m NU include toate cheile din m2!\n");
    }

   
    m.Clear();
    printf("Dupa Clear(), numarul de elemente este: %d\n", m.Count());

    return 0;
}
