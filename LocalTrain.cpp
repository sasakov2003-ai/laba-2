#include "LocalTrain.h"
#include <iostream>
#include <stdexcept>

LocalTrain::LocalTrain() : Train(), numStops(0) {
    std::cout << "[LocalTrain] Вызван конструктор без параметров" << std::endl;
}

LocalTrain::LocalTrain(std::string dest, int num, std::string time, int stops)
    : Train(dest, num, time), numStops(stops) {
    std::cout << "[LocalTrain] Вызван конструктор с параметрами: " << dest
        << " остановок=" << stops << std::endl;
}

LocalTrain::LocalTrain(const LocalTrain& other)
    : Train(other), numStops(other.numStops) {
    std::cout << "[LocalTrain] Вызван конструктор копирования" << std::endl;
}

LocalTrain::~LocalTrain() {
    std::cout << "[LocalTrain] Вызван деструктор" << std::endl;
}

void LocalTrain::setNumStops(int stops) {
    if (stops < 0) {
        throw std::invalid_argument("Ошибка: количество остановок не может быть отрицательным!");
    }
    numStops = stops;
}

int LocalTrain::getNumStops() const {
    return numStops;
}

LocalTrain& LocalTrain::operator=(const LocalTrain& other) {
    if (this != &other) {
        Train::operator=(other);
        numStops = other.numStops;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const LocalTrain& train) {
    os << static_cast<const Train&>(train);
    os << " | Тип: Пригородный | Остановок: " << train.numStops;
    return os;
}

std::istream& operator>>(std::istream& is, LocalTrain& train) {
    is >> static_cast<Train&>(train);
    int stops;
    std::cout << "  Введите количество остановок: ";
    is >> stops;
    train.setNumStops(stops);
    return is;
}
