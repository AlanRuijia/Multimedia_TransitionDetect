#ifndef HISTOGRAM
#define HISTOGRAM

#include <opencv2/opencv.hpp>
using namespace cv;
class histogram{
    Mat h;
    Mat z,zt;
    Mat D,A;

public:
    histogram * next;
    histogram * previous;

    histogram():next(NULL), previous(NULL){}
    ~histogram(){}

    void BuildHistogram(float Histogram[6][6]);
};

#endif // HISTOGRAM

