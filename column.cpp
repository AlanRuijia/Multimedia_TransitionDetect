#include "column.h"

column::column(float col[32]):next(NULL){
    for (int i = 0; i< 32;i++){
        cols[i] = col[i];
    }
}

column::~column(){

}

column* column::push(float col[32]){
    next = new column(col);
    return next;
}
