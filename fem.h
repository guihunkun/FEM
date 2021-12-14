#ifndef __FEM__
#define __FEM__


class Point
{
/**
  * Point coordinate information
  */
  public:
    Point(const double x = 0, const double y = 0, const double z = 0):_x(x), _y(y) , _z(z){}
    Point(const Point& p) : _x( p.getX() ), _y( p.getY() ), _z(p.getZ()) {;}
    ~Point() {}
    const double getX() const {return _x;}
    const double getY() const {return _y;}
    const double getZ() const {return _z;}
    void setX(const double x) {_x = x;}
    void setY(const double y) {_y = y;}
    void setZ(const double z) {_z = z;}
    
  private:
    double _x, _y, _z;
};





#endif 
