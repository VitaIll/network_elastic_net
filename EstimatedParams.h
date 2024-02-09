#pragma once
#include "DataTypes.h"
#include <memory>

using namespace data;

namespace objective_function
{
class EstimatedParams
{ 
 public:
	  EstimatedParams (const int& unitCount);
	 // EstimatedParams (const EstimatedParams& other) : m_unitCount(other.unitCount()) {}

	~ EstimatedParams ();
	  
	  typedef std::shared_ptr <EstimatedParams>                pointer_t;

	  void operator () (vector_t const& paramVector);

	  inline matrix_t adjacencyMatrix () const { return m_adjacencyMatrix; }
	  inline double   rho ()             const { return m_rho;             }
	  inline double   beta()             const { return m_beta;            }
	  inline double   gamma()            const { return m_gamma;           }

	  inline double    unitCount()       const { return m_unitCount;       }
	  inline pointer_t pointer()         const { return m_theseParams;     }

 private: 
	  void unpackVector ( vector_t const& paramVector );
 
private:
	 pointer_t                  m_theseParams { nullptr };
	 const int&                 m_unitCount;
	 
	 matrix_t                   m_adjacencyMatrix {matrix_t::Zero(m_unitCount,m_unitCount)};
	 vector_t                   m_scalarParams    {vector_t::Zero(m_unitCount)};
	 
	 double                     m_rho  { 0.0 };
	 double                     m_beta { 0.0 };
	 double                     m_gamma{ 0.0 };
};
}