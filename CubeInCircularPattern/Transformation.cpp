
#include <iostream>
#include "Transformation.h"
#include "Solid.h"
#include "Point.h"
#include "Vector.h"


Solid Transformation:: translateSolidVertexAlongVector(Solid &firstSolid, Vector  &unitVector,
	                                  int &noOfvertices, int &noOfFacets, float &radius)
{
	Solid instanceSolid;
	               //  along the unitvectors calculated before at particular radius
		for (int i = 0; i < noOfvertices; i++)
		{
			Point newPoint;
			newPoint = firstSolid.getFacetVertex(i);
			newPoint = (unitVector * radius) + newPoint;
			instanceSolid.setFacetVertex(newPoint);
		}
		if (firstSolid.noOfNormals() != 0)
		{
			for (int i = 0; i < noOfFacets; i++)
			{
				Point newNormal;
				newNormal = firstSolid.getFacetNormal(i);
				newNormal = unitVector * radius + newNormal;
				instanceSolid.setFacetNormal(newNormal);
			}
		}

	return instanceSolid;
}