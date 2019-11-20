//
// Created by yaros on 17.11.2019.
//

#include "FitnessFunction.h"
FitnessFunction::FitnessFunction(std::vector<int> v){
        f = v;
    }
double FitnessFunction::fitFun(std::vector<int> v){
        if(f.size() != v.size() ) // error check
        {
            puts( "Sizes are not equal" ) ;
            return -1 ;  // not defined
        }

        // compute
        double res = 0;
        for (int i = 0; i <= f.size()-1; i++)
            res += (f[i]) * (v[i]);
        return res;
    }