
/** @file  ElasticNetGMM.h
  * @brief This file contains declaration of the elastic net GMM objective function class and its methods.
  *  
  */
#pragma once
#include "ObjectiveFunctionInterface.h"
#include "PanelDataInterface.h"
#include "EstimatedParams.h"
#include "Errors.h"
#include <optional>
#include <Eigen/dense>

using namespace data;

namespace objective_function
{    /** @class ElasticNetGMM
	   * @brief This class is responsible for creation of GMM objective function.
	   *        Description of its methods follows. Functionalities of all objects 
	   *        of type objective function are accessed indirectly trough objective 
	   *        function interface.
	   */
	class ElastiNetGMM : public ObjectiveFunctionInterface
	{
	public:
		 /** @constructor ElastiNetGMM (PanelDataInterface* panelData)
		   * @brief       Instance of the elastic net GMM class is created from a pointer
		   *              to the PanelDataInterface, implying that GMM objective is created 
		   *              automatically uppon given access to dataset in panell format.
		   *              All relevant properties are figgured by the GMM class trough the
		   *              comunication protocol defined by the data interface.
		   */
		  ElastiNetGMM (PanelDataInterface* panelData);
		~ ElastiNetGMM ();
		
		/** @fn      virtual double operator () (const vector_t& x_0) override final
		  * @brief   Call operator overloaf, obtains value function at point x_0 from R^n space.
		  * @param   n-dimensional vector x_0
		  * @return  returns value of GMM at x_0
		  */
		virtual double operator ()  (const vector_t& x_0) override final;

		/** @fn      virtual vector_t diff(const vector_t& x_0) override final
		  * @brief   Differentiation operator which computes an approximate value of GMM gradient
		  *          at x_0 using forward numerical differentiation.
		  * @param   n-dimensional vector x_0
		  * @return  returns value of gradient vector at x_0
		  */
		virtual vector_t        diff(const vector_t& x_0) override final;

		/** @fn      virtual int dimensions() const override final
	      * @brief   Dimension call returns dimension of the search space.
		  *          The purpose of this method is to communicate to optimization algorithm 
		  *          the dimensions of the optimization problem at hand to initiate correct comunication protocol.
		  *       
	      * @param   none
	      * @return  Returns an integer specifing size of the search space.
	     */
		virtual int             dimensions() const        override final;
        
		/** @fn      virtual EstimatedParams::pointer_t getParams() const override final
          * @brief   Returns pointer to estimated params packaged in special EstimatedParams class.
          * @param   none
          * @return  Returns shared pointer to the class with estimated parameters.
          */
		virtual EstimatedParams::pointer_t getParams() const override final { return m_params; }

	private:
		double evalGMM(const vector_t& x_0) const;

	private:
		PanelDataInterface*                   m_dataIface;
		EstimatedParams::pointer_t            m_params         { nullptr };
		Errors::pointer_t                     m_errors         { nullptr };

		int const                             m_unitCount;
		int const                             m_periodCount;
		int const                             m_varCount;
		
		double const                          m_perturbParam = 0.001;
		double                                m_l1param      = 0.5;
		double                                m_l2param      = 0.5;

	};
}