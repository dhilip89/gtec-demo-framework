#ifndef FSLDEMOAPPVULKAN_SETUP_REGISTERDEMOAPP_HPP
#define FSLDEMOAPPVULKAN_SETUP_REGISTERDEMOAPP_HPP
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

#ifndef FSL_FEATURE_VULKAN1_0
#error Graphics.Vulkan support has not been enabled (define FSL_FEATURE_VULKAN1_0) to enable it
#endif

#include <FslDemoApp/Host/DemoAppHostConfigVulkan.hpp>
#include <FslDemoApp/Setup/RegisterDemoApp.hpp>


namespace Fsl
{
  class RegisterDemoAppVulkan
  {
  public:
    static void Register(const HostDemoAppSetup& setup, const DemoAppHostConfigVulkan& demoHostConfig, const std::shared_ptr<IDemoAppFactory>& appFactory);
    static void Register(const HostDemoAppSetup& setup, const DemoAppHostConfigVulkan& demoHostConfig, const std::shared_ptr<IDemoAppFactory>& appFactory, const std::shared_ptr<Fsl::ADemoOptionParser> appOptionParser);
  };
}


// Register a pure Vulkan demo
#define FSL_REGISTER_VULKAN_DEMO(tdEMOaPP, dEMOhOSTcONFIG) \
namespace Fsl \
{ \
  void HOST_DemoAppSetup(const HostDemoAppSetup*const pSetup) \
  { \
    if(pSetup == nullptr) \
      return; \
    const std::shared_ptr<IDemoAppFactory> appFactory(new DemoHost_Internal::DemoAppFactoryTemplate<tdEMOaPP>()); \
    return RegisterDemoAppVulkan::Register(*pSetup, (dEMOhOSTcONFIG), appFactory); \
  } \
}

#define FSL_REGISTER_VULKAN_DEMO_EX(tdEMOaPP, dEMOhOSTcONFIG, tdEMOaPPoPTIONpARSER) \
namespace Fsl \
{ \
  void HOST_DemoAppSetup(const HostDemoAppSetup*const pSetup) \
  { \
    if(pSetup == nullptr) \
      return; \
    const std::shared_ptr<IDemoAppFactory> appFactory(new DemoHost_Internal::DemoAppFactoryTemplate<tdEMOaPP>()); \
    const std::shared_ptr<Fsl::ADemoOptionParser> appOptionParser(new tdEMOaPPoPTIONpARSER()); \
    return RegisterDemoAppVulkan::Register(*pSetup, (dEMOhOSTcONFIG), appFactory, appOptionParser); \
  } \
}

#endif
