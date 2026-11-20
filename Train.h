#ifndef TRAIN_H          // защита от повторного включения заголовка
#define TRAIN_H          // (если файл уже включён — компилятор пропустит)

#include <string>        // подключаем библиотеку для работы со строками
#include <iostream>      // подключаем библиотеку для ввода/вывода
#include <stdexcept>     // подключаем библиотеку для исключений (exceptions)

// Базовый класс TRAIN — описывает поезд
class Train {
private:                          // поля скрыты от внешнего мира (инкапсуляция)
    std::string destination;      // название пункта назначения
    int trainNumber;              // номер поезда
    std::string departureTime;    // время отправления (формат "ЧЧ:ММ")

public:                           // публичный интерфейс — то, что видно снаружи

    // --- Конструкторы ---
    Train();                                                  // конструктор без параметров
    Train(std::string dest, int num, std::string time);       // конструктор с параметрами
    Train(const Train& other);                                // конструктор копирования

    // --- Деструктор ---
    virtual ~Train();  // virtual нужен, чтобы при удалении через указатель на базовый класс
    // вызывался деструктор наследника (полиморфизм)

// --- Set и Get методы (сеттеры и геттеры) ---
    void setDestination(std::string dest);   // установить пункт назначения
    std::string getDestination() const;      // получить пункт назначения (const = не меняет объект)
    void setTrainNumber(int num);            // установить номер поезда
    int getTrainNumber() const;              // получить номер поезда
    void setDepartureTime(std::string time); // установить время отправления
    std::string getDepartureTime() const;    // получить время отправления

    // --- Переопределённые операторы ---
    friend std::ostream& operator<<(std::ostream& os, const Train& train); // оператор вывода <<
    friend std::istream& operator>>(std::istream& is, Train& train);       // оператор ввода >>
    Train& operator=(const Train& other);    // оператор присваивания =
    bool operator<(const Train& other) const; // оператор сравнения < (для сортировки)
    bool operator==(const Train& other) const; // оператор сравнения == (для поиска)
};

#endif // TRAIN_H
