//
// Created by tenni on 02/06/2023.
//

#ifndef EXAMEN_PRA_POO_V1_EXCEPTIECUSTOMNUMBER_H
#define EXAMEN_PRA_POO_V1_EXCEPTIECUSTOMNUMBER_H

#include <iostream>

class ExceptieCustomNumber: public std::exception {
private:
    std::string message;
public:
    ExceptieCustomNumber(std::string message): message(message){}

    const char *what() const noexcept override {
        return message.c_str();
    }
};

#endif //EXAMEN_PRA_POO_V1_EXCEPTIECUSTOMNUMBER_H
