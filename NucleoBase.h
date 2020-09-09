#ifndef NUCLEOBASE_H
#define NUCLEOBASE_H

#include <iostream>
class Triangular;
using namespace std;

class NucleoBase {
	/* This class represents RNA and will
		be used only by Triangular microorganisms */
	friend class Triangular;

	private:
		string chain;
		NucleoBase* prev; 	            
		NucleoBase();
	public:		

		/*********************************************************************
		*									Constructor
		*
		* The first @param is the whole RNA sequence
		* The second parameter is a NucleoBase pointer addressing the previous
		  NucleoBase object. For the initial nucleobase this is NULL.
		*/
		NucleoBase(string, NucleoBase*);
		/*********************************************************************
		*								Copy Constructor
		*
		* Deep copy
		*/
		NucleoBase(const NucleoBase&);
		/*********************************************************************
		*									Destructor
		*
		*/
		~NucleoBase();
		/*********************************************************************
		*									GetLast
		*
		* @return pointer to the last element of NucleoBase chain.
		*/
		NucleoBase* GetLast();
		/*********************************************************************
		*									Stream Operator
		* Prints the data in NucleoBase chain.
		* Prints the char data of each NucleoBase object starting from the
		  given NucleoBase in the @param upto the last element of the chain.
		*/
		friend ostream& operator<<(ostream&, const NucleoBase&);
		/********************************************************************/
};

#endif
