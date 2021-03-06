#ifndef FSLDEMOHOST_SERVICE_DEMOAPPCONTROL_DEMOAPPCONTROLSERVICE_HPP
#define FSLDEMOHOST_SERVICE_DEMOAPPCONTROL_DEMOAPPCONTROLSERVICE_HPP
/****************************************************************************************************************************************************
* Copyright (c) 2014 Freescale Semiconductor, Inc.
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

#include <FslDemoApp/Service/ServiceProvider.hpp>
#include <FslDemoHost/Service/DemoAppControl/IDemoAppControlEx.hpp>
#include <FslDemoHost/Service/ThreadLocal/ThreadLocalService.hpp>

namespace Fsl
{
  class IEventPoster;
  class IDemoPlatformControl;

  class DemoAppControlService
    : public ThreadLocalService
    , public IDemoAppControlEx
  {
    std::shared_ptr<IEventPoster> m_eventPoster;
    std::shared_ptr<IDemoPlatformControl> m_platformControl;
    int m_defaultExitCode;
    bool m_hasScreenshotRequest;
    bool m_hasAppRestartResetRequest;
    bool m_hasUpdateTimerResetRequest;
    mutable bool m_hasExitRequest;
    int m_exitCode;
    TimeStepMode m_timestepMode;
  public:
    DemoAppControlService(const ServiceProvider& serviceProvider, const int defaultExitCode);
    ~DemoAppControlService();


    // From IDemoAppControl
    virtual void RequestScreenshot() override;
    virtual void RequestAppRestart() override;
    virtual void RequestUpdateTimerReset() override;
    virtual void RequestExit() override;
    virtual void RequestExit(const int exitCode) override;
    virtual void ChangeExitCode(const int exitCode) override;
    virtual bool HasScreenshotRequest() const override;
    virtual bool HasAppRestartRequest() const override;
    virtual bool HasUpdateTimerResetRequest() const override;
    virtual bool HasExitRequest() const override;
    virtual int GetExitCode() const override;
    virtual void SetTimeStepMode(const TimeStepMode timeStepMode) override;
    virtual TimeStepMode GetTimeStepMode() const override;

    // From IDemoAppControlServiceEx
    virtual void ClearScreenshotRequestRequest() override;
    virtual void ClearAppRestartRequestRequest() override;
    virtual void ClearUpdateTimerResetRequest() override;
  private:
    void DoRequestExit(const int exitCode);
  };
}

#endif
