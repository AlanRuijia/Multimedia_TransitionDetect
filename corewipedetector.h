#ifndef COREWIPEDETECTOR_H
#define COREWIPEDETECTOR_H

#include <opencv2/opencv.hpp>
#include "column.h"


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
        filename = "/Users/Jerry/Movies/Clip #1-SD 480p.mov";
        cout << filename << "at TransitionDetect" << endl;
        vc = VideoCapture(filename);

    }

    ~TransitionDetect(){
        vc.release();
    }

    bool AddCols();

    void GetHistogram(float r[32][32], float g[32][32], float& h[32][32]);
    Mat OutputImg();

};

class CoreWipeDetector
{
public:
    CoreWipeDetector();
};


#endif // COREWIPEDETECTOR_H
