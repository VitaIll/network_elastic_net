#pragma once
#include <memory>
#include "PanelDataInterface.h"

namespace data
{
	class PanelData : public PanelDataInterface
	{
	public:
		  PanelData (panel_t& observedData);
		~ PanelData ();

		typedef std::shared_ptr<PanelDataInterface>      pointer_t;
		inline pointer_t data()  const { return m_thisPanel; };

		/// return panel
		virtual panel_t& getPanel() const override final;

		/// return data in given period
		virtual matrix_t  getXt(index_t& t) const override final;  /// get matrix of exogenous variables at time t
		virtual vector_t  getYt(index_t& t) const override final;  /// get the response vector at time t

		/// return dimensions
		virtual  index_t   timeDim()   const override final;
		virtual  index_t   varsDim()   const override final;
		virtual  index_t   unitCount() const override final;

		/// return iterables
		virtual  range_t  timeRange() const override final;
		virtual  range_t  varsRange() const override final;
		virtual  range_t  unitRange() const override final;

	private:
		range_t getSequence (auto& end);
		range_t getSequence (auto& start, auto& end);

	private:
		pointer_t  m_thisPanel = std::make_shared<PanelData>(*this);

		panel_t&               m_data;     /// panel data

		index_t const          m_T;        /// time range of the panel
		index_t const          m_n;        /// observational unit count
		index_t const          m_k;        /// exogenous  variable count

		range_t             m_timeRange;    /// iterable time range
		range_t             m_varsRange;    /// iterable variable range
		range_t             m_unitRange;    /// iterable time range
	};
}