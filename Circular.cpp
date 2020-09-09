#include "Circular.h"

Circular::Circular(int id1,float radius1) {
	id=id1;
	located=false;
	radius=radius1;
	connection=NULL;	
}




Circular::~Circular() {
	connection=NULL;
	for (int i=0;i<edge.size();i++)
	{
		delete edge[i];
	}	
	edge.clear();
}




void Circular::ConnectToCell(Cell* const cell){
	connection=cell;
	vector<Wall*> temp=cell->GetCellWall();
	for (int i=0;i<temp.size();i++)
        {		
      		edge.push_back(temp[i]->Clone());
        }
	located=true;
	return;
}





bool Circular::DoesFitInto(const Cell& rhs) const {
	Cell clone(rhs);
	clone.StrengthenCellWall();
	vector<Wall*> temp=clone.GetCellWall();
	if (temp.size()==1)
	{	
		CurvyWall* temp1= (CurvyWall *) temp[0];
		if (abs(temp1->GetRadius()-radius)<EPSILON)
		{
			return true;
		}
	}
	return false;
}






void Circular::React(){
	connection->StrengthenCellWall();
	vector<Wall*> temp=connection->GetCellWall();
	vector<Wall*> temp5;
	for (int i=0;i<temp.size();i++)
	{		
		CurvyWall* temp2 = (CurvyWall *) temp[i];
		float radius = (temp2->GetRadius())*2;
		Particle center(temp2->GetCenter().X(),temp2->GetCenter().Y());
		Particle start(temp2->GetCenter().X()+radius,temp2->GetCenter().Y());
		CurvyWall* temp3 =new CurvyWall(start,start,center);
		temp5.push_back(temp3);
	}
	connection->RenewCellWall(temp5);
}	






bool Circular::DoesContain(const Particle& rhs) const {
	CurvyWall* temp=(CurvyWall *) (edge[0]);
	float radius=temp->GetRadius();
	Particle x=temp->GetCenter();
	if (x.FindDistance(rhs)>radius)
	{
		return false;
	}
	else {return true;}
}


		
	























































