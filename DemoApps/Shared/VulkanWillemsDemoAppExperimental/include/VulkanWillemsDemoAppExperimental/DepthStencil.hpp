#ifndef VULKANWILLEMSDEMOAPPEXPERIMENTAL_DEPTHSTENCIL_HPP
#define VULKANWILLEMSDEMOAPPEXPERIMENTAL_DEPTHSTENCIL_HPP
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

#include <FslGraphicsVulkan1_0/Image.hpp>
#include <FslGraphicsVulkan1_0/Memory.hpp>
#include <FslGraphicsVulkan1_0/ImageView.hpp>
#include <vulkan/vulkan.h>

namespace Fsl
{
  namespace Willems
  {
    class DepthStencil
    {
    public:
      Vulkan::Image Image;
      Vulkan::Memory Mem;
      Vulkan::ImageView View;

      DepthStencil(const DepthStencil&) = delete;
      DepthStencil& operator=(const DepthStencil&) = delete;

      //! @brief Move assignment operator
      DepthStencil& operator=(DepthStencil&& other);

      //! @brief Move constructor
      //! Transfer ownership from other to this
      DepthStencil(DepthStencil&& other);

      //! @brief Create a 'invalid' DepthStencil
      DepthStencil();
    };
  }
}

#endif
