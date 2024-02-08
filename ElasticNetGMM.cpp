#include "ElasticNetGMM.h"

namespace objective_function
{
    ElastiNetGMM::ElastiNetGMM(PanelDataInterface* panelData)
        :
        m_dataIface(panelData),
        m_unitCount(panelData -> unitCount()),
        m_periodCount(panelData -> timeDim()),
        m_varCount(panelData -> varsDim())
    {
        ;
    }

    ElastiNetGMM:: ~ ElastiNetGMM ()
    {
    }

    double ElastiNetGMM::operator()(const vector_t& x_0)
    {
        return this -> evalGMM(x_0) ;
    }
    vector_t ElastiNetGMM::diff(const vector_t& x_0)
    {
        int      dim  = x_0.rows();
        vector_t   h  = vector_t::Zero(dim);
        vector_t grad = vector_t::Zero(dim);

        for (int i = 0; i < dim; i++)
        {
            h(i)    = m_perturbParam;
            grad(i) = (this->evalGMM(x_0 + h) - this->evalGMM(x_0)) * (1 / m_perturbParam);
        }

        return grad;
    }
    int ElastiNetGMM::dimensions() const
    {
        return  m_unitCount * (m_unitCount - 1) + 3;
    }
    double ElastiNetGMM::evalGMM(const vector_t& x_0) const
    {  
        int  unitCount    = m_dataIface -> unitCount();
        panel_t panel     = m_dataIface -> getPanel ();
        range_t timeRange = m_dataIface -> timeRange();
        range_t unitRange = m_dataIface -> unitRange();

        int q        = unitCount * unitCount;
        vector_t gNT = vector_t::Zero(q);
        matrix_t Iqq = matrix_t::Identity(q, q);

        for (auto& t: timeRange)
        {
            matrix_t m_t = panel[t];
            vector_t x_t = m_dataIface -> getXt(t);
            vector_t e_t = m_errors(x_0, m_t);
           
            matrix_t g   = matrix_t::Zero(unitCount, unitCount);

            for (auto& i: unitRange)
            {
                g.col(i) = x_t(i) * e_t;
            }
            gNT += g.reshaped(q, 1);
        }
        matrix_t W = m_params.adjacencyMatrix();
       
        double GMM = (gNT.transpose() * Iqq) * gNT 
                       + m_l1param * W.lpNorm<1>() 
                       + m_l2param * W.lpNorm<2>();
        return GMM;
    }
}