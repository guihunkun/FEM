#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <ctime>

#include "fem.h" 


bool Polygon::setPoint(const unsigned int index, const Point& p)
{
    if(index >= _vertex.size()) {
      return false;
    }
    _vertex[index] = p;
    return true;
}

bool Polygon::setPoint(const unsigned int index, 
                   const double x, const double y, const double z)
{
    if(index >= _vertex.size()) {
      return false;
    }
    _vertex[index].setX(x);
    _vertex[index].setY(y);
    _vertex[index].setZ(z);
    return true;
}


const double Polygon::getArea() const
{
    int n = _vertex.size();
    if(n < 3) {
      return 0.0f;
    }
    double area = 0.0f;
    double x,y;
    y = _vertex[0].getY();
    x = _vertex[n-1].getX();
    area = y*(x - _vertex[1].getX());
    for(int i = 1; i < n; ++i)
    {
      y = _vertex[i].getY();
      x = _vertex[i-1].getX();
      area += y*(x - _vertex[(i+1)%n].getX());
    }
    return fabs(area*0.5);
}

bool Polygon::getXYRange(double& minx, double& maxx, 
                     double& miny, double& maxy) const
{
    if(!_vertex.empty())
    {
      minx = _vertex[0].getX();
      maxx = _vertex[0].getX();
      miny = _vertex[0].getY();
      maxy = _vertex[0].getY();
      for(unsigned int i = 1; i < _vertex.size(); ++i)
      {
        minx = min(minx, _vertex[i].getX());
        maxx = max(maxx, _vertex[i].getX());
        miny = min(miny, _vertex[i].getY());
        maxy = max(maxy, _vertex[i].getY());
      }
      return true;
    } else {
      return false;
    }
}

bool Polygon::getCenter(Point& p) const
{
    double minx, maxx, miny, maxy;
    getXYRange(minx, maxx, miny, maxy);
    p.setX((minx+maxx)/2.0);
    p.setY((miny+maxy)/2.0);
    return true;
}

double Polygon::getDistance(const Point& p) const
{
    double minx, maxx, miny, maxy;
    getXYRange(minx, maxx, miny, maxy);
    double pox = (minx+maxx)/2.0;
    double poy = (miny+maxy)/2.0;
    double dis = (pox-p.getX())*(pox-p.getX()) + (poy-p.getY())*(poy-p.getY());
    if(Equal(dis, 0.0)) {
      return 0.0;
    }
    return sqrt(dis);
}
  
  
bool Polygon::isRectangle() const
{
    for(unsigned int i = 0; i < _vertex.size(); ++i)
    {
      Point p1 = _vertex[i];
      Point p2 = _vertex[i == _vertex.size()-1 ? 0 : i+1];
      if(!Equal(p1.getY(), p2.getY()))
      {
        if(!Equal(p1.getX(), p2.getX())) {
          return false;
        }
      }
    }
    return true;
}


bool Polygon::isInPolygon(const Point& p) const
{
    double minx, maxx, miny, maxy;
    getXYRange(minx, maxx, miny, maxy);
    double x = p.getX();
    double y = p.getY();
    if(Less(minx, x) && Less(x, maxx) && Less(miny, y) && Less(y, maxy)) {
      return true;
    }
    return false;
}


  
  
  

using namespace std;
int main()
{
	cout<<"FEM"<<endl;
	return 0;
}
