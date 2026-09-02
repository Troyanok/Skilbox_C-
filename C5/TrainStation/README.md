# Симуляция работы вокзала

Три поезда (A, B, C) едут к одному вокзалу. Вокзал может принимать только один поезд. Прибывший поезд ждёт команды `depart`.

## Структура проекта
```bash
TrainStation/
├── include/
│ ├── train.h
│ └── station.h
├── src/
│ ├── train.cpp
│ ├── station.cpp
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
./train_station
