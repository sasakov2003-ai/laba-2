#include "ExpressTrain.h"
#include <iostream>
#include <stdexcept>

// Конструктор без параметров — вызываем конструктор базового класса
ExpressTrain::ExpressTrain() : Train(), maxSpeed(0) {
    // Train() — вызов конструктора базового класса без параметров
    std::cout << "[ExpressTrain] Вызван конструктор без параметров" << std::endl;
}

// Конструктор с параметрами
ExpressTrain::ExpressTrain(std::string dest, int num, std::string time, int speed)
    : Train(dest, num, time), maxSpeed(speed) {
    // Train(dest, num, time) — вызов конструктора базового класса с параметрами
    std::cout << "[ExpressTrain] Вызван конструктор с параметрами: " << dest
        << " скорость=" << speed << " км/ч" << std::endl;
}

// Конструктор копирования
ExpressTrain::ExpressTrain(const ExpressTrain& other)
    : Train(other), maxSpeed(other.maxSpeed) {
    // Train(other) — вызов конструктора копирования базового класса
    std::cout << "[ExpressTrain] Вызван конструктор копирования" << std::endl;
}

// Деструктор
ExpressTrain::~ExpressTrain() {
    std::cout << "[ExpressTrain] Вызван деструктор" << std::endl;
}

void ExpressTrain::setMaxSpeed(int speed) {
    if (speed <= 0) {
        throw std::invalid_argument("Ошибка: скорость должна быть положительной!");
    }
    maxSpeed = speed;
}

int ExpressTrain::getMaxSpeed() const {
    return maxSpeed;
}

ExpressTrain& ExpressTrain::operator=(const ExpressTrain& other) {
    if (this != &other) {
        Train::operator=(other);  // вызываем оператор присваивания базового класса
        maxSpeed = other.maxSpeed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ExpressTrain& train) {
    os << static_cast<const Train&>(train);  // выводим поля базового класса
    // static_cast<const Train&>(train) — приводим ExpressTrain к Train,
    // чтобы вызвать operator<< для базового класса
    os << " | Тип: Скорый | Макс. скорость: " << train.maxSpeed << " км/ч";
    return os;
}

std::istream& operator>>(std::istream& is, ExpressTrain& train) {
    is >> static_cast<Train&>(train);  // считываем поля базового класса
    int speed;
    std::cout << "  Введите максимальную скорость (км/ч): ";
    is >> speed;
    train.setMaxSpeed(speed);
    return is;
}
