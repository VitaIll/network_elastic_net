#pragma once
#include "ObjectiveFunctionInterface.h"
#include "OptimizationAlgorithmInterface.h"
#include "Particle.h"
#include <memory>
#include <set>

using namespace data;
using objective_function::ObjectiveFunctionInterface;

namespace optimization_algorithms::swarm_algorithms
{
	class ParticleSwarm : public OptimizationAlgorithmInterface
	{
	  public:
		   ParticleSwarm (ObjectiveFunctionInterface*  objectiveIface );

		  ~ ParticleSwarm ();

		  virtual void optimize(const int& maxIter) override final;
		  virtual void optimize() override final;
		  virtual int  dim() const override final { return m_dimensions; }

		  typedef std::shared_ptr<ParticleSwarm>                  pointer_t;
		  typedef std::set<Particle::pointer_t>                   swarm_t;
		  

	private:
		  vector_t uniform();
		  void     update();

	  private:
		  int    const                                  m_populationSize   {  100   };
		  int    const                                  m_maxIter          {  100   };
		  double const                                  m_bound            {  0.01  };

		  pointer_t                                     m_thisSwarm        { nullptr };
		  ObjectiveFunctionInterface*                   m_objective;
		  int   const                                   m_dimensions;
		  swarm_t                                       m_swarm;
		  vector_t                                      m_globalBest;
	};
}