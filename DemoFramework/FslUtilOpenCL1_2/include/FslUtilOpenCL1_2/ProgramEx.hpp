#ifndef FSLUTILOPENCL1_2_PROGRAMEX_HPP
#define FSLUTILOPENCL1_2_PROGRAMEX_HPP
/****************************************************************************************************************************************************
* Copyright (c) 2016 Freescale Semiconductor, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*
*    * Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*
*    * Neither the name of the Freescale Semiconductor, Inc. nor the names of
*      its contributors may be used to endorse or promote products derived from
*      this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************************************************************************************/

// Make sure Common.hpp is the first include file (to make the error message as helpful as possible when disabled)
#include <FslUtilOpenCL1_2/Common.hpp>
#include <FslUtilOpenCL1_2/Program.hpp>
#include <FslBase/Attributes.hpp>
#include <string>
#include <CL/cl.h>

namespace Fsl
{
  namespace OpenCL
  {
    // Provides a quick way to build a program.
    // If you want more direct control of the build process use the Program class instead.
    //
    // This object is movable so it can be thought of as behaving in the same was as a unique_ptr and is compatible with std containers
    class ProgramEx
    {
      Program m_program;
    public:
      ProgramEx(const ProgramEx&) = delete;
      ProgramEx& operator=(const Program&) = delete;

      //! @brief Move assignment operator
      ProgramEx& operator=(ProgramEx&& other);
      //! @brief Move constructor
      ProgramEx(ProgramEx&& other);

      //! @brief Create a 'invalid' instance (use Reset to populate it)
      ProgramEx();

      //! @brief Assume control of the Program (this object becomes responsible for releasing it)
      explicit ProgramEx(const cl_program program);

      //! @brief Create the requested resource
      ProgramEx(const cl_context context, const cl_device_id deviceId, const std::string& program);

      //! @brief returns the managed handle and releases the ownership.
      cl_program Release() FSL_FUNC_POSTFIX_WARN_UNUSED_RESULT
      {
        return m_program.Release();
      }

      //! @brief Destroys any owned resources and resets the object to its default state.
      void Reset()
      {
        m_program.Reset();
      }

      //! @brief Destroys any owned resources and assume control of the Program (this object becomes responsible for releasing it)
      void Reset(const cl_program program)
      {
        m_program.Reset(program);
      }

      //! @brief Destroys any owned resources and then creates the requested one
      void Reset(const cl_context context, const cl_device_id deviceId, const std::string& program);

      //! @brief Get the associated resource handle
      cl_program Get() const
      {
        return m_program.Get();
      }

      //! @brief Check if this object contains a valid resource
      bool IsValid() const
      {
        return m_program.IsValid();
      }
    };
  }
}

#endif
