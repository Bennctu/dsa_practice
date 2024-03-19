#include <lib_hello.h>

namespace Eigen{
 void print() {
    std::cout << "Hello Eigen" << std::endl;
 }
 void showVec() {
    std::cout << Eigen::Vector3d(0, 0, 0) << std::endl;
 }
}

namespace cv{
 void print() {
    std::cout << "Hello OpenCV" << std::endl;
 };
 void showVec() {
    std::cout << cv::Vec3d(0, 0, 0) << std::endl;
 }
}