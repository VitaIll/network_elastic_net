#pragma once

#include "ObjectiveFunctionInterface.h"
#include "PanelDataInterface.h"
#include "EstimatedParams.h"
#include "Errors.h"
#include <optional>
#include <Eigen/dense>

using namespace data;

namespace objective_function
{
	class ElastiNetGMM : public ObjectiveFunctionInterface
	{
	public:
		  ElastiNetGMM (PanelDataInterface* panelData);
		~ ElastiNetGMM ();
		
		virtual double operator ()  (const vector_t& x_0) override final;
		virtual vector_t        diff(const vector_t& x_0) override final;
		virtual int             dimensions() const        override final;
        
		virtual EstimatedParams::pointer_t getParams() const override final { return m_params; }

	private:
		double evalGMM(const vector_t& x_0) const;

	private:
		PanelDataInterface*                   m_dataIface;
		EstimatedParams                       m_params = EstimatedParams(m_unitCount);
		Errors                                m_errors = Errors (m_params);

		int const                             m_unitCount;
		int const                             m_periodCount;
		int const                             m_varCount;
		
		double const                          m_perturbParam = 0.001;
		double                                m_l1param      = 10.0;
		double                                m_l2param      = 0.0;

	};
}