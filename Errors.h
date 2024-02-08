#pragma once

#include "DataTypes.h"
#include "EstimatedParams.h"
#include "PanelDataInterface.h"
#include <memory>

using namespace data;

namespace objective_function
{
class Errors
{
public:
	  Errors  ( EstimatedParams params );
	  Errors  (const Errors& other) : m_params(other.getParams()) {}

	~ Errors ();

	 typedef std::shared_ptr<Errors>         pointer_t;

	 vector_t operator ()   (const vector_t& paramVector, const matrix_t& data);

	 inline EstimatedParams getParams() const { return m_params; }
private:
	 vector_t computeErrors (const vector_t& paramVector, const matrix_t& data);

private:
	EstimatedParams                  m_params;
	pointer_t                        m_thisInstance { nullptr };
}; 
}