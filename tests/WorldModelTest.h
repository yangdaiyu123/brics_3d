/**
 * @file 
 * WorldModelTest.h
 *
 * @date: Oct 19, 2011
 * @author: sblume
 */

#ifndef WORLDMODELTEST_H_
#define WORLDMODELTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "brics_3d/core/HomogeneousMatrix44.h"
#include "brics_3d/util/Timer.h"
#include "brics_3d/worldModel/WorldModel.h"
#include "brics_3d/worldModel/sceneGraph/Attribute.h"
#include "brics_3d/worldModel/sceneGraph/Box.h"
#include "brics_3d/worldModel/sceneGraph/Cylinder.h"


namespace unitTests {

using namespace brics_3d;
using namespace Eigen;
using namespace std;
using namespace brics_3d::rsg;
using std::cout;
using std::endl;



class WorldModelTest : public CPPUNIT_NS::TestFixture {

	CPPUNIT_TEST_SUITE( WorldModelTest );
	CPPUNIT_TEST( testConstructor );
	CPPUNIT_TEST( testSimpleHanoiUseCase );
	CPPUNIT_TEST( testTowerOfHanoi );
	CPPUNIT_TEST( testFMPCUseCase );
	CPPUNIT_TEST( testMovingSceneObject );
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testConstructor();
	void testSimpleHanoiUseCase();
	void testTowerOfHanoi();
	void testFMPCUseCase();
	void testMovingSceneObject();

private:
	  /// Maximum deviation for equality check of double variables
	  static const double maxTolerance = 0.00001;
};

}
#endif /* WORLDMODELTEST_H_ */

/* EOF */
