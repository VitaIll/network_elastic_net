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

class OptimizationManger 
{
public:
	  OptimizationManger  (panel_t& data);
		 
	~ OptimizationManger  ();
	  
	  void operator () (const int& maxIter);
	 
	  EstimatedParams::pointer_t getResults() const;

private:
	PanelDataInterface*                              m_data          { nullptr };
	ObjectiveFunctionInterface*                      m_objective     { nullptr };
	OptimizationAlgorithmInterface*                  m_algorithm     { nullptr };
};