#include "EstimatedParams.h"

namespace objective_function
{
	EstimatedParams::EstimatedParams(const int& unitCount)
		:
		m_unitCount(unitCount)
	{
		m_theseParams = std::make_shared<EstimatedParams>(*this);
	}

	EstimatedParams:: ~EstimatedParams()
	{
		;
	}

	void EstimatedParams::operator() (vector_t const& paramVector)
	{
		this->unpackVector(paramVector);
	}

	void EstimatedParams::unpackVector(vector_t const& paramVector)
	{	
		m_scalarParams = paramVector.tail(3);

		m_rho    = m_scalarParams(0);
		m_beta   = m_scalarParams(1);
		m_gamma  = m_scalarParams(2);
	
	for (int i = 0; i < m_unitCount; i++)
	{
		vector_t row    = vector_t::Zero(m_unitCount);
		vector_t params = paramVector.segment(i * (m_unitCount - 1), m_unitCount -1);

		row.head(i)                   = params.head(i);
		row.tail(m_unitCount - i - 1) = params.tail(m_unitCount - i - 1);
		m_adjacencyMatrix.row(i)      = row;
	}
	  m_theseParams = std::make_shared<EstimatedParams>(*this);
    }
		
}
