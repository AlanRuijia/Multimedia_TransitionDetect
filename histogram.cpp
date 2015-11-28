#include "histogram.h"

void histogram::BuildHistogram(float h[][]){
    h = Mat(6,6,CV_32FC1,Histogram).inv();
    z = Mat(36,1,CV_32FC1,Histogram).inv();
    zt = Mat(1,36,CV_32FC1,Histogram).inv();
    for (int i = 0;i < 36;i++)
        for (int j = 0;j<36;j++){
            A[i][j] =z[i] * zt[j] / sqrt(2);
        }
    D =
}
