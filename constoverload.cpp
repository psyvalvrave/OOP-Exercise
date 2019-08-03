#include<constoverload.h>
#include<iostream>
using namespace std;
ostream& operator<<(std::ostream& out, const Point3& v){
    out << '(' << v[0] << ", " << v[1] << ", " << v[2] <<  ')';
    return out;
}
Point3::Point3(double x, double y, double z) {
    m_Coord[0] = x;
    m_Coord[1] = y;
    m_Coord[2] = z;
}

Point3 Point3::operator +(const Point3& v)const{
    return Point3(this->x+v.x,this->y+v.y,this->z+v.z);
}

Point3 Point3::operator -(const Point3& v)const{
    return Point3(this->x-v.x,this->y-v.y,this->z-v.z);
}

Point3 Point3::operator *(double s)const{
    return Point3(this->x*s,this->y*s,this->z*s);
}
const double& Point3::operator [](int index) const{
    if((index>=0)&&(index<cm_Dim))
        return m_Coord[index];
    else
        return zero(index);
}

double& Point3::operator [](int index){
    if((index>=0)&&(index<cm_Dim))
        return m_Coord[index];
    else
        return zero(index);
}
inline static double& zero(int index) {
    static double _zero = 0 ;
    _zero = 0 ;
    cerr << "index out of bounds: "  << index<< endl ;
    return _zero;
}
