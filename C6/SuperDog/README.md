# Суперпёс

Демонстрация добавления талантов собаке. Таланты — отдельные классы, наследуемые от абстрактного `Talent`. Класс `Dog` не наследуется от `Talent`.

## Структура проекта
```bash
SuperDog/
├── include/
│   ├── talent.h
│   ├── swimming.h
│   ├── dancing.h
│   ├── counting.h
│   └── dog.h
├── src/
│   ├── dog.cpp
│   └── CMakeLists.txt
├── main.cpp
├── CMakeLists.txt
└── README.md
```

## Сборка
```bash
mkdir build && cd build
cmake ..
make
./super_dog
