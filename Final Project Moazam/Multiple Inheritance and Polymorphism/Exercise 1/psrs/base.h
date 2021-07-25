#pragma once
// base class
#include<iostream>
#include <opencv2\opencv.hpp>
#include "edgeDetector.h";

using namespace std;

// psrs namespace declaration
namespace psrs {

	// const ENUM START
	const enum baseTypes { EdgeDetect, BlurFilter };

	const enum EdgeDetectors {
		CANNY,
		LAPLACIAN,
		SOBEL,
	};

	const enum  BlurFilters {
		MEAN,
		GAUSSIAN,
		MEDIAN,
	};

	// enum END

	class Base {
	// base class for EdgeDetector and BlurFiltering

	// to make this vars available to children classes 
	protected:
		int process;
		baseTypes type; // to distinguish between EdgeDetector and BlurFiltering

	public:

		// Default constructor
		Base(baseTypes _type) : process{ 0 }, type{_type} {}

		// param constructor
		Base(int _process, baseTypes _type) : process{ _process }, type{ _type } {}

		// set process for Edge Detectors
		void setOpenCVProcessName(EdgeDetectors _process) {

			if (type == BlurFilter) // to prevent this function when using Edge detection
				cout << "Provide an Edge Detector !" << endl;
			else
				process = _process;
		}

		// set process for Blur Filtering 
		void setOpenCVProcessName(BlurFilters _process) {

			if (type == EdgeDetect) // to prevent this function when using Blur filtering
				cout << "Provide a Blur Filter !" << _process << type << endl;
			else
				process = _process;
		}

		const char* getOpenCVProcessName() {
			// returns process name in string format

			switch (type) // type => enum EdgeDetect || enum BlurFilter
			{
			case EdgeDetect:
				switch (process)
				{
				case CANNY:
					return "CANNY";
				case LAPLACIAN:
					return "LAPLACIAN";
				case SOBEL:
					return "SOBEL";
				default:
					return "!"; // throw exception
				}
			case BlurFilter:
				switch (process)
				{
				case MEAN:
					return "MEAN";
				case GAUSSIAN:
					return "GAUSSIAN";
				case MEDIAN:
					return "MEDIAN";
				default:
					return "!"; // throw exception
				}

			default:
				return "!"; // throw exception
			}
			return ""; 
		}

	};

}