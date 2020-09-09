#include "Cell.h"


Cell::Cell(){
	id=-1;
	tissue=NULL;
}




Cell& Cell::operator=(const Cell& rhs){
	if (this!=&rhs)
	{
	id=rhs.GetCellID();
	tissue=rhs.GetTissue();
	vector<Wall*> temp=rhs.GetCellWall();
	if (walls.size()!=0)
	{
		for (int i=0;i<walls.size();i++)
		{
			delete walls[i];
		}
	}
	for (int i=0;i<temp.size();i++)
	{
		walls.push_back(temp[i]->Clone());
	}
	}
	return *this;
}



Cell::Cell(int id1,const vector<Wall*>& temp,Tissue* tissue1){
	id=id1;
	tissue=tissue1;
	for (int i=0;i<temp.size();i++)
	{
		walls.push_back(temp[i]->Clone());
	}
}





Cell::Cell(const Cell& rhs){
	id=rhs.GetCellID();
	tissue=rhs.GetTissue();
	vector<Wall*> temp=rhs.GetCellWall();
	if (walls.size()!=0)
	{
		for (int i=0;i<walls.size();i++)
		{
			delete walls[i];
		}
	}
	for (int i=0;i<temp.size();i++)
	{
		walls.push_back(temp[i]->Clone());
	}
}



int Cell::GetCellID() const {
	return id;
}



Tissue* Cell::GetTissue() const {
	return tissue;
}




const vector<Wall*>& Cell::GetCellWall() const {
	return walls;
}




void Cell::RenewCellWall(vector<Wall*>& rhs) {
	for (int i=0;i<walls.size();i++)
	{
		delete walls[i];
	}
	walls.clear();
	walls=rhs;
}




Cell::~Cell() {
	tissue=NULL;
	id=-1;
	if (walls.size()!=0)
	{
		for (int i=0;i<walls.size();i++)
		{
			delete walls[i];
			walls[i]=NULL;
		}
		walls.clear();
	}
}







ostream& operator<<(ostream& os,const Cell& rhs){
	vector<Wall*> temp=rhs.GetCellWall();
	if (temp.size()!=0)
	{	
		int i=0;
		for (;i<temp.size()-1;i++)
		{
			os<<((temp[i])->GetInitialParticle());
			os<<" "<<"-"<<" ";
		}
		os<<((temp[i])->GetInitialParticle());
	}
	return os;
}
	







void Cell::StrengthenCellWall() {
    int i = 0;
    int size = walls.size();
    if (size > 1) {
        i = 0;
        while (i < size-1) {
            try {
                const Wall *tmpWall = &(*walls[i] + *walls[i+1]);
                delete walls[i];
                delete walls[i+1];
                walls[i % size] = (Wall *) tmpWall;
                walls.erase(walls.begin() + i+1);
                size--;
            } catch(ApplePearException e) {
                i++;
            }
            if (size <= 1) break;
        }
    }
    if (size > 1) {
        try {
            const Wall *tmpWall = &(*walls[size-1] + *walls[0]);
            delete walls[size-1];
            delete walls[0];
            walls[0] = (Wall *) tmpWall;
            walls.erase(walls.end()-1);
            size--;
        } catch(ApplePearException e) {
            return;
        }
    }
    return;
}






		




























































