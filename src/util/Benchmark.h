/**
 * @file 
 * Benchmark.h
 *
 * @date: Feb 5, 2010
 * @author: sblume
 */

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <string>
#include <iostream>
#include <fstream>

namespace BRICS_3D {

/**
 * @brief Simple benchmark suite
 *
 * This class allows to store benchmarking results in an automated way. The basic usage is like: <br> <br>
 * <code>
 * Benchmark benchmark("myNiceBenchmark"); <br>
 * benchmark.output << "some important result" << std::endl" <br>
 * </code> <br>
 *
 * The result, that a new file called myNiceBenchmark.txt is created in a new folder that is names by the current time stamp
 * in a YYYY-MM-DD_HH-MM-SS fashion e.g "2010-02-15_17-02-22". This folder is created in the standard log folder,
 * as defined by the environment variable BRICS_LOGFILES_DIR. <br><br>
 *
 * Every new Benchmark after the first one also stores its logfile ins the same time stamp folder.
 * This means one time stamp represents one run of a process, from its creation to its termination.
 * The intention is to repeat a benchmark by relaunching its process.
 * (That allows a benchmark to  be scheduled by the operating system or a script.)
 */
class Benchmark {
public:

	/**
	 * @brief Standard constructor
	 * If this constructor is used, benchmark name is set to "unnamedBenchmark.txt"
	 */
	Benchmark();

	/**
	 * @brief Constructor that allows to specify a benchmark name
	 * @param benchmarkName Name of the benchmark. The benchmark output will be saved in a file called like this name.
	 * A suffix ".txt" is added automatically.
	 *
	 */
	Benchmark(std::string benchmarkName);

	/**
	 * Standard destructor.
	 */
	virtual ~Benchmark();

	std::ofstream output;
private:

	/// Times stamp that will be used in path of benchmark
	static std::string timeStamp;

	/// File seperator. "\" for Window and "/" for Linux
	static std::string seperator;

	/// Resulting directory name. Consists of path to logfiles + timeStamp
	static std::string directoryName;

	/// The name of this benchmark. The benchmark output will be saved in a file called like this name.
	std::string benchmarkName;

	/// Resulting file name. Is a concatenation of directoryName and benchmarkName.
	std::string fileName;

	/**
	 * @brief Initializes folders and file streams
	 */
	void setupTargetFile();

};


}

#endif /* BENCHMARK_H_ */

/* EOF */
