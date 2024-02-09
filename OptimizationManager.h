#pragma once

#include "DataTypes.h"
#include "PanelData.h"
#include "ParticleSwarm.h"
#include "ElasticNetGMM.h"
#include "PanelDataInterface.h"
#include "OptimizationAlgorithmInterface.h"
#include "ObjectiveFunctionInterface.h"

using namespace data;
using namespace objective_function;
using namespace optimization_algorithms;

using optimization_algorithms::swarm_algorithms::ParticleSwarm;

/** @class  OptimizationManger 
  * @brief  Optimization manager is essentially a factory class which creates instances of relevant
  *         classes based on passed data, searches for paramaters implied by the chosen objective function 
  *         for either default or prespecified number of itterations and returns EstimatedpParameter class 
  *         storing optimized values.
  */
class OptimizationManger 
{
public:
	  /** @constructor  OptimizationManger  (panel_t& data)
	    * @brief        Optimisation manager is created by the a reference to valid panel data.
	    */
	  OptimizationManger  (panel_t& data);
		 
	~ OptimizationManger  ();
	  
	/** @fn     void operator () (const int& maxIter)
	  * @brief  Call operator triggers optimisation procedure for prespecified number of itterations.
	  * @params integer specifing maximum number of iterations.
	  * @return none - the method has no return type as it operates on 
	  */
	  void operator () (const int& maxIter);
	 
	  EstimatedParams::pointer_t getResults() const;

private:
	PanelDataInterface*                              m_data          { nullptr };
	ObjectiveFunctionInterface*                      m_objective     { nullptr };
	OptimizationAlgorithmInterface*                  m_algorithm     { nullptr };
};