/**
 * @file 
 * OSGPointCloudVisualizer.cpp
 *
 * @date: Nov 23, 2009
 * @author: sblume
 */

#ifdef BRICS_OSG_ENABLE

#include "OSGPointCloudVisualizer.h"

namespace BRICS_3D {

OSGPointCloudVisualizer::OSGPointCloudVisualizer() {
	rootGeode = new osg::Group();
	viewer.setSceneData(rootGeode);
}

OSGPointCloudVisualizer::~OSGPointCloudVisualizer() {

}

struct DrawCallback: public osg::Drawable::DrawCallback {

	DrawCallback() :
		_firstTime(true) {
	}

	virtual void drawImplementation(osg::RenderInfo& renderInfo, const osg::Drawable* drawable) const {
		osg::State& state = *renderInfo.getState();

		if (!_firstTime) {
			_previousModelViewMatrix = _currentModelViewMatrix;
			_currentModelViewMatrix = state.getModelViewMatrix();
			_inverseModelViewMatrix.invert(_currentModelViewMatrix);

			osg::Matrix T(_previousModelViewMatrix * _inverseModelViewMatrix);

			osg::Geometry * geometry = dynamic_cast<osg::Geometry*> (const_cast<osg::Drawable*> (drawable));
			osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*> (geometry->getVertexArray());
			for (unsigned int i = 0; i + 1 < vertices->size(); i += 2) {
				(*vertices)[i + 1] = (*vertices)[i] * T;
			}
		} else {
			_currentModelViewMatrix = state.getModelViewMatrix();
		}

		_firstTime = false;

		drawable->drawImplementation(renderInfo);
	}

	mutable bool _firstTime;
	mutable osg::Matrix _currentModelViewMatrix;
	mutable osg::Matrix _inverseModelViewMatrix;
	mutable osg::Matrix _previousModelViewMatrix;
};

void OSGPointCloudVisualizer::addPointCloud(PointCloud3D* pointCloud, float red, float green, float blue, float alpha) {
	rootGeode->addChild(createPointCloudNode(pointCloud, red, green, blue, alpha));
}

void OSGPointCloudVisualizer::visualizePointCloud(PointCloud3D *pointCloud, float red, float green, float blue, float alpha)
{
	rootGeode->addChild(createPointCloudNode(pointCloud, red, green, blue, alpha));
	//viewer.setSceneData(createPointCloudNode(pointCloud));
	viewer.run(); // run();
}

osg::Node* OSGPointCloudVisualizer::createPointCloudNode(PointCloud3D* pointCloud, float red, float green, float blue, float alpha) {

	unsigned int targetNumVertices = 10000; //maximal points per geode

	osg::Geode* geode = new osg::Geode;
	osg::Geometry* geometry = new osg::Geometry;

	osg::Vec3Array* vertices = new osg::Vec3Array;
	//osg::Vec3Array* normals = new osg::Vec3Array;
	//osg::Vec4ubArray* colours = new osg::Vec4ubArray; //every point has color
	osg::Vec4Array* colours = new osg::Vec4Array(1); //all point have same color
	(*colours)[0].set(red, green, blue, alpha); //set colours (r,g,b,a)

	vertices->reserve(targetNumVertices);
	//normals->reserve(targetNumVertices);
	colours->reserve(targetNumVertices);

	//feed point cloud into osg "geode(s)"
	unsigned int j = 0;
	unsigned int i = 0;
	for (i = 0; i < pointCloud->getSize(); ++i, j += 2) {

		osg::Vec3 tmpPoint;
		tmpPoint.set((float) ((*pointCloud->getPointCloud())[i].x), (float) ((*pointCloud->getPointCloud())[i].y),
				(float) ((*pointCloud->getPointCloud())[i].z));
		vertices->push_back(tmpPoint);

		/*
		 * If geode gets bigger than 10000 (targetNumVertices) points than create a new child node.
		 * This is necessary to improve the performance due to graphics adapter internals.
		 */
		if (vertices->size() >= targetNumVertices) {
			// finishing setting up the current geometry and add it to the geode.
			geometry->setUseDisplayList(true);
			geometry->setUseVertexBufferObjects(true);
			geometry->setVertexArray(vertices);
			//geometry->setNormalArray(normals);
			//geometry->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);
			geometry->setColorArray(colours);
			geometry->setColorBinding(osg::Geometry::BIND_OVERALL);

			geometry->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices->size()));

			geode->addDrawable(geometry);

			// allocate a new geometry
			geometry = new osg::Geometry;

			vertices = new osg::Vec3Array;
			//normals = new osg::Vec3Array;
			//colours = new osg::Vec4ubArray;

			vertices->reserve(targetNumVertices);
			//normals->reserve(targetNumVertices);
			//colours->reserve(targetNumVertices);

		}

	}

	geometry->setUseDisplayList(true);
	geometry->setVertexArray(vertices);
	geometry->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices->size()));
	geometry->setColorArray(colours);
	geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	geometry->setDrawCallback(new DrawCallback);

	geode->addDrawable(geometry);
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	osg::Group* group = new osg::Group;
	group->addChild(geode);

	return group;
}

}

#endif //BRICS_OSG_ENABLE

/* EOF */