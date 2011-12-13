/******************************************************************************
* BRICS_3D - 3D Perception and Modeling Library
* Copyright (c) 2011, GPS GmbH
*
* Author: Pinaki Sunil Banerjee
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

#ifndef EUCLIDEANCLUSTERING3D_H_
#define EUCLIDEANCLUSTERING3D_H_

#include "core/PointCloud3D.h"
#include "core/ColoredPointCloud3D.h"
#include "algorithm/nearestNeighbor/NearestNeighborANN.h"
#include "algorithm/nearestNeighbor/NearestNeighborFLANN.h"
#include "algorithm/segmentation/ISegmentation.h"

#include <vector>
#include<stdio.h>

namespace BRICS_3D {

class EuclideanClustering3D : public ISegmentation{

private:

	/**
	 * spacial cluster tolerance in metres
	 */
	float clusterTolerance;


	/**
	 * Minimum number of points to consider it as a cluster
	 */
	unsigned int minClusterSize;


	/**
	 * Maximum number of points to be in the cluster
	 */
	unsigned int maxClusterSize;

	/**
	 * Takes a pointcloud and returns an array of pointcloud that make up the clusters.
	 * The clusters are defined by the parameters being set
	 * @param inCloud	Input point cloud
	 * @param extractedClusters Vector of pointcluds containing the extracted clusters
	 */
	void extractClusters(BRICS_3D::PointCloud3D *inCloud);


	/**
	 * Takes a pointcloud and returns an array of pointcloud that make up the clusters.
	 * The clusters are defined by the parameters being set
	 * @param inCloud	Input point cloud
	 * @param extractedClusters Vector of pointcluds containing the extracted clusters
	 */
	void extractClusters(BRICS_3D::ColoredPointCloud3D *inCloud);


	std::vector<BRICS_3D::PointCloud3D*> extractedClusters;

	std::vector<BRICS_3D::ColoredPointCloud3D*> extractedClustersColored;


public:
	EuclideanClustering3D();
	virtual ~EuclideanClustering3D();


	/**
	 * @return the used spatial cluster tolerance
	 */
	float getClusterTolerance() const
	{
		return clusterTolerance;
	}


	/**
	 *
	 * @return maximum no of point in a cluster till the cluster is valid
	 */
	int getMaxClusterSize() const
	{
		return maxClusterSize;
	}


	/**
	 *
	 * @return minimum no of point in a cluster till the cluster is valid
	 */
	int getMinClusterSize() const
	{
		return minClusterSize;
	}


	/**
	 *
	 * @param clusterTolerance spacial cluster tolerance
	 */
	void setClusterTolerance(float clusterTolerance)
	{
		this->clusterTolerance = clusterTolerance;
	}


	/**
	 *
	 * @param maxClusterSize maximum no of point in a cluster till the cluster is valid
	 */
	void setMaxClusterSize(int maxClusterSize)
	{
		this->maxClusterSize = maxClusterSize;
	}


	/**
	 *
	 * @param minClusterSize minimum no of point in a cluster till the cluster is valid
	 */
	void setMinClusterSize(int minClusterSize)
	{
		this->minClusterSize = minClusterSize;
	}


	void getExtractedClusters(std::vector<BRICS_3D::PointCloud3D*> &extractedClusters){
		if(!isColoredInput)
		extractedClusters = this->extractedClusters;
	}

	void getExtractedClusters(std::vector<BRICS_3D::ColoredPointCloud3D*> &extractedClusters){
		if(isColoredInput)
		extractedClusters = this->extractedClustersColored;
	}

	int segment();
};

}

#endif /* EUCLIDEANCLUSTERING3D_H_ */
