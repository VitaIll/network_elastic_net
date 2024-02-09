
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
  /** @class OptimizationAlgorithmInterface
    * @brief This abstract class defines communication protocol with optimization algoritm of choice.
    */
	class OptimizationAlgorithmInterface
	{
	public:
		/** @fn    	virtual void optimize (const int& maxIter )
          * @brief  Performs given optimization procedure for specified number of iterations.
         */
		virtual void optimize (const int& maxIter ) = 0;
		
		/** @overload virtual void optimize ()
		  * @brief    Performs given optimization procedure for the default number of iterations
		  *           specified by the implementing algorithm.
		 */
		virtual void optimize () = 0;

		/** @fn       virtual int  dim() const
	      * @brief    Returns dimension of the search space, this is to check that
		  *           dimensions specified by the algorithm and optimised function match.
	    */
		virtual int  dim() const =  0;
	};
}
/**
  *@}
  */