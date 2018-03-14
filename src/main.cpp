#include <opencv2/opencv.hpp>

#include "sc.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if(argc != 5) {
        cout << "Usage: ../sc input_image new_width new_height output_image" << endl;
        return -1;
    }
    
    //Load the input image
    Mat in_image;
    in_image = imread(argv[1]);
   
    if(!in_image.data) {
        cout << "Could not load input image!!!" << endl;
        return -1;
    }

    //the image should have 3 channels
    if(in_image.channels()!=3) {
        cout << "Image does not have 3 channels!!!" << in_image.depth() << endl;
        return -1;
    }
    
    //get the new dimensions from the argument list
    int new_width = atoi(argv[2]);
    int new_height = atoi(argv[3]);
    
    //the output image
    Mat out_image;
    
    if(!seam_carving(in_image, new_width, new_height, out_image)) {
        return -1;
    }

    //write it on disk
    imwrite( argv[4], out_image);
    
    //also display them both
    namedWindow( "Original Image", WINDOW_AUTOSIZE );
    namedWindow( "Seam Carved Image", WINDOW_AUTOSIZE );
    imshow( "Original Image", in_image );
    imshow( "Seam Carved Image", out_image );
    cout << "Input Image Dimensions: " << in_image.rows << " x " << in_image.cols << endl;
    cout << "Output Image Dimensions: " << out_image.rows << " x " << out_image.cols << endl;
    waitKey(0);
    return 0;
}
