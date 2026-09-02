# Симуляция работы кухни онлайн-ресторана

Программа моделирует кухню с онлайн-заказами. Заказы генерируются каждые 5–10 секунд, кухня готовит 5–15 секунд, курьер забирает каждые 30 секунд. 

## Структура
```bash
RestaurantKitchen/
├── include/
│ ├── order.h
│ ├── kitchen.h
│ └── courier.h
├── src/
│ ├── order.cpp
│ ├── kitchen.cpp
│ ├── courier.cpp
│ └── CMakeLists.txt
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
./restaurant_kitchen
