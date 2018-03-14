#include <opencv2/opencv.hpp>

bool seam_carving(cv::Mat& in_image, int new_width, int new_height, cv::Mat& out_image);

bool reduce_vertical_seam(cv::Mat& in_image, cv::Mat& out_image);

bool reduce_horizontal_seam(cv::Mat& in_image, cv::Mat& out_image);
