/**
  * @file  ObjectiveFunctionInterface.h
  * 
  * @brief This abstract class cointains declaration of virtual methods 
  *        which can be used to call objective function.
  *        Roughly, speaking we are interested in value and gradient of 
  *        any object densended from the ObejctiveFunctionInterface abstract
  *        class.
  */

#pragma once
#include "DataTypes.h"
#include "EstimatedParams.h"

using namespace data;

/**
  * @defgroup objectiveFunction Objective function
  * @{
  */
namespace objective_function
{
class ObjectiveFunctionInterface
{
public:
	/** @name       Call operator ()
	  * @brief      Overload of the call () operator for objective function evaluation.
	  * @param      The call operator takes in point x_0 as an argument. 
	  * @return     Call to the function returns value of the objective in x_0.      
	  */
	virtual double operator () (const vector_t& x_0) = 0;
	
	/** @name  Differentiation method
	  * @brief This method will return value of gradient in x_0.
	  */
	virtual vector_t       diff (const vector_t& x_0) = 0;

	 /** @name       Dimensions of search space
	   * @brief      Gets dimension of the optimization space.
	   */
	virtual int dimensions() const = 0;

	virtual EstimatedParams::pointer_t getParams () const = 0;
};
}
/**
  *@} 
  */