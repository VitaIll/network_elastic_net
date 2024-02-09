#include "Particle.h"

namespace optimization_algorithms::swarm_algorithms
{
	Particle::Particle(ObjectiveFunctionInterface* function, const vector_t& initialPosition)
		:
		m_position(initialPosition),
		m_function(function)
	{
		int dim    = m_position.size();
		m_velocity = vector_t::Zero(dim);
		this       -> update(m_position);
		m_thisParticle = std::make_shared<Particle>(*this);

	}

	Particle::~Particle()
	{
		;
	}

	void Particle::operator()(vector_t& globalBest)
	{
		this -> update(globalBest);
	}

	void Particle::update(vector_t& globalBest)
	{
		m_velocity =  - m_gradientWeight * (m_function->diff(m_position))
			          + (1 - m_gradientWeight) * (globalBest - m_position)
			          + 0.1*m_velocity;
		
		m_position  = m_position + m_velocity;
		m_value     = m_function -> operator()(m_position);
	}
}
