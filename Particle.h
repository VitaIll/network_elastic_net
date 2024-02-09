#pragma once
#include "ObjectiveFunctionInterface.h"
#include <memory>

using namespace data;
using objective_function::ObjectiveFunctionInterface;

namespace optimization_algorithms::swarm_algorithms
{
   /* @class Particle
	*/
class Particle
{
	public:
	   Particle (ObjectiveFunctionInterface* function, const vector_t& initialPosition);

	 ~ Particle ();
	 
	 typedef std::shared_ptr<Particle>    pointer_t;

	 inline double    getValue ()    const { return m_value;    }
	 inline vector_t  getPosition () const { return m_position; }
	 inline pointer_t getPtr()       const { return m_thisParticle; }
	 
	 void operator () (vector_t& globalBest);
	 
	 inline bool operator < (const Particle& other) const
	 {
		 return m_value < other.getValue();
	 }
   
    private:
		void update(vector_t& globalBest);

    private:
		vector_t	                                  m_position;
		vector_t	                                  m_velocity;
		double                                        m_value          { 0.0 };
		double                                        m_gradientWeight { 0.8 };
		ObjectiveFunctionInterface*                   m_function;
		pointer_t                                     m_thisParticle;
};
}