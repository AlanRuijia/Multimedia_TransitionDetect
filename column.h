#ifndef COLUMN_H
#define COLUMN_H

#include <iostream>

using namespace std;

class column{
    float cols[32];

public:

    column * next;

    column(){
        next = NULL;
        for (int i = 0;i<32;i++)
            cols[i] = 1;
    }
    column(float col[32]);

    ~column();

    column* push(float col[32]);

    float GetColumni(int i){
        return cols[i];
    }
};
#endif // COLUMN_H
