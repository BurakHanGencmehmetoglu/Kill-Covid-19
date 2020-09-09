#include "Triangular.h"





void selectionsort(float a[], int n) {
   int i, j, min; 	
   float temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (a[j] < a[min])
            min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}




Triangular::Triangular()
{
	rna=NULL;
	id=-1;
	located=false;
	connection=NULL;
}




Triangular::Triangular(int id1,const vector<Wall*>& temp,const NucleoBase& RNA) {
	rna = new NucleoBase(RNA.chain,NULL);	
	id=id1;
	for (int i=0;i<3;i++)
	{
		edge.push_back(temp[i]->Clone());
	}
	located=false;
	connection=NULL;
}





Triangular::~Triangular() {
 	connection=NULL;
	delete rna;
	for (int i=0;i<edge.size();i++)
	{
		delete edge[i];
	}
	rna=NULL;			       
        edge.clear();
}




void Triangular::ConnectToCell(Cell* const cell) {
	for (int i=0;i<edge.size();i++)
	{
		delete edge[i];
	}
	edge.clear();
	connection=cell;
	vector<Wall*> temp=cell->GetCellWall();
	for (int i=0;i<temp.size();i++)
	{
		edge.push_back(temp[i]->Clone());
	}
	located=true;
	return;
}





bool Triangular::DoesFitInto(const Cell& rhs) const {
	Cell clone(rhs);
	clone.StrengthenCellWall();
	vector<Wall*> temp=clone.GetCellWall();
	if (temp.size()!=3){return false;}
	else
	{
		float* arr= new float[3];
		for (int i=0;i<3;i++)
		{
			arr[i]=(temp[i])->GetLength();
		}
		selectionsort(arr,3);
		float* arr2=new float[3];
		for (int i=0;i<3;i++)
		{
			arr2[i]=(edge[i])->GetLength();
		}
		selectionsort(arr2,3);
		for (int i=0;i<3;i++)
		{
			if (abs(arr[i]-arr2[i])<EPSILON){continue;}
			else
			{
				delete [] arr;
				delete [] arr2;
				return false;
			}
		}
		delete [] arr;
		delete [] arr2;
		return true;
	}
}





void Triangular::React(){
	if (connection!=NULL)
		{
			Tissue* tissue=connection->GetTissue();
			tissue->RemoveCell(*connection);
			connection=NULL;
		}
	
}





const NucleoBase& Triangular::GetRNA() const {
	return *rna;
}





void Triangular::Mutate(Triangular& rhs) {
        string rna1=(*this).GetRNA().chain;
	string rna2=rhs.GetRNA().chain;
	int length=rna1.length();
	int i=0,k=length-1;
        string ad="A";
        string ur="U";
        string gu="G";
        string st="S";
        char A=ad[0];;
        char G=gu[0];
        char U=ur[0];
        char S=st[0];
        for (;;)
        {
                char rn1=rna1[i];
                char rn2=rna2[i];
                char rn3=rna1[k];
                char rn4=rna2[k];
                if (rn1==rn2){i++;}
                if (rn3==rn4){k--;}
		else  if (rn1!=rn2 && rn3!=rn4){break;}
        }
        for (;i<=k;i++)
        {
                char rn1=rna1[i];
                char rn2=rna2[i];
                if (rn1==G && rn2==S)
                {
                        rna1.replace(i,1,"S");
                        rna2.replace(i,1,"G");
                }
                else if (rn1==S && rn2==G)
                {
                        rna1.replace(i,1,"G");
                        rna2.replace(i,1,"S");
                }
                else if (rn1==A && rn2==U)
                {
                        rna1.replace(i,1,"U");
                        rna2.replace(i,1,"A");
                }
                else if (rn1==U && rn2==A)
                {
                        rna1.replace(i,1,"A");
                        rna2.replace(i,1,"U");
                }
                else
                {
                        rna1.replace(i,1,"x");
                        rna2.replace(i,1,"x");
                }
        }
        string sonuc="";
	string sonuc2="";
        length=rna1.length();
        for (i=0;i<length;i++)
        {
 	    char temp=rna1[i];
	    char temp2=rna2[i];
            if (temp=='x'){continue;}
            else 
            {
		sonuc2.push_back(temp2);    
                sonuc.push_back(temp);
            }
        }
	delete rna;
	rna=new NucleoBase(sonuc,NULL);	
	return ;
}
