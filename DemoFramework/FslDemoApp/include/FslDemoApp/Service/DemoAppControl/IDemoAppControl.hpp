#ifndef FSLDEMOAPP_SERVICE_DEMOAPPCONTROL_IDEMOAPPCONTROL_HPP
#define FSLDEMOAPP_SERVICE_DEMOAPPCONTROL_IDEMOAPPCONTROL_HPP
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

#include <FslBase/BasicTypes.hpp>
#include <FslDemoApp/TimeStepMode.hpp>

namespace Fsl
{
  class IDemoAppControl
  {
  public:
    virtual ~IDemoAppControl() {}

    //! @brief Request a screenshot (this causes a update timer reset to occur as well, to prevent the screenshot from affecting the animation too much)
    virtual void RequestScreenshot() = 0;

    //! @brief Request that the app restarts.
    virtual void RequestAppRestart() = 0;

    //! @brief Reset the update timers (do this if a lengthy operation has taken place to prevent a lot FixedUpdate catchup calls)
    virtual void RequestUpdateTimerReset() = 0;

    //! @brief Request that the demo exits with the default exit code.
    virtual void RequestExit() = 0;

    //! @brief Request that the demo exits with the provided exit code.
    virtual void RequestExit(const int exitCode) = 0;

    //! @brief Changes the exit code if one has been set.
    //!        Will ignore the change request if not in 'requested exit' mode and log a warning.
    //!        Will ignore the change request if the current exit code isn't defaultExitCode and log a warning
    virtual void ChangeExitCode(const int exitCode) = 0;

    virtual bool HasScreenshotRequest() const = 0;
    virtual bool HasAppRestartRequest() const = 0;
    virtual bool HasUpdateTimerResetRequest() const = 0;
    virtual bool HasExitRequest() const = 0;
    virtual int GetExitCode() const = 0;

    virtual void SetTimeStepMode(const TimeStepMode timeStepMode) = 0;
    virtual TimeStepMode GetTimeStepMode() const = 0;
  };
}

#endif
