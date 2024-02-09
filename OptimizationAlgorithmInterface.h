
/**
  * @file  OptimizationAlgorithmInterface.h
  *
  * @brief This abstract class cointains declaration of virtual methods
  *        which can be used to call optimisation algorithms for a given objective function.
  *             
*/
#pragma once
#include "DataTypes.h"

using namespace data;
/**
  * @defgroup optimization_algorithms Optimization algorithms
  * @{
  */
namespace optimization_algorithms
{ 
  /** class OptimizationAlgorithmInterface
    */
	class OptimizationAlgorithmInterface
	{
	public:
		virtual void optimize (const int& maxIter ) = 0;
		virtual void optimize () = 0;
		virtual int  dim() const =  0;
	};
}
/**
  *@}
  */