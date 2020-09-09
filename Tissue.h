#ifndef TISSUE_H
#define TISSUE_H

#include "MicroOrganism.h"
#include <fstream>
#include <string>
#include <vector>
class Tissue {

	private: 
			float minx;
			float maxx;
			float miny;
			float maxy;
			vector<Cell*> cells;

	public:		

		/*********************************************************************
		*									Constructor
		*
		*/
		Tissue();
		/*********************************************************************
		*									Constructor
		*
		* The first @param is the minimum x border
		* The second @param is the maximum x border
		* The third @param is the minimum y border
		* The fourth @param is the maximum y border
		* The tissue is the region residing among those coordinates.
		*/
		Tissue(float, float, float, float);
		/*********************************************************************
		*								Copy Constructor
		*
		* Shallow copy
		*/
		Tissue(const Tissue&);
		/*********************************************************************
		*									Destructor
		*
		*/
		~Tissue();
		/*********************************************************************
		*									GetCoordinates
		*
		* @return the coordinates of minimum x border, maximum x border,
		  minimum y border and maximum y border in an array with the stated
			order.
		*/
		float* GetCoordinates();
		/*********************************************************************
		*									AddCell
		*
		* Adds the actual reference of the cell given in the @param to storage
		  of cells belonging to this Tissue object.
		*/
		void AddCell(Cell&);
		/*********************************************************************
		*									RemoveCell
		*
		* Deletes the cell given in the @param and removes it from the storage
		  of cells belonging to this Tissue object.
		* Do the necessary operation that your own implementation requires.
		*/
		void RemoveCell(Cell&);
		/*********************************************************************
		*									GetCell
		*
		* @return the cell whose id is given in the @param
		* If the cell whose id is given does not exit, in other words it is a
		  dead cell, then the method should throw DeadCellException which was
			defined in Exception.h.
		*/
		const Cell& GetCell(int) const;
		/*********************************************************************
		*									Interact
		*
		* This method makes the cells interacting with the microorganisms in
		  the @param. For each microorganism a compatible cell is found.
		  Input will be given satisfying that each microorganism fits into a cell.
		*/
		void Interact(const vector<MicroOrganism*>&);
};

#endif
