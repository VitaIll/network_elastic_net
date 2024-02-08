#include "OptimizationManager.h"

OptimizationManger::OptimizationManger (panel_t& data)
{ 
	m_data         = new PanelData        (data);
	m_objective    = new ElastiNetGMM     (m_data);
	m_algorithm    = new ParticleSwarm    (m_objective);
}

OptimizationManger::~OptimizationManger()
{
}

void OptimizationManger::operator()(const int& maxIter)
{
	m_algorithm -> optimize(maxIter);
}

EstimatedParams::pointer_t OptimizationManger::getResults() const
{
	return m_objective -> getParams();
}

