#ifndef __FEM__
#define __FEM__


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <math.h>


using namespace std;

const double FLOAT_EPS = 1e-10;
template<class T1, class T2>  static bool Equal(T1 t1, T2 t2) {return fabs(t1-t2) < FLOAT_EPS;}
template<class T1, class T2>  static bool Greater(T1 t1, T2 t2) {return t1-t2 > FLOAT_EPS;}
template<class T1, class T2>  static bool Less(T1 t1, T2 t2) {return t2-t1 > FLOAT_EPS;}
template<class T1, class T2>  static bool GreaterOrEqual(T1 t1, T2 t2) {return fabs(t1-t2) >= FLOAT_EPS;}
template<class T1, class T2>  static bool LessOrEqual(T1 t1, T2 t2) {return t1-t2 <= FLOAT_EPS;}


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

class Polygon
{
	public:
	  Polygon() : _name(""), _vertex() { }
	  Polygon(const string& name, const vector<Point>& vertex) : _name(name), _vertex(vertex) {}
	  ~Polygon();
	  const vector<Point>& getVertex() const {return _vertex;}
      void clear() {_vertex.clear();}
      void append(const Point& p) {_vertex.push_back(p);}
      bool setPoint(const unsigned int index, const Point& p);
      bool setPoint(const unsigned int index, const double x, const double y, const double z);
      void setPoints(const vector<Point>& vertex) {_vertex.clear();_vertex = vertex;}
      const double getArea() const;
      bool getXYRange(double& minx, double& maxx, double& miny, double& maxy) const;
      bool getCenter(Point& p) const;
      // calculate distance of p and poly center
      double getDistance(const Point& p) const; 
      bool isRectangle() const;
      bool isInPolygon(const Point& p) const;		
	
	private:
		string _name;
		vector<Point> _vertex;
};




#endif 
