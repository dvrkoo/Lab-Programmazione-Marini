//
// Created by nick on 9/1/23.
//

#include "ctime"
#include "string"

#ifndef LAB_MARINI_DATETIME_H
#define LAB_MARINI_DATETIME_H

class DateTime {
private:


    std::time_t time;
public:
    DateTime();

    DateTime(time_t time);

    ~DateTime();

    void update();

    std::string getCurrentDateTime()const ;
};


#endif //LAB_MARINI_DATETIME_H
