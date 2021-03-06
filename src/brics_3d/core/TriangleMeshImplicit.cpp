/******************************************************************************
* BRICS_3D - 3D Perception and Modeling Library
* Copyright (c) 2011, GPS GmbH
*
* Author: Sebastian Blumenthal
*
*
* This software is published under a dual-license: GNU Lesser General Public
* License LGPL 2.1 and Modified BSD license. The dual-license implies that
* users of this code may choose which terms they prefer.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License LGPL and the BSD license for
* more details.
*
******************************************************************************/

#include "TriangleMeshImplicit.h"
#include "assert.h"

namespace brics_3d {

TriangleMeshImplicit::TriangleMeshImplicit() {
	vertices = new std::vector<Point3D> ();
	vertices->clear();

	indices =  new std::vector<int> ();
	indices->clear();
}

TriangleMeshImplicit::~TriangleMeshImplicit() {
	if (vertices != NULL) {
		vertices->clear();
		delete vertices;
	}
	if (indices != NULL) {
		indices->clear();
		delete indices;
	}
}


std::vector<Point3D>* TriangleMeshImplicit::getVertices() {
	return vertices;
}


void TriangleMeshImplicit::setVertices(std::vector<Point3D>* vertices) {
	if (this->vertices != NULL) {
		this->vertices->clear();
		delete this->vertices;
	}
	this->vertices = vertices;
}


std::vector<int>* TriangleMeshImplicit::getIndices() {
	return indices;
}


void TriangleMeshImplicit::setIndices(std::vector<int>* indices) {
	if (this->indices != NULL) {
		this->indices->clear();
		delete this->indices;
	}
	this->indices = indices;
}


int TriangleMeshImplicit::getSize() {
	assert((static_cast<int>(indices->size()) % 3) == 0); //plausibility check if index triples are consistent
	return (static_cast<int>(indices->size()) / 3);
}

int TriangleMeshImplicit::getNumberOfVertices() {
	return (static_cast<int>(vertices->size()));
}

Point3D* TriangleMeshImplicit::getTriangleVertex(int triangleIndex, int vertexIndex) {
	/* check if parameters are in range */
	assert ((0 <= triangleIndex) && (triangleIndex < this->getSize()));
	assert ((0 <= vertexIndex) && (vertexIndex <= 2));

	return &((*vertices)[triangleIndex + vertexIndex]);
}

int TriangleMeshImplicit::addTriangle(Point3D vertex1, Point3D vertex2, Point3D vertex3) {
	assert((static_cast<int>(indices->size()) % 3) == 0); //postcondition

	/* append at end */
	vertices->push_back(vertex1); //TODO: check for duplication?
	indices->push_back(static_cast<int>(vertices->size())); // important: must follow a vertices->push_back()
	vertices->push_back(vertex2);
	indices->push_back(static_cast<int>(vertices->size())); // important: must follow a vertices->push_back()
	vertices->push_back(vertex3);
	indices->push_back(static_cast<int>(vertices->size())); // important: must follow a vertices->push_back()

	assert((static_cast<int>(indices->size()) % 3) == 0); //precondition
	return this->getSize();
}

void TriangleMeshImplicit::removeTriangle (int triangleIndex) {
	assert (false);//TODO: implement
	assert((static_cast<int>(indices->size()) % 3) == 0); //plausibility check if index triples are consistent
}

void TriangleMeshImplicit::homogeneousTransformation(IHomogeneousMatrix44 *transformation) {
	for (int i = 0; i < static_cast<int>(vertices->size()); ++i) { // propagate transformation to triangles
		(*vertices)[i].homogeneousTransformation(transformation);
	}
}

void TriangleMeshImplicit::read(std::istream& inStream) {

}

void TriangleMeshImplicit::write(std::ostream& outStream) {
	for (int i = 0; i < this->getSize(); ++i) {
		outStream << (*vertices)[i] << std::endl;
	}
	for (int i = 0; i < static_cast<int>(indices->size()); ++i) {
		outStream << (*indices)[3*i] << ", ";
		outStream << (*indices)[3*i + 1] << ", ";
		outStream << (*indices)[3*i + 2] << std::endl;
	}
}

}

/* EOF */
