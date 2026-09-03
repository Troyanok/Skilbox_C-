# Использование умного указателя

Демонстрация работы `std::shared_ptr` для управления игрушками между собаками.

## Структура проекта
```bash
SharedPtrUsage/
├── include/
│   ├── toy.h
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
./shared_ptr_usage
