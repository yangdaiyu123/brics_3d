/**
 * @file
 * demoEvaluation.cpp
 *
 * @author: Pinaki Banerjee
 * @date: Apr 10, 2011
 * @version: 0.1
 *
 * @description
 * This test file demonstrates the use of the proposed Evaluation framework to empirically
 * analyze the result of a segmentation algorithms. The metrics are calculated w.r.t the ground truth
 * files for the same input scenes provided in BRICS_3D.
 *
 */


#include<iostream>
#include <algorithm/segmentation/evaluation/Evaluator.h>
#include <algorithm/segmentation/evaluation/FileReader.h>
#include <algorithm/segmentation/evaluation/FileWriter.h>
#include <algorithm/segmentation/evaluation/MetricCalculator.h>
#include <algorithm/segmentation/evaluation/Comparator.h>
using namespace std;

int main(){

//ToDo Complete the description

	//Create the necessary objects
	BRICS_3D::Evaluator evaluator;
	BRICS_3D::MetricCalculator metricCalculator;
	BRICS_3D::FileWriter fileWriter;
	BRICS_3D::FileReader fileReader;

	//Evaluator Initialization
	//ToDo set the ground truth file path properly
	stringstream baseName;
	string folderPath = "../src/algorithm/segmentation/evaluation/groundTruthData/";
	string scenarioName = "bureau3/";
	string prefix ="bureau3_gt_";

	//set the ground truth base file name. For more info on file convention see
	// "trunk/src/algorithm/segmentation/evaluation/FileNameReadMe.txt"
	baseName.str("");
	baseName.clear();
	baseName << folderPath << scenarioName << prefix;
	evaluator.setGtBaseName(baseName.str());

	//set the machne segmented file names.
	folderPath = "../src/algorithm/segmentation/evaluation/data/MSAC_results/";
	prefix="bureau3_plane_msac_";
	baseName.str("");
	baseName.clear();
	baseName << folderPath << prefix;
	evaluator.setMsBaseName(baseName.str());

	evaluator.setFileExt(".txt");

	evaluator.setCountGt(12);
	evaluator.setCountMs(20);
	evaluator.setImageSize(160560);
	evaluator.setRegionCorrespondence("");
	evaluator.Initialize();

	//Set the initialized evaluator object to be used for metric Calculation
		metricCalculator.setEvaluatorObject(evaluator);
	//Calculating the metrics
		metricCalculator.calculateMetrics();

	//Saving the evaluation results into files.

		//HTML version to view the evaluation result
		fileWriter.WriteToHTML(metricCalculator,"MSAC_result");

		//CSV version to be used for comparison of different algorithms
		//NOTE: the file name should be <MethodName>_result
		//The <MethodName> will be the same name to be used for comparing the algorithms
		fileWriter.WriteToCsv(metricCalculator,"MSAC_result");

	cout<<"[Check Point]: Evaluation Done :)" << endl;

}
