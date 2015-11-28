#ifndef COREWIPEDETECTOR_H
#define COREWIPEDETECTOR_H

#include <vector>

#include "column.h"
#include "histogram.h"


using namespace cv;
using namespace std;


class TransitionDetect{
    VideoCapture vc;
    int ColumnCount;
    column *cols;
    column *end;

public:

    TransitionDetect():ColumnCount(0),cols(NULL),end(NULL){}

    TransitionDetect(string filename):ColumnCount(0),cols(NULL),end(NULL){
        cout << "Constructor\n";
        filename = "/home/open/Multimedia/MultiMediaProject/7.mov";
        cout << filename << "at TransitionDetect" << endl;
        vc = VideoCapture(filename);
        cout << "Exit Constructor\n";
    }

    ~TransitionDetect(){
        vc.release();
    }

    bool AddCols();

    void GetHistogram(float r[32][32], float g[32][32], float (*)[6][6]);

   // void IHistogramDifference(Mat h, Mat d);

    Mat OutputImg();

};

class CoreWipeDetector
{
public:
    CoreWipeDetector();
};


#endif // COREWIPEDETECTOR_H
