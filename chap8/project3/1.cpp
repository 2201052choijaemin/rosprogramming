#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    cout << "Hello OpenCV " << CV_VERSION << endl;

    Mat img = imread("../src/lenna.bmp");

    if (img.empty())
    {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("Original", img);

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    imshow("Gray", gray);

    Mat binary;
    threshold(gray, binary, 128, 255, THRESH_BINARY);
    imshow("Binary", binary);

    waitKey(0);

    return 0;
}
