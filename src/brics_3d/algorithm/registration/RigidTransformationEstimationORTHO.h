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

#ifndef BRICS_3D_RIGIDTRANSFORMATIONESTIMATIONORTHO_H_
#define BRICS_3D_RIGIDTRANSFORMATIONESTIMATIONORTHO_H_

#include "IRigidTransformationEstimation.h"

namespace brics_3d {

/**
 * @ingroup registration
 * @brief Implementation of rigid transformation estimation between two corresponding point clouds.
 *
 * This implementation uses a ORTHO TODO based error function for the ICP.
 */
class RigidTransformationEstimationORTHO: public brics_3d::IRigidTransformationEstimation {
public:

	/**
	 * Standard constructor
	 */
	RigidTransformationEstimationORTHO();

	/**
	 * Standard destructor
	 */
	virtual ~RigidTransformationEstimationORTHO();

	double estimateTransformation(std::vector<CorrespondencePoint3DPair>* pointPairs, IHomogeneousMatrix44* resultTransformation);

};

}

#endif /* BRICS_3D_RIGIDTRANSFORMATIONESTIMATIONORTHO_H_ */

/* EOF */
