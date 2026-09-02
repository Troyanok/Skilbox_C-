# Заплыв на 100 метров

Программа симулирует заплыв шести пловцов. Каждый пловец движется в отдельном потоке с заданной скоростью. Выводится текущее состояние каждую секунду и итоговая таблица.

## Структура проекта
```bash
SwimRace/
├── include/
│   └── swimmer.h
├── src/
│   ├── swimmer.cpp
│   └── CMakeLists.txt
├── main.cpp
├── CMakeLists.txt
├── test_cases.txt
└── README.md
```

## Сборка

```bash
mkdir build && cd build
cmake ..
make
./swim_race
