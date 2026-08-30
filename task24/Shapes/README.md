# Иерархия геометрических фигур

## Описание
Программа моделирует геометрические фигуры: круг, квадрат, равносторонний треугольник, прямоугольник. Для каждой фигуры задаются координаты центра и цвет (red/blue/green/none). Пользователь вводит команды, программа выводит площадь и описывающий прямоугольник.

## Структура проекта
Shapes/
├── include/
│   ├── figure.h
│   ├── circle.h
│   ├── square.h
│   ├── triangle.h
│   └── rectangle.h
├── src/
│   ├── circle.cpp
│   ├── square.cpp
│   ├── triangle.cpp
│   ├── rectangle.cpp
│   └── CMakeLists.txt
├── main.cpp
├── CMakeLists.txt
└── README.md

## Сборка
```bash
mkdir build && cd build
cmake ..
make
./shapes_app