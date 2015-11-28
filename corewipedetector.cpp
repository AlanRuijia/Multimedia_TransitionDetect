#include "corewipedetector.h"

CoreWipeDetector::CoreWipeDetector()
{

}
void TransitionDetect::GetHistogram(float r[32][32], float g[32][32], float (*h)[6][6]){
    float N[6];
    for (int i = 0;i<6;i++)
        N[i] = i/6.0;
    for (int i = 0;i<32;i++){
        for (int j = 0;j < 32 ;j++){
            (*h)[(int)(r[i][j]/(1.0/6.0))][(int)(g[i][j]/(1.0/6.0))]+=1;
        }
    }
}

bool TransitionDetect::AddCols(){
    cout << "AddCols\n";
    histogram *his = NULL, *before = NULL, *front = NULL,*temp = NULL;

    while(true){
        Mat frame,small_frame;
        vc.read(frame);
        Size size(32,32);
        if (frame.empty()){
            cout << "Video is empty now\n";
            break;
        }
        resize(frame,small_frame,size,32,32);

        Vec3b intensity4bits[32][32];
        float r[32][32];
        float g[32][32];

        float Histogram[6][6];
        Mat h[2];
        for (int i  = 0;i<6;i++)
            for (int j = 0;j < 6; j++)
                Histogram[i][j] = 0;

        for (int i = 0;i<32;i++){
            for (int j=0;j<32;j++){
                intensity4bits[i][j] = small_frame.at<Vec3b>(Point(i,j));
                float total = intensity4bits[i][j][0] + intensity4bits[i][j][1] + intensity4bits[i][j][2];
                r[i][j] = intensity4bits[i][j][0]/total;
                g[i][j] = intensity4bits[i][j][1]/total;
                }
            }
            GetHistogram(r,g,&Histogram);
            his->BuildHistogram(Histogram);
            if (front == NULL){
                front = his;
                before = his;
            }
            else {
                before->next = his;
                his->previous = before;
                before = before->next;
            }
    }
    temp = front;
    for (;temp->next!=NULL;temp = temp->next){
        temp->CalHistogram(temp->next);
    }
    return true;
}

Mat TransitionDetect::OutputImg(){
    Mat a;
    return a;
}
