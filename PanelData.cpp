// 
#include "PanelData.h"
// ##############################################################
// Implementation of methods declared in class PanelData.
// ##############################################################
namespace data
{ 

// ##############################################################
// Implementation of public methods:
// ##############################################################
    PanelData::PanelData(panel_t& observedData)
        :
        m_data (observedData),
        m_T    (observedData.size()),
        m_n    (observedData[0].rows()),
        m_k    (observedData[0].cols())
    {
        m_timeRange = getSequence(m_T);
        m_unitRange = getSequence(m_k);
        m_varsRange = getSequence(m_k);
    }

    PanelData::~ PanelData()
    {
        ;
    }

// ################################################################

    panel_t& PanelData::getPanel() const
    {
        panel_t& dataRef = m_data;
        
        return dataRef;
    }

    matrix_t PanelData::getXt(index_t& t) const
    {   
        return m_data[t].block(0, 1, m_n , m_k  - 1 );   
    }

    vector_t PanelData::getYt(index_t& t) const
    {   
        return m_data[t].col(0);
    }
 // ##############################################################

    index_t PanelData::timeDim() const
    {
        return m_T;
    }

    index_t PanelData::varsDim() const
    {
        return m_k;
    }

    index_t PanelData::unitCount() const
    {
        return m_n;
    }
// ##############################################################
    range_t PanelData::timeRange() const
    {   
        return m_timeRange;
    }
 
    range_t PanelData::varsRange() const
    {
        return m_varsRange;
    }
   
    range_t PanelData::unitRange() const
    {
        return m_unitRange;
    }
 
// ##############################################################
// Implemenation of private methods:
// ##############################################################
    range_t PanelData::getSequence( auto& end)
    {
        range_t v;
        for (auto i = 0; i < end; i++)
        {
            v.push_back(i);
        }
        return v;
    }

    range_t PanelData::getSequence(auto& start, auto& end)
    {
        range_t v;
        for (auto& i = start; i < end; i++)
        {
            v.push_back(i);
        }
        return v;
    } 
}
// End of implementation.
// ##############################################################