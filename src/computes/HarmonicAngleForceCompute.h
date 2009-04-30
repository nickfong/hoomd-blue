/*
Highly Optimized Object-Oriented Molecular Dynamics (HOOMD) Open
Source Software License
Copyright (c) 2008 Ames Laboratory Iowa State University
All rights reserved.

Redistribution and use of HOOMD, in source and binary forms, with or
without modification, are permitted, provided that the following
conditions are met:

* Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names HOOMD's
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

Disclaimer

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND
CONTRIBUTORS ``AS IS''  AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 

IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS  BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.
*/

// $Id$
// $URL$
// Maintainer: dnlebard

#include <boost/shared_ptr.hpp>

#include "ForceCompute.h"
#include "AngleData.h"

#include <vector>

/*! \file HarmonicAngleForceCompute.h
	\brief Declares a class for computing harmonic angles
*/

#ifndef __HARMONICANGLEFORCECOMPUTE_H__
#define __HARMONICANGLEFORCECOMPUTE_H__

//! Computes harmonic angle forces on each particle
/*! Harmonic angle forces are computed on every particle in the simulation.

	The angles which forces are computed on are accessed from ParticleData::getAngleData
	\ingroup computes
*/
class HarmonicAngleForceCompute : public ForceCompute
	{
	public:
		//! Constructs the compute
		HarmonicAngleForceCompute(boost::shared_ptr<ParticleData> pdata);
		
		//! Destructor
		~HarmonicAngleForceCompute();
		
		//! Set the parameters
		virtual void setParams(unsigned int type, Scalar K, Scalar t_0);
		
		//! Returns a list of log quantities this compute calculates
		virtual std::vector< std::string > getProvidedLogQuantities(); 
		
		//! Calculates the requested log value and returns it
		virtual Scalar getLogValue(const std::string& quantity, unsigned int timestep);

	protected:
		Scalar *m_K;	//!< K parameter for multiple angle tyes
		Scalar *m_t_0;	//!< r_0 parameter for multiple angle types
		
		boost::shared_ptr<AngleData> m_angle_data;	//!< Angle data to use in computing angles
		
		//! Actually compute the forces
		virtual void computeForces(unsigned int timestep);
	};
	
//! Exports the AngleForceCompute class to python
void export_HarmonicAngleForceCompute();

#endif
