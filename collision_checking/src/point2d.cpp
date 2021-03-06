#include "point2d.h"
#include <cmath>

namespace collision{
double point2d::get_angle(){return std::atan2(y_,x_);}

void point2d::normalize(){
    double l=get_length();
    if(l>kMathEpsilon){
        x_=x_/l;
        y_=y_/l;
    }
}

double point2d::get_length() const{
    return std::hypot(x_,y_);
}

double point2d::distance_to_point(const point2d& another) const{
    return std::hypot(x_-another.get_x(),y_-another.get_y());
}

double point2d::crossproduct(const point2d& another) const{
    return x_*another.get_y()-y_*another.get_x();
}

double point2d::innerproduct(const point2d& another) const{
    return x_*another.get_x()+y_*another.get_y();
}

point2d point2d::operator + (const point2d& another) const{
    return point2d(x_+another.get_x(),y_+another.get_y());
}

point2d point2d::operator - (const point2d& another) const{
    return point2d(x_-another.get_x(),y_-another.get_y());
}

point2d point2d::operator * (const double ratio) const{
    return point2d(x_*ratio,y_*ratio);
}

point2d point2d::operator / (const double ratio) const{
    return point2d(x_/ratio,y_/ratio);
}

point2d point2d::operator += (const point2d& another){
    x_+=another.get_x();
    y_+=another.get_y();
    return *this;
}

point2d point2d::operator -= (const point2d& another){
    x_-=another.get_x();
    y_-=another.get_y();
    return *this;
}

point2d point2d::operator *= (const double ratio){
    x_*=ratio;
    y_*=ratio;
    return *this;
}

point2d point2d::operator /=(const double ratio){
    x_/=ratio;
    y_/=ratio;
    return *this;
}

bool point2d::operator == (const point2d& another) const{
    return std::abs(x_-another.get_x())<kMathEpsilon && std::abs(y_-another.get_y())<kMathEpsilon;
}

point2d operator * (const double ratio,const point2d& point){
    return point2d(ratio*point.get_x(),ratio*point.get_y());
}

}