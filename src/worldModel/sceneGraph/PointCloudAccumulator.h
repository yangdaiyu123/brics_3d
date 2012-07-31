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

#ifndef POINTCLOUDACCUMULATOR_H_
#define POINTCLOUDACCUMULATOR_H_

#include "Node.h"
#include "Group.h"
#include "Transform.h"
#include "GeometricNode.h"
#include "INodeVisitor.h"

#include "core/PointCloud3DIterator.h"

namespace BRICS_3D {

namespace RSG {

class PointCloudAccumulator : public INodeVisitor {
public:
	PointCloudAccumulator(Node::NodePtr referenceNode);
	virtual ~PointCloudAccumulator();

	virtual void visit(Node* node);
	virtual void visit(Group* node);
	virtual void visit(Transform* node);
	virtual void visit(GeometricNode* node);

	virtual void reset();

	IPoint3DIterator* getAccumulatedPointClouds () {
		return accumulatedPointClouds;
	}

protected:

	PointCloud3DIterator* accumulatedPointClouds;
	Node::NodePtr referenceNode;

};

}

}

#endif /* POINTCLOUDACCUMULATOR_H_ */

/* EOF */