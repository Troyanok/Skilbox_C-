# Интерфейс Shape

Реализован абстрактный интерфейс `Shape` с чисто виртуальными методами. Классы-наследники `Circle`, `Rectangle`, `Triangle` вычисляют площадь и размеры описывающего прямоугольника. Функция `printParams` выводит информацию о фигуре.

## Структура проекта
```bash
ShapeInterface/
├── include/
│ ├── shape.h
│ ├── circle.h
│ ├── rectangle.h
│ └── triangle.h
├── src/
│ ├── circle.cpp
│ ├── rectangle.cpp
│ ├── triangle.cpp
│ └── CMakeLists.txt
├── main.cpp
├── CMakeLists.txt
└── README.md
```

## Сборка
```bash
mkdir build && cd build
cmake ..
make
./shape_app
