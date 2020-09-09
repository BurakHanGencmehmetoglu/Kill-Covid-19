#include "MicroOrganism.h"





MicroOrganism::MicroOrganism() {
	id=-1;
	located=false;
	connection=NULL;
}





MicroOrganism::MicroOrganism(int id1,const vector<Wall*>& temp) {
	id=id1;
	cout<<321321321;
	for (int i=0;i<temp.size();i++)
	{
		edge.push_back(temp[i]->Clone());
	}
	located=false;
	connection=NULL;
}





ostream& operator<<(ostream& os,const MicroOrganism& rhs){
	if (rhs.located)
	{
		os<<"The microorganism ";
		os<<rhs.id;
		os<<" was successfully placed into the cell"<<(rhs.connection)->GetCellID();
		os<<".";
	}
	else
	{
		os<<"The microorganism "<<rhs.id<<" could not be placed into any cell!";
	}
	return os;
}




MicroOrganism::~MicroOrganism() {
	if (connection!=NULL){delete connection;}
	for (int i=0;i<edge.size();i++)
	{
		delete edge[i];
	}
	edge.clear();
}	

