/****************************************************************************************************************************************************
* Copyright (c) %AG_YEAR% Freescale Semiconductor, Inc.
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

#include "%AG_PROJECT_NAME%.hpp"
#include <FslBase/Log/Log.hpp>
#include <FslBase/Exceptions.hpp>
#include <FslGraphics/Bitmap/Bitmap.hpp>
#include <FslGraphics/Texture/Texture.hpp>
#include <FslGraphicsVulkan1_0/Exceptions.hpp>
#include <FslGraphicsVulkan1_0/Extend/Convert.hpp>
#include <FslGraphicsVulkan1_0/Check.hpp>
#include <FslGraphicsVulkan1_0/ConvertUtil.hpp>
#include <FslGraphicsVulkan1_0/Memory.hpp>
#include <FslGraphicsVulkan1_0/MemoryTypeHelper.hpp>
#include <FslGraphicsVulkan1_0/VulkanHelper.hpp>

namespace Fsl
{
  using namespace Willems;

  namespace
  {
  }


  %AG_PROJECT_NAME%::%AG_PROJECT_NAME%(const DemoAppConfig& config)
    : VulkanWillemsMeshDemoApp(config)
  {
  }


  %AG_PROJECT_NAME%::~%AG_PROJECT_NAME%()
  {

  }


  // This ensures the flow is the same as in the original sample
  void %AG_PROJECT_NAME%::Prepare()
  {
  }


  void %AG_PROJECT_NAME%::BuildCommandBuffers()
  {
  }


  void %AG_PROJECT_NAME%::Update(const DemoTime& demoTime)
  {
  }


  void %AG_PROJECT_NAME%::Draw(const DemoTime& demoTime)
  {
  }

}
