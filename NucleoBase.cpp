#include "NucleoBase.h"





NucleoBase::NucleoBase() {
	prev=NULL;
	chain="";
}




NucleoBase::NucleoBase(string chain1,NucleoBase* ptr) {
	chain=chain1;
	prev=ptr;
}



NucleoBase::~NucleoBase() {
	if (prev!=NULL){delete prev;}
}
		



NucleoBase* NucleoBase::GetLast() {
	string temp(1,chain[chain.length()-1]);
	NucleoBase *temp1= new NucleoBase(temp,NULL);
	return temp1;
}




ostream& operator<<(ostream& os,const NucleoBase& rhs){
	string temp=rhs.chain;
	for (int i=0;i<temp.length();i++)
	{
		os<<temp[i];
	}
	return os;
}


NucleoBase::NucleoBase(const NucleoBase& rhs) {
	prev=NULL;
	chain=rhs.chain;
}

