#ifndef LOCAL_TRAIN_H
#define LOCAL_TRAIN_H

#include "Train.h"

// LocalTrain — пригородный поезд, добавляет поле "количество остановок"
class LocalTrain : public Train {
private:
    int numStops;  // количество остановок

public:
    LocalTrain();
    LocalTrain(std::string dest, int num, std::string time, int stops);
    LocalTrain(const LocalTrain& other);
    virtual ~LocalTrain();

    void setNumStops(int stops);
    int getNumStops() const;

    LocalTrain& operator=(const LocalTrain& other);
    friend std::ostream& operator<<(std::ostream& os, const LocalTrain& train);
    friend std::istream& operator>>(std::istream& is, LocalTrain& train);
};

#endif
