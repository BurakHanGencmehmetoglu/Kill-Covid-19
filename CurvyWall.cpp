#include "CurvyWall.h"




CurvyWall::CurvyWall(){
	start=NULL;
	end=NULL;
	center=NULL;
	length=0;
	curve=true;
	radius=0;
}







CurvyWall& CurvyWall::operator=(const CurvyWall& rhs){
	if (this!=&rhs)
	{
		if (start!=NULL){delete start;}
		if (end!=NULL){delete end;}
		if (center!=NULL){delete center;}
		if (rhs.start!=NULL)
		{ 
			float x=(rhs.start)->X();
			float y=(rhs.start)->Y();
			float x1=(rhs.end)->X();
			float y1=(rhs.end)->Y();
			float x2=(rhs.center)->X();
			float y2=(rhs.center)->Y();
			start=new Particle(x,y);
            end=new Particle(x1,y1);
			center=new Particle(x2,y2);
		}
		length=rhs.length;
		curve=rhs.curve;
		radius=rhs.radius;
	}
	return *this;
}




CurvyWall::CurvyWall(float len,float rad){
	radius=rad;
	length=len;
	start=NULL;
	end=NULL;
	center=NULL;
	curve=true;
}






CurvyWall::CurvyWall(const Particle& start1, const Particle& end1, const Particle& center1){
	start=new Particle(start1.X(),start1.Y());
    end=new Particle(end1.X(),end1.Y());
	center=new Particle(center1.X(),center1.Y());
	curve=true;
	radius=start->FindDistance(*center);
	ComputeLength();
}






CurvyWall::CurvyWall(const CurvyWall& rhs){
	start=NULL;
	end=NULL;
	center=NULL;
	length=0;
	radius=0;
	curve=true;
	*this=rhs;
}




float CurvyWall::GetRadius() const {
	return radius;
}



const Particle& CurvyWall::GetCenter() const {
	return *center;
}




void CurvyWall::ComputeLength() {
        Wall* temp1=new Wall(*start,*center);
        Wall* temp2=new Wall(*end,*center);
        float angle=temp1->FindAngleBetween(*temp2);
        delete temp1;
        delete temp2;
        length=2*PI*radius*(angle/360);
}




Wall* CurvyWall::Clone() const {
	CurvyWall* copy;
	if (center!=NULL)
	{
		copy=new CurvyWall(*start,*end,*center);
	}
	else
	{
		copy=new CurvyWall(length,radius);
	}
	return copy;
}




bool CurvyWall::IsContinuousLinear(const Wall& rhs) const {
	return false;
}




CurvyWall::~CurvyWall() {
	if (center!=NULL)
	{
		delete center;
		center=NULL;
	}
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






const Wall& CurvyWall::operator+(const Wall& rhs) const {
	CurvyWall* copy;
	CurvyWall* temp;
	if (curve==true && rhs.curve==true)
	{
		temp= (CurvyWall *) &rhs;
	}	
	if (curve==true && rhs.curve==true && (*center)==temp->GetCenter())
	{
                if ((*start)==rhs.GetFinalParticle())
                {
                        copy = new CurvyWall(*end,rhs.GetInitialParticle(),*center);
                        return *copy;
                }
                else if ((*end)==rhs.GetInitialParticle())
                {
                        copy = new CurvyWall(*start,rhs.GetFinalParticle(),*center);
                        return *copy;
         	}
	}
	else
	{
		throw ApplePearException();
	}
}
