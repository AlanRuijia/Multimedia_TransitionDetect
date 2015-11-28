#ifndef HISTOGRAM
#define HISTOGRAM

#include <opencv2/opencv.hpp>
using namespace cv;
class histogram{
    Mat h;
    Mat z,zt;
    Mat A,D;
public:
    histogram * next;
    histogram * previous;

    histogram():next(NULL), previous(NULL){}
    ~histogram(){}

    void BuildHistogram(float Histogram[6][6]);
    void CalHistogram(histogram*);
    Mat Geth()const{return h;}
};

#endif // HISTOGRAM

