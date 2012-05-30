/**
 * @file 
 * ColoredPointCloud3DTest.cpp
 *
 * @date: Dec 22, 2009
 * @author: sblume
 */

#include "ColoredPointCloud3DTest.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

#include "core/HomogeneousMatrix44.h"

namespace unitTests {

CPPUNIT_TEST_SUITE_REGISTRATION( ColoredPointCloud3DTest );

void ColoredPointCloud3DTest::setUp() {
	pointCloudCube = new ColoredPointCloud3D();

	point000 = new ColoredPoint3D(new Point3D(0,0,0),1,1,1);
	point001 = new ColoredPoint3D(new Point3D(0,0,1),1,1,1);
	point011 = new ColoredPoint3D(new Point3D(0,1,1),1,1,1);
	point010 = new ColoredPoint3D(new Point3D(0,1,0),1,1,1);
	point100 = new ColoredPoint3D(new Point3D(1,0,0),1,1,1);
	point101 = new ColoredPoint3D(new Point3D(1,0,1),1,1,1);
	point111 = new ColoredPoint3D(new Point3D(1,1,1),1,1,1);
	point110 = new ColoredPoint3D(new Point3D(1,1,0),1,1,1);

	pointCloudCube->addPoint(point000);
	pointCloudCube->addPoint(point001);
	pointCloudCube->addPoint(point011);
	pointCloudCube->addPoint(point010);
	pointCloudCube->addPoint(point100);
	pointCloudCube->addPoint(point101);
	pointCloudCube->addPoint(point111);
	pointCloudCube->addPoint(point110);
}

void ColoredPointCloud3DTest::tearDown() {
	delete point000;
	delete point001;
	delete point011;
	delete point010;
	delete point100;
	delete point101;
	delete point111;
	delete point110;

	delete pointCloudCube;
//	delete pointCloudCubeCopy;
}

void ColoredPointCloud3DTest::testConstructor() {

	CPPUNIT_ASSERT_EQUAL(8u, pointCloudCube->getSize());

	/* check copy constructor */
	pointCloudCubeCopy = new ColoredPointCloud3D(*pointCloudCube);
	CPPUNIT_ASSERT_EQUAL(8u, pointCloudCubeCopy->getSize());
}

void ColoredPointCloud3DTest::testContent() {
	ColoredPoint3D resultPoint(new Point3D());

	/* check all points in cloud */
	resultPoint = (*pointCloudCube->getPointCloud())[0];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[1];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[2];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[3];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[4];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[5];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[6];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[7];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	pointCloudCube->getPointCloud()->clear();
	CPPUNIT_ASSERT_EQUAL(0u, pointCloudCube->getSize());
}

void ColoredPointCloud3DTest::testLimits() {
	pointCloudCubeCopy = new ColoredPointCloud3D;
	int limit = (int)(*pointCloudCubeCopy->getPointCloud()).max_size();

	/*
	 * ugly for loop but it ensures exception is at some place thrown as
	 * the max_size(); gives only the potential maximum
	 */
	CPPUNIT_ASSERT_THROW(for(int i = 0; i <= limit; i++) pointCloudCubeCopy->addPoint(*point111), bad_alloc);
}

void ColoredPointCloud3DTest::testStreaming() {
	string comparatorString;
	string referenceString = "0 0 0 1 1 1\n0 0 1 1 1 1\n0 1 1 1 1 1\n0 1 0 1 1 1\n1 0 0 1 1 1\n1 0 1 1 1 1\n1 1 1 1 1 1\n1 1 0 1 1 1\n";
	stringstream testStringStream0;
	ColoredPoint3D resultPoint(new Point3D());

	/* check all points in cloud */
	resultPoint = (*pointCloudCube->getPointCloud())[0];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[1];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[2];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[3];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[4];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[5];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[6];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);

	resultPoint = (*pointCloudCube->getPointCloud())[7];
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, resultPoint.getZ(), maxTolerance);
	CPPUNIT_ASSERT(resultPoint.red == 1);
	CPPUNIT_ASSERT(resultPoint.green == 1);
	CPPUNIT_ASSERT(resultPoint.blue == 1);
	stringstream testStringStream1;
	stringstream testStringStream2;

	/* test output */
	testStringStream0 << *pointCloudCube;
	comparatorString = testStringStream0.str();
//	cout << "RGB pointCloudCube:" << endl << *pointCloudCube;
	CPPUNIT_ASSERT_EQUAL(0, comparatorString.compare(referenceString));

	/* test input */
	pointCloudCubeCopy = new ColoredPointCloud3D();
	CPPUNIT_ASSERT_EQUAL(0u, pointCloudCubeCopy->getSize());

	testStringStream0 >> *pointCloudCubeCopy;
	CPPUNIT_ASSERT_EQUAL(8u, pointCloudCubeCopy->getSize());

	/* check if input is same as reference */
	testStringStream1 << *pointCloudCubeCopy;
	comparatorString = testStringStream0.str();
	CPPUNIT_ASSERT_EQUAL(0, comparatorString.compare(referenceString));

	/* check if points are added */
	testStringStream1 >> *pointCloudCubeCopy;
	CPPUNIT_ASSERT_EQUAL(16u, pointCloudCubeCopy->getSize());
	//	cout << *point111 << endl; // actual

	/* check what happens if bad data is inserted */
	testStringStream2 << "1 2 3 1 1 1 5" << endl;
	testStringStream2 >> *pointCloudCubeCopy;
	CPPUNIT_ASSERT_NO_THROW((testStringStream2 >> *pointCloudCubeCopy));
	testStringStream2.clear();
	testStringStream2 << "5 6" << endl;
	CPPUNIT_ASSERT_THROW((testStringStream2 >> *pointCloudCubeCopy), runtime_error);

	//cout << *pointCloudCubeCopy;
}

void ColoredPointCloud3DTest::testTransformation() {

	/* rotate 90° about X */
//	AngleAxis<double> rotation(M_PI_2, Vector3d(1,0,0));
	AngleAxis<double> rotation(M_PI_2*0.389475, Vector3d(1,0,0)); // pvector pointCloudCube->getPointCloud()
	transformation = rotation;

	IHomogeneousMatrix44 *homogeneousTransformation = new HomogeneousMatrix44(&transformation);
	CPPUNIT_ASSERT_EQUAL(8u, pointCloudCube->getSize());
	pointCloudCube->homogeneousTransformation(homogeneousTransformation); //BUG here
	CPPUNIT_ASSERT_EQUAL(8u, pointCloudCube->getSize());

	/* check 90° rotation about X */
	Point3D resultPoint;
	Point3D referencePoint;

	resultPoint = (*pointCloudCube->getPointCloud())[0];
	referencePoint = Point3D(0,0,0);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	resultPoint = (*pointCloudCube->getPointCloud())[1];
	referencePoint = Point3D(0,0,1);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	resultPoint = (*pointCloudCube->getPointCloud())[2];
	referencePoint = Point3D(0,1,1);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	resultPoint = (*pointCloudCube->getPointCloud())[3];
	referencePoint = Point3D(0,1,0);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	resultPoint = (*pointCloudCube->getPointCloud())[4];
	referencePoint = Point3D(1,0,0);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	resultPoint = (*pointCloudCube->getPointCloud())[5];
	referencePoint = Point3D(1,0,1);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	resultPoint = (*pointCloudCube->getPointCloud())[6];
	referencePoint = Point3D(1,1,1);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	resultPoint = (*pointCloudCube->getPointCloud())[7];
	referencePoint = Point3D(1,1,0);
	referencePoint.homogeneousTransformation(homogeneousTransformation);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), resultPoint.getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), resultPoint.getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), resultPoint.getZ(), maxTolerance);

	delete homogeneousTransformation;

}

void ColoredPointCloud3DTest::testMassiveData() {
	int maxCount = 307200; //VGA resolution for realistic test
	int maxCaptures = 2;

	ColoredPointCloud3D* sensorData;
	for (int captures = 0; captures < maxCaptures; ++captures) {
		sensorData = new ColoredPointCloud3D();

		(*sensorData->getPointCloud()).resize(maxCount);
		for (int i = 0; i < static_cast<int>(sensorData->getPointCloud()->size()); i++) {
			//			outputPointCloud->addPoint(BRICS_3D::Point3D (inputPointCloud->points[i].x, inputPointCloud->points[i].y, inputPointCloud->points[i].z));
			(*sensorData->getPointCloud())[i].setX(1);
			(*sensorData->getPointCloud())[i].setY(2);
			(*sensorData->getPointCloud())[i].setZ(3);
			(*sensorData->getPointCloud())[i].setR(128);
			(*sensorData->getPointCloud())[i].setG(255);
			(*sensorData->getPointCloud())[i].setB(128);
		}
		CPPUNIT_ASSERT_EQUAL(maxCount, static_cast<int>(sensorData->getPointCloud()->size()));
		delete	sensorData;
	}

	ColoredPointCloud3D* sensorData2;
	for (int captures = 0; captures < maxCaptures; ++captures) {
		sensorData2 = new ColoredPointCloud3D();

		for (int i = 0; i < maxCount; i++) {
//			sensorData2->addPoint(ColoredPoint3D(new Point3D(1,2,3), 128, 255, 128)); //this will create a memory leak
			Point3D tmpPoint(1,2,3);
			sensorData2->addPoint(ColoredPoint3D(&tmpPoint, 128, 255, 128)); //this will not create a memory leak
		}
		CPPUNIT_ASSERT_EQUAL(maxCount, static_cast<int>(sensorData2->getPointCloud()->size()));
		delete	sensorData2;
	}
}

void ColoredPointCloud3DTest::testPolymorphPointCloud() {
	pointCloud = new PointCloud3D();
	Point3D* testPoint = new ColoredPoint3D(point110);
	pointCloud->addPointPtr(testPoint);
	pointCloud->addPointPtr(new Point3D(4,5,6)); //without decoration

	Point3D* result;
	result = &(*pointCloud->getPointCloud())[0]; // be cereful -> assignment can still cause slicing...
//	cout << "Polymorph point = "  << *result << endl;

	Point3D referencePoint = Point3D(1,1,0);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getX(), result->getX(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getY(), result->getY(), maxTolerance);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(referencePoint.getZ(), result->getZ(), maxTolerance);

	ColoredPoint3D* castedPoint;
	castedPoint = dynamic_cast<ColoredPoint3D*>(testPoint);
	CPPUNIT_ASSERT(castedPoint != 0);

	castedPoint = dynamic_cast<ColoredPoint3D*>(result);
	CPPUNIT_ASSERT(castedPoint != 0);
	CPPUNIT_ASSERT_EQUAL(point110->getR(), castedPoint->getR());
	CPPUNIT_ASSERT_EQUAL(point110->getG(), castedPoint->getG());
	CPPUNIT_ASSERT_EQUAL(point110->getB(), castedPoint->getB());

//	cout << "Casted polymorph point = "  << *castedPoint << endl;

//	Point3D* introspectionPoint;
//	introspectionPoint = testPoint->asDecoration<Point3D>();
//	CPPUNIT_ASSERT(introspectionPoint == 0);

	ColoredPoint3D* introspectionPoint;
	introspectionPoint = testPoint->asColoredPoint3D();
	CPPUNIT_ASSERT(introspectionPoint != 0);
	CPPUNIT_ASSERT_EQUAL(point110->getR(), introspectionPoint->getR());
	CPPUNIT_ASSERT_EQUAL(point110->getG(), introspectionPoint->getG());
	CPPUNIT_ASSERT_EQUAL(point110->getB(), introspectionPoint->getB());

	introspectionPoint = (*pointCloud->getPointCloud())[0].asColoredPoint3D();
	CPPUNIT_ASSERT(introspectionPoint != 0);
	CPPUNIT_ASSERT_EQUAL(point110->getR(), introspectionPoint->getR());
	CPPUNIT_ASSERT_EQUAL(point110->getG(), introspectionPoint->getG());
	CPPUNIT_ASSERT_EQUAL(point110->getB(), introspectionPoint->getB());

	introspectionPoint = (*pointCloud->getPointCloud())[1].asColoredPoint3D();
	CPPUNIT_ASSERT(introspectionPoint == 0);

	delete pointCloud;

}

}


/* EOF */
