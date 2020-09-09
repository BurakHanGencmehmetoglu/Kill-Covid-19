There are two main classes which are MicroOrganism and Cell classes.

Each microorganism will have circular or triangular shape.

Initially, we will accept them as a microorganism, and we will implement them with inheritance.

Cells can be any type.We will match cells and microorganisms if they have the same size and shape.

If cells and microorganisms are matched,each microorganism will have different effect on cells.

We will use wall class to define shape of cells.Cells can have many walls.

Walls consist of two particles where one of them represents start point,and another represents end point.

For circular segments, there is CurvyWall class which is inherited from Wall class.

As well as start and end points, there is a third point which represents center of the circular segment in CurvyWall class.

Finally, there is Tissue class where we hold cells.

Detailed explanations can be found in '.h' files. 
