#pragma once

/** @file DataTypes.h
  *       This file contains base definitions of custom data types used to 
  *       manipulate obervational data.
  * 
  * @section Includes
  *
  * @brief I use Eigen for linear algebra and standard library map to store instances
  *        of more complex data classes.
 */

#include <map>
#include <span>
#include <Eigen/dense>

/** 
  * @defgroup data Data
  *           This group contains facilities related to manipaulation and maintanance of the observational data.
  * @{
  * @Section Custom data types
  *          Definitions of custom types follow.
 */

namespace data
{  
	/** @name  Integer index type
	  * @brief Element access type.                                   */
	typedef int                                    index_t;

	/** @name  Vector
	  * @brief Column vector of real numbers.                         */
	typedef Eigen::VectorXd                        vector_t;

	/** @name  Matrix
	    @brief Matrix type for data storage of observational data.    */
	typedef Eigen::MatrixXd                        matrix_t;

	/** @name  Panel collection of matricies
	    @brief Conatiner storing panel data as sequence of matricies.  */
	typedef std::map <int, matrix_t>               panel_t;   

	/** @name  Iterable range
	    @brief Data parsing iterable device for conscise looping.      */
	typedef std::vector <int>                      range_t;      
}
/** 
  *@author vit.illichmann@gmail.com
  @}*/