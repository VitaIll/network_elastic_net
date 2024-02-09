#pragma once
#include <memory>
#include "DataTypes.h"

namespace data 
{
	/** @class  PanelDataInterface
	  */
class PanelDataInterface
{
public:
	virtual ~ PanelDataInterface () {} ;

	virtual panel_t&  getPanel ()        const = 0;
	virtual matrix_t  getXt (index_t& t) const = 0;
	virtual vector_t  getYt (index_t& t) const = 0;
	virtual index_t   timeDim    ()      const = 0;
	virtual index_t   varsDim    ()      const = 0;
	virtual index_t   unitCount  ()      const = 0;
	virtual range_t   timeRange ()       const = 0;
	virtual range_t   varsRange ()       const = 0;
	virtual range_t   unitRange ()       const = 0;
};
}