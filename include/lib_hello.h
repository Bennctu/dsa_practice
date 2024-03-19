#ifndef __LIB_HELLO_H__
#define __LIB_HELLO_H__
#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <iostream>

namespace Eigen{
 void print();
 void showVec();
}

namespace cv{
 void print();
 void showVec();
}

#define use_lib_is(x)  { using namespace x ; print();}
#define show_vector_format_of(x)  { using namespace x ; showVec();}

#endif  //__LIB_HELLO_H__
