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

#ifndef OSGVISUALIZER_H_
#define OSGVISUALIZER_H_

#include "ISceneGraphUpdateObserver.h"
#include "worldModel/sceneGraph/PointCloud.h"
#include "util/OSGPointCloudVisualizer.h" //unfortunately libbrics3d_world_model depends now on libbrics3d_util

#include <map>

namespace BRICS_3D {

namespace RSG {


/**
 * @brief Displays a robot scene graph via OSG
 * @ingroup visualization
 */
class OSGVisualizer : public ISceneGraphUpdateObserver {
public:
	OSGVisualizer();
	virtual ~OSGVisualizer();

	/* implemetntations of observer interface */
	bool addNode(unsigned int parentId, unsigned int& assignedId, vector<Attribute> attributes);
	bool addGroup(unsigned int parentId, unsigned int& assignedId, vector<Attribute> attributes);
	bool addTransformNode(unsigned int parentId, unsigned int& assignedId, vector<Attribute> attributes, IHomogeneousMatrix44::IHomogeneousMatrix44Ptr transform, TimeStamp timeStamp);
	bool addGeometricNode(unsigned int parentId, unsigned int& assignedId, vector<Attribute> attributes, Shape::ShapePtr shape, TimeStamp timeStamp);
	bool setNodeAttributes(unsigned int id, vector<Attribute> newAttributes);
	bool setTransform(unsigned int id, IHomogeneousMatrix44::IHomogeneousMatrix44Ptr transform, TimeStamp timeStamp);
	bool deleteNode(unsigned int id);
	bool addParent(unsigned int id, unsigned int parentId);

    /**
     * Return true if  viewer's work is done and should exit the frame loop.
     */
    bool done();


private:

    ///Internal initialization
	void init();

	/// Viewer will get its own thread such that visialization does not block the main program.
	void threadFunction(OSGVisualizer* obj);

    unsigned int getRootId();

    osg::ref_ptr<osg::Node> findNodeRecerence(unsigned int id);

	/// OSG viewer object
	osgViewer::Viewer viewer;

	/// Root node for scenegraph
	osg::ref_ptr<osg::Group> rootGeode;

	/// Thread handle for visualization thread
	boost::thread* thread;

	///Grant helper classes full access
	friend class OSGOperationAdd;

	///ID management for OSG
    std::map<unsigned int, osg::ref_ptr<osg::Node> > idLookUpTable;
    std::map<unsigned int, osg::ref_ptr<osg::Node> >::const_iterator nodeIterator;




};

}  // namespace RSG

}  // namespace BRICS_3D

#endif /* OSGVISUALIZER_H_ */

/* EOF */