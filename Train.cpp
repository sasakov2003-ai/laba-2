#include "Train.h"       // подключаем заголовок нашего класса
#include <iostream>      // для cout/cerr
#include <stdexcept>     // для исключений

// ============================================================
// Конструктор без параметров — создаёт "пустой" объект
// ============================================================
Train::Train() : destination(""), trainNumber(0), departureTime("") {
    // Список инициализации: задаём поля значениями по умолчанию
    std::cout << "[Train] Вызван конструктор без параметров" << std::endl;
    // Выводим сообщение — так требует ТЗ
}

// ============================================================
// Конструктор с параметрами — создаёт объект с конкретными данными
// ============================================================
Train::Train(std::string dest, int num, std::string time)
    : destination(dest), trainNumber(num), departureTime(time) {
    // Инициализируем поля переданными значениями
    std::cout << "[Train] Вызван конструктор с параметрами: " << destination
        << " №" << trainNumber << " в " << departureTime << std::endl;
}

// ============================================================
// Конструктор копирования — создаёт копию другого объекта
// ============================================================
Train::Train(const Train& other)
    : destination(other.destination),       // копируем пункт назначения
    trainNumber(other.trainNumber),       // копируем номер
    departureTime(other.departureTime) {  // копируем время
    std::cout << "[Train] Вызван конструктор копирования: " << destination << std::endl;
}

// ============================================================
// Деструктор — вызывается при уничтожении объекта
// ============================================================
Train::~Train() {
    std::cout << "[Train] Вызван деструктор: " << destination << std::endl;
    // Здесь можно было бы освобождать динамическую память,
    // но в базовом классе её нет — она появится в TrainList
}

// ============================================================
// СЕТТЕРЫ — методы для установки значений с проверкой
// ============================================================

void Train::setDestination(std::string dest) {
    // Проверяем: пункт назначения не должен быть пустым
    if (dest.empty()) {
        // Бросаем исключение — так требует ТЗ
        throw std::invalid_argument("Ошибка: пункт назначения не может быть пустым!");
    }
    destination = dest; // если всё ок — сохраняем
}

std::string Train::getDestination() const {
    return destination; // возвращаем пункт назначения
    // const означает: метод не меняет поля объекта
}

void Train::setTrainNumber(int num) {
    // Номер поезда должен быть положительным
    if (num <= 0) {
        throw std::invalid_argument("Ошибка: номер поезда должен быть положительным числом!");
    }
    trainNumber = num;
}

int Train::getTrainNumber() const {
    return trainNumber;
}

void Train::setDepartureTime(std::string time) {
    // Проверяем формат: должно быть ровно 5 символов "ЧЧ:ММ"
    if (time.length() != 5 || time[2] != ':') {
        throw std::invalid_argument("Ошибка: время должно быть в формате ЧЧ:ММ (например, 14:30)!");
    }
    // Извлекаем часы и минуты для проверки диапазона
    int hours = std::stoi(time.substr(0, 2));   // первые 2 символа — часы
    int minutes = std::stoi(time.substr(3, 2)); // символы после двоеточия — минуты

    if (hours < 0 || hours > 23) {  // часы от 0 до 23
        throw std::invalid_argument("Ошибка: часы должны быть от 00 до 23!");
    }
    if (minutes < 0 || minutes > 59) { // минуты от 0 до 59
        throw std::invalid_argument("Ошибка: минуты должны быть от 00 до 59!");
    }
    departureTime = time; // всё хорошо — сохраняем
}

std::string Train::getDepartureTime() const {
    return departureTime;
}

// ============================================================
// ПЕРЕОПРЕДЕЛЁННЫЕ ОПЕРАТОРЫ
// ============================================================

// Оператор вывода << — позволяет писать cout << train
std::ostream& operator<<(std::ostream& os, const Train& train) {
    os << "Поезд №" << train.trainNumber
        << " | Пункт назначения: " << train.destination
        << " | Время отправления: " << train.departureTime;
    return os; // возвращаем поток, чтобы можно было chaining: cout << a << b
}

// Оператор ввода >> — позволяет писать cin >> train
std::istream& operator>>(std::istream& is, Train& train) {
    std::string dest, time;
    int num;

    std::cout << "  Введите пункт назначения: ";
    is >> dest;  // читаем строку (до пробела)

    std::cout << "  Введите номер поезда: ";
    is >> num;   // читаем число

    std::cout << "  Введите время отправления (ЧЧ:ММ): ";
    is >> time;  // читаем время

    // Устанавливаем значения через сеттеры (с проверками!)
    train.setDestination(dest);
    train.setTrainNumber(num);
    train.setDepartureTime(time);

    return is; // возвращаем поток
}

// Оператор присваивания = — копирует данные из другого объекта
Train& Train::operator=(const Train& other) {
    if (this != &other) {  // защита от самоприсваивания (a = a)
        // this — указатель на текущий объект
        // &other — адрес объекта, из которого копируем
        destination = other.destination;
        trainNumber = other.trainNumber;
        departureTime = other.departureTime;
    }
    return *this; // возвращаем ссылку на текущий объект (для chaining)
}

// Оператор < — для сортировки по времени отправления
bool Train::operator<(const Train& other) const {
    return departureTime < other.departureTime;
    // Строки сравниваются лексикографически, но для формата "ЧЧ:ММ" это работает корректно
}

// Оператор == — для поиска по номеру поезда
bool Train::operator==(const Train& other) const {
    return trainNumber == other.trainNumber;
}
