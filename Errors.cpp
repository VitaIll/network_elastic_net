#include "Errors.h"

namespace objective_function
{
Errors::Errors ( EstimatedParams::pointer_t params
                )
	:
	m_params    (params)
{
	m_thisInstance = std::make_shared<Errors>(*this);
}

Errors::~Errors()
{
	;
}

vector_t Errors::operator()(const vector_t& paramVector, const matrix_t& data)
{
	return this -> computeErrors (paramVector, data);
}

vector_t Errors::computeErrors(const vector_t& paramVector, const matrix_t& data)
{
	vector_t y_t = data.col(0);
	vector_t x_t = data.col(1);
	
	EstimatedParams::pointer_t params = m_params;
	                           params -> operator() (paramVector); 
	
    m_thisInstance = std::make_shared<Errors>(*this);

	matrix_t W     = params -> adjacencyMatrix ();
	double   rho   = params -> rho  ();
	double   beta  = params -> beta ();
	double   gamma = params -> gamma();

	vector_t e = y_t - rho * W * y_t - beta * x_t - gamma * W * x_t;

	return e;
}	
}