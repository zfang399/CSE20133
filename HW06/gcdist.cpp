/**
 * by Zhaoyuan Fang
 * CSE20133 HW6
 * gcdist.cpp
 */

#include <iostream>
#include <cmath>
using namespace std;

#define R (3959)
#define PI (3.14159265)

struct Point{
  double latitude;
  double longitude;
};

double GCDistance(Point*,Point*);

int main(){
  double ans=0;
  Point prev,now;
  bool first=true;
  double latit,longi;
  while(cin>>latit>>longi){
    if(first){
  	  first=false;
  	  now.latitude=latit;
  	  now.longitude=longi;
  	  continue;
  	}else{
  	  prev.latitude=now.latitude;
  	  prev.longitude=now.longitude;
  	  now.latitude=latit;
  	  now.longitude=longi;
  	}
  	ans+=GCDistance(&prev,&now);
  }
  cout<<ans<<endl;
  return 0;
}

double GCDistance(Point* a,Point* b){
  double delta_latitude=abs(a->latitude-b->latitude)*PI/180;
  double delta_longitude=abs(a->longitude-b->longitude)*PI/180;
  return R*2*asin(sqrt((pow(sin(delta_latitude/2),2))+cos(a->latitude*PI/180)*cos(b->latitude*PI/180)*pow(sin(delta_longitude/2),2)));
}