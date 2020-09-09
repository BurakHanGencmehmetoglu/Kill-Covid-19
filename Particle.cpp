#include "Particle.h"
Particle::Particle(){
	x=0;
	y=0;
}




Particle::Particle(float x_coord,float y_coord){
	x=x_coord;
	y=y_coord;
}




Particle::Particle(const Particle& rhs){
	x=rhs.x;
	y=rhs.y;
}



float Particle::X() const{
	return x;
}



float Particle::Y() const{
	return y;
}



float Particle::FindDistance(const Particle& rhs) const{
	return sqrt(pow(rhs.X()-x,2)+pow(rhs.Y()-y,2));
}



bool Particle::operator==(const Particle& rhs) const{
	if (abs(rhs.X()-x)<EPSILON && abs(rhs.Y()-y)<EPSILON){return true;}
	return false;
}




ostream& operator<<(ostream& os,const Particle& particle){
	os<<"("<<particle.X()<<","<<particle.Y()<<")";
	return os;
}

