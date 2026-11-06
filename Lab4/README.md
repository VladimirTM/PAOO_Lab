# Lucrarea de laborator 4 (Lab 4)

## Cerințe

Să se scrie un proiect C++ care să acopere principalele probleme descrise în următoarele item-uri din cartea **Effective C++**:

- **Item 4**: *Make sure that objects are initialized before they’re used.*
  - Inițializarea manuală a tipurilor built-in.
  - Utilizarea listei de inițializare a membrilor (în ordinea declarării în clasă) în locul atribuirii în corpul constructorului.
  - Înlocuirea obiectelor statice non-locale cu obiecte statice locale (*Meyer's Singleton*) pentru a evita problemele legate de ordinea inițializării între fișiere `.cpp` diferite.
- **Item 5**: *Know what functions C++ silently writes and calls.*
  - Funcțiile generate automat de compilator (constructor default, copy constructor, copy assignment `operator=`, destructor).
  - Cazul în care compilatorul refuză să genereze `operator=` (clase cu membri referință sau `const`), dar permite copy constructor-ul.
- **Item 6**: *Explicitly disallow the use of compiler generated functions you do not want.*
  - Interzicerea copierii obiectelor unice folosind `= delete` (C++11) și clasa de bază `Uncopyable` / metode `private` nedefinite (C++98).

