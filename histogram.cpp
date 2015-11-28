#include "histogram.h"
#include <iostream>
using namespace std;
void histogram::BuildHistogram(float Histogram[6][6]){
    h = Mat(6,6,CV_32FC1,Histogram);

}

void histogram::CalHistogram(histogram* his){

        z = h - his->Geth();
        zt = h - his->Geth();
        for (int i = 0;i < 36;i++)
            for (int j = 0;j<36;j++){
                A.at<float>(i,j) =1- z.at<float>(i) * zt.at<float>(j) / sqrt(2);
            }
        D = z * A * zt;
        cout << D << endl;
}
