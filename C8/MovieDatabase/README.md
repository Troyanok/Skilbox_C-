# Анализ базы данных фильмов
Программа загружает JSON-базу из пяти фильмов и ищет актёров по имени или фамилии. Используется библиотека nlohmann/json.

## Структура проекта
```bash
MovieDatabase/
├── data/
│ └── movies_db.json
├── include/
│ └── movie_database.h
├── src/
│ ├── movie_database.cpp
│ └── CMakeLists.txt
├── main.cpp
├── CMakeLists.txt
└── README.md
```

## Сборка
```bash
mkdir build && cd build
cmake ..
