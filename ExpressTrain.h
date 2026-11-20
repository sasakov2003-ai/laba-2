#ifndef EXPRESS_TRAIN_H
#define EXPRESS_TRAIN_H

#include "Train.h"  // подключаем базовый класс

// ExpressTrain наследует от Train — добавляет поле "максимальная скорость"
class ExpressTrain : public Train {
    // public наследование — публичные поля базового класса остаются публичными
private:
    int maxSpeed;  // максимальная скорость (км/ч) — своё поле наследника

public:
    ExpressTrain();                                              // без параметров
    ExpressTrain(std::string dest, int num, std::string time, int speed); // с параметрами
    ExpressTrain(const ExpressTrain& other);                     // копирования
    virtual ~ExpressTrain();                                     // деструктор

    void setMaxSpeed(int speed);  // сеттер
    int getMaxSpeed() const;      // геттер

    ExpressTrain& operator=(const ExpressTrain& other);  // оператор присваивания
    friend std::ostream& operator<<(std::ostream& os, const ExpressTrain& train);
    friend std::istream& operator>>(std::istream& is, ExpressTrain& train);
};

#endif
