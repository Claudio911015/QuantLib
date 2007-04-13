/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Fran�ois du Vignaud

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/


#ifndef quantlib_abcd_market_model_hpp
#define quantlib_abcd_market_model_hpp

#include <ql/marketmodels/marketmodel.hpp>
#include <ql/marketmodels/evolutiondescription.hpp>
#include <vector>

namespace QuantLib
{
    class Matrix;
    class AbcdMarketModel : public MarketModel {
      public:
        AbcdMarketModel(
            Real a,
            Real b,
            Real c,
            Real d,
            const std::vector<Real>& ks,
            const Matrix& correlations,
            const Size numberOfFactors,
            const std::vector<Rate>& initialRates,
            const std::vector<Spread>& displacements,
            const std::vector<Time>& rateTimes,
            const std::vector<Time>& evolutionTimes);
        //! \name MarketModel interface
        //@{
        const std::vector<Rate>& initialRates() const;
        const std::vector<Spread>& displacements() const;
        const EvolutionDescription& evolution() const;
        Size numberOfRates() const;
        Size numberOfFactors() const;
        Size numberOfSteps() const;
        const Matrix& pseudoRoot(Size i) const;
        //@}
      private:
        std::vector<Matrix> pseudoRoots_;
        Size numberOfFactors_, numberOfRates_, numberOfSteps_;
        std::vector<Rate> initialRates_;
        std::vector<Spread> displacements_;
        EvolutionDescription evolution_;
    };

    // inline

    inline const std::vector<Rate>& AbcdMarketModel::initialRates() const {
        return initialRates_;
    }

    inline const std::vector<Spread>& AbcdMarketModel::displacements() const {
        return displacements_;
    }

    inline const EvolutionDescription& AbcdMarketModel::evolution() const {
        return evolution_;
    }

    inline Size AbcdMarketModel::numberOfRates() const {
        return numberOfRates_;
    }

    inline Size AbcdMarketModel::numberOfFactors() const {
        return numberOfFactors_;
    }

    inline Size AbcdMarketModel::numberOfSteps() const {
        return numberOfSteps_;
    }

    inline const Matrix& AbcdMarketModel::pseudoRoot(Size i) const {
        QL_REQUIRE(i<pseudoRoots_.size(), "i<pseudoRoots_.size()");
        return pseudoRoots_[i];
    }

}

#endif