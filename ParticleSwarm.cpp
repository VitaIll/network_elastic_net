#include "ParticleSwarm.h"

namespace optimization_algorithms::swarm_algorithms
{
	ParticleSwarm::ParticleSwarm( ObjectiveFunctionInterface* objectiveIface)
		:
		m_objective  (objectiveIface),
		m_dimensions (objectiveIface -> dimensions())
	{   
		m_globalBest = vector_t::Zero(m_dimensions);

		for (int i = 0; i < m_populationSize; i++)
		{
			Particle particle = Particle(m_objective, this -> uniform());
			m_swarm.insert(particle.getPtr());
		}
		m_thisSwarm = std::make_shared <ParticleSwarm>(*this);
	}

	ParticleSwarm::~ParticleSwarm()
	{
		;
	}

	void ParticleSwarm::optimize(const int& maxIter)
	{
		for (int i = 0; i <= maxIter; i++)
		{
			this -> update();
		}
	}
	
	void ParticleSwarm::optimize()
	{
		for (int i = 0; i <= m_maxIter; i++)
		{
			this->update();
		}
	}
	vector_t ParticleSwarm::uniform()
	{
		return vector_t::Random(m_dimensions)*m_bound;
	}

	void ParticleSwarm::update()
	{
		Particle::pointer_t  bestParticle   =  *m_swarm.rbegin();
		                     m_globalBest   =  bestParticle -> getPosition();

		for (Particle::pointer_t particle : m_swarm)
		{
			particle ->operator()(m_globalBest);
		}
	}
		
}
