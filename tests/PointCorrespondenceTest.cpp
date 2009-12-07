/**
 * @file 
 * PointCorrespondenceTest.cpp
 *
 * @date: Dec 4, 2009
 * @author: sblume
 */

#include "PointCorrespondenceTest.h"

#include <sstream>

using namespace std;
using namespace Eigen;
using namespace BRICS_3D;

namespace unitTests {

CPPUNIT_TEST_SUITE_REGISTRATION( PointCorrespondenceTest );

void PointCorrespondenceTest::setUp() {
	pointCloudCube = new PointCloud3D();

	point000 = new Point3D(0,0,0);
	point001 = new Point3D(0,0,1);
	point011 = new Point3D(0,1,1);
	point010 = new Point3D(0,1,0);
	point100 = new Point3D(1,0,0);
	point101 = new Point3D(1,0,1);
	point111 = new Point3D(1,1,1);
	point110 = new Point3D(1,1,0);

	pointCloudCube->addPoint(point000);
	pointCloudCube->addPoint(point001);
	pointCloudCube->addPoint(point011);
	pointCloudCube->addPoint(point010);
	pointCloudCube->addPoint(point100);
	pointCloudCube->addPoint(point101);
	pointCloudCube->addPoint(point111);
	pointCloudCube->addPoint(point110);

	pointCloudCubeCopy = new PointCloud3D();
	stringstream tmpSteam;
	tmpSteam << *pointCloudCube;
	tmpSteam >> *pointCloudCubeCopy;
}
void PointCorrespondenceTest::tearDown() {
	delete pointCloudCube;
	delete pointCloudCubeCopy;
}

void PointCorrespondenceTest::testConstructor() {

	CPPUNIT_ASSERT(assigner == 0);
	assigner = new PointCorrespondenceKDTree();
	CPPUNIT_ASSERT(assigner != 0);

	/* polymorph variant */
	CPPUNIT_ASSERT(abstractAssigner == 0);
	abstractAssigner = new PointCorrespondenceKDTree();
	CPPUNIT_ASSERT(abstractAssigner != 0);

}

void PointCorrespondenceTest::testSimpleCorrespondence() {

	/* manipulate second point cloud */
	AngleAxis<double> rotation(M_PI_2l/4.0, Vector3d(1,0,0));
	Transform3d transformation;
	transformation = rotation;
	IHomogeneousMatrix44* homogeneousTrans = new HomogeneousMatrix44(&transformation);
	pointCloudCubeCopy->homogeneousTransformation(homogeneousTrans);

	cout << "pc1" << endl;
	cout << *pointCloudCube << endl << endl;

	cout << "pc2" << endl;
	cout << *pointCloudCubeCopy	 << endl;

	assigner = new PointCorrespondenceKDTree();
	vector<CorrespondencePoint3DPair>* pointPairs = new vector<CorrespondencePoint3DPair>();
	assigner->createNearestNeighborCorrespondence(pointCloudCube, pointCloudCubeCopy, pointPairs);


	CPPUNIT_ASSERT_EQUAL((int)pointCloudCube->getSize(), (int)pointPairs->size());
	for (int i = 0;  i < pointPairs->size(); ++ i) {

		cout << "Point 1: " << (*pointPairs)[i].firstPoint
				<< ", Point 2 " << (*pointPairs)[i].secondPoint << endl;
		/*
		 * expectation as the same point cloud is used:
		 * direct correspondence from one cloud the other
		 */
		//CPPUNIT_ASSERT_EQUAL(0, (int)(*pointPairs)[i].firstIndex);
		CPPUNIT_ASSERT_DOUBLES_EQUAL((int)(*pointCloudCube->getPointCloud())[i].x, (int)(*pointPairs)[i].firstPoint.x, maxTolerance);
		CPPUNIT_ASSERT_DOUBLES_EQUAL((int)(*pointCloudCubeCopy->getPointCloud())[i].x, (int)(*pointPairs)[i].secondPoint.x, maxTolerance);

		CPPUNIT_ASSERT_DOUBLES_EQUAL((int)(*pointCloudCube->getPointCloud())[i].y, (int)(*pointPairs)[i].firstPoint.y, maxTolerance);
		CPPUNIT_ASSERT_DOUBLES_EQUAL((int)(*pointCloudCubeCopy->getPointCloud())[i].y, (int)(*pointPairs)[i].secondPoint.y, maxTolerance);

		CPPUNIT_ASSERT_DOUBLES_EQUAL((int)(*pointCloudCube->getPointCloud())[i].z, (int)(*pointPairs)[i].firstPoint.z, maxTolerance);
		CPPUNIT_ASSERT_DOUBLES_EQUAL((int)(*pointCloudCubeCopy->getPointCloud())[i].z, (int)(*pointPairs)[i].secondPoint.z, maxTolerance);

	}



	/* test with index based association */
//	vector<CorrespondenceIndexPair>* pointPairs = new vector<CorrespondenceIndexPair>();
//	assigner->createNearestNeighborCorrespondence(pointCloudCube, pointCloudCubeCopy, pointPairs);
//
//	CPPUNIT_ASSERT_EQUAL((int)pointCloudCube->getSize(), (int)pointPairs->size());
//	for (int i = 0;  i < pointPairs->size(); ++ i) {
//
//		cout << "Pair: " << (int)(*pointPairs)[i].firstIndex
//				<< ", " << (int)(*pointPairs)[i].secondIndex << endl;
//		/*
//		 * expectation as the same point cloud is used:
//		 * direct correspondence from one cloud the other
//		 */
//		//CPPUNIT_ASSERT_EQUAL(0, (int)(*pointPairs)[i].firstIndex);
//		CPPUNIT_ASSERT_EQUAL(i, (int)(*pointPairs)[i].firstIndex);
//	    CPPUNIT_ASSERT_EQUAL(i, (int)(*pointPairs)[i].secondIndex);
//
//	}

//	CPPUNIT_ASSERT(false);
}

}
/* EOF */
