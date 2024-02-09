#pragma once

#include "DataTypes.h"
#include "EstimatedParams.h"
#include "PanelDataInterface.h"
#include <memory>

using namespace data;

namespace objective_function
{
	 /** @class  Errors
	   * @brief  This class computes errors for a given instance of GMM and given
	   *         vector of parameters.
	   */
class Errors
{
public:
	/** @constructor Errors (EstimatedParams::pointer_t params)
	  * @brief       Errors class is instantiated by a pointer to the instance of EstimatedParamClass.
	  */
	  Errors  ( EstimatedParams::pointer_t params );
	~ Errors  ();
	
	 typedef std::shared_ptr<Errors>         pointer_t;
	
	 /** @fn      vector_t operator () (const vector_t& paramVector, const matrix_t& data)
	   * @brief   Call to the instance of  Errors class will return vector of errors for 
	   *          given data and paramters.
	   * @params  The call requiers reference to a parameter vector and slice matrix from panel the 
	   *          data at period t = k.
	   * @return  Call operator returns vector of errors used to evaluate objective function.
	  */
	 vector_t operator ()   (const vector_t& paramVector, const matrix_t& data);

	 /** @fn    inline EstimatedParams::pointer_t getParams() const
	   * @brief This method returns shared pointer to the instance of EstimatedParams on which current 
	   *        instance of Errors class operates.
	   */
	 inline EstimatedParams::pointer_t getParams() const { return m_params; }
private:
	 vector_t computeErrors (const vector_t& paramVector, const matrix_t& data);

private:
	EstimatedParams::pointer_t       m_params;
	pointer_t                        m_thisInstance { nullptr };
}; 
}