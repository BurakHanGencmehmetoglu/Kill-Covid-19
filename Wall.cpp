#include "Wall.h"





Wall::Wall(){
	start=NULL;
	end=NULL;
	length=0;
	curve=false;
}





Wall& Wall::operator=(const Wall& rhs){
	if (this!=&rhs)
	{
		if (start!=NULL){delete start;}
		if (end!=NULL){delete end;}
		if (rhs.start!=NULL)
		{ 
			float x=(rhs.start)->X();
			float y=(rhs.start)->Y();
			float x1=(rhs.end)->X();
			float y1=(rhs.end)->Y();
			start=new Particle(x,y);
            end=new Particle(x1,y1);
		}
		length=rhs.length;
		curve=rhs.curve;
	}
	return *this;
}







Wall::Wall(float len){
	start=NULL;
	end=NULL;
	length=len;
	curve=false;
}






Wall::Wall(const Particle& start1,const Particle& end1){
	length=start1.FindDistance(end1);
	start=new Particle(start1.X(),start1.Y());
    end=new Particle(end1.X(),end1.Y());
	curve=false;
}






Wall::Wall(const Wall& rhs){
	curve=false;
	start=NULL;
	end=NULL;
	length=0;
	*this=rhs;
}




const Particle& Wall::GetInitialParticle() const {
	return *start;
}




const Particle& Wall::GetFinalParticle() const {
	return *end;
}





float Wall::FindAngleBetween(const Wall& rhs) const {
	float pi=3.14159265;
    float x1,y1;
    float x2,y2;
	float dot;
    float uzunluk1;
    float uzunluk2;
    float angle;
	x1=end->X()-start->X();
	y1=end->Y()-start->Y();
	x2=rhs.GetFinalParticle().X()-rhs.GetInitialParticle().X();
	y2=rhs.GetFinalParticle().Y()-rhs.GetInitialParticle().Y();
    dot=x1*x2+y1*y2;
    uzunluk1=sqrt(pow(x1,2)+pow(y1,2));
    uzunluk2=sqrt(pow(x2,2)+pow(y2,2));
    angle=acos(dot/(uzunluk1*uzunluk2))*(180.0/pi);
	return angle;
}






float Wall::GetLength() const {
	return length;
}





void Wall::ComputeLength(){
	length=start->FindDistance(*end);
	return;
}



Wall* Wall::Clone() const {
	Wall* copy;
	if (start!=NULL)
	{
		copy= new Wall(*start,*end);
	}
	else 
	{
		copy= new Wall(length);
	}	
	return copy;
}





Wall::~Wall() {
	if (start!=NULL)
	{
		delete start;
		start=NULL;
	}
	if (end!=NULL)
	{	
		delete end;
		end=NULL;
	}
}





bool Wall::IsContinuousLinear(const Wall& rhs) const {
	bool vertical1=false;
	bool vertical2=false;
	bool check=false;
	float slope1=-100;
	float slope2=500;
	float yeksen=end->Y()-start->Y();
	float xeksen=end->X()-start->X();
	if (abs(xeksen)<=EPSILON){vertical1=true;}
	else {slope1=yeksen/xeksen;}	
	float xeksen1=rhs.GetFinalParticle().X()-rhs.GetInitialParticle().X();
	float yeksen1=rhs.GetFinalParticle().Y()-rhs.GetInitialParticle().Y();
	if (abs(xeksen1)<=EPSILON){vertical2=true;}
	else {slope2=yeksen1/xeksen1;}
	if (vertical1 && vertical2) {check=true;}
	if (abs(slope1-slope2)<=EPSILON) {check=true;}
	if (check)
	{
		if ((*start)==rhs.GetFinalParticle())
		{
			return true;
		}
		else if ((*end)==rhs.GetInitialParticle()){return true;}
	}
	return false;
}





const Wall& Wall::operator+(const Wall& rhs) const {
	if (IsContinuousLinear(rhs))
	{
		if ((*start)==rhs.GetFinalParticle())
		{
			Wall* copy = new Wall(rhs.GetInitialParticle(),*end);
			return *copy;
		}
		else if ((*end)==rhs.GetInitialParticle())
		{
			Wall* copy = new Wall(*start,rhs.GetFinalParticle());
			return *copy;
		}
	}	
	else 
	{
		throw ApplePearException();
	}
	
}
