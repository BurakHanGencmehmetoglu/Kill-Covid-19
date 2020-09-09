#include "Tissue.h"

Tissue::Tissue(){
	minx=0;
	maxx=0;
	miny=0;
	maxy=0;
}




Tissue::Tissue(float x,float y,float z,float t){
	minx=x;
        maxx=y;
        miny=z;
        maxy=t;
}




Tissue::Tissue(const Tissue& rhs){
	for (int i=0;i<cells.size();i++)
	{
		delete cells[i];
	}
	*this=rhs;
}




Tissue::~Tissue(){
	if (cells.size()!=0)
	{
	for (int i=0;i<cells.size();i++)
	{
		delete cells[i];
	}
	cells.clear();
	}
}



float* Tissue::GetCoordinates(){
	float* temp=new float[4];
	temp[0]=minx;
	temp[1]=maxx;
	temp[2]=miny;
	temp[3]=maxy;
	return temp;
}



void Tissue::AddCell(Cell& rhs){
	cells.push_back(&rhs);
}



void Tissue::RemoveCell(Cell& rhs){
	for (int i=0;i<cells.size();i++)
	{
		if ((cells[i])->GetCellID()==rhs.GetCellID())
		{
			delete cells[i];
			cells[i]=NULL;
			cells.erase(cells.begin()+i);
			break;
		}
	}
}




const Cell& Tissue::GetCell(int id) const {
	bool a=false;
	int i=0;
        for (;i<cells.size();i++)
        {
                if ((cells[i])->GetCellID()==id)
                {
                        a=true;
                        break;
                }
        }
	if (a)
	{
		return *(cells[i]);
	}
	else 
	{
		throw DeadCellException();
	}
}





void Tissue::Interact(const vector<MicroOrganism*>& rhs){
	for (int i=0;i<rhs.size();i++)
	{
		for (int k=0;k<cells.size();k++)
		{
			if ((rhs[i])->DoesFitInto(*(cells[k])))
			{	
				(rhs[i])->ConnectToCell(cells[k]);
			}
		}
	}
}
