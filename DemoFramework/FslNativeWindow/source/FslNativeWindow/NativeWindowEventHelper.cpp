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

#include <FslBase/Exceptions.hpp>
#include <FslNativeWindow/NativeWindowEventHelper.hpp>
#include <FslNativeWindow/VirtualKeyFlag.hpp>
#include <cassert>
#include <limits>

namespace Fsl
{
  NativeWindowEvent NativeWindowEventHelper::EncodeWindowActivationEvent(const bool activated)
  {
    return NativeWindowEvent(NativeWindowEventType::WindowActivation, activated ? 1 : 0);
  }


  void NativeWindowEventHelper::DecodeWindowActivationEvent(const NativeWindowEvent& event, bool& rActivated)
  {
    assert(event.Type == NativeWindowEventType::WindowActivation);
    rActivated = event.Arg1 != 0;
  }


  NativeWindowEvent NativeWindowEventHelper::EncodeWindowSuspendEvent(const bool suspend)
  {
    return NativeWindowEvent(NativeWindowEventType::WindowSuspend, suspend ? 1 : 0);
  }


  void NativeWindowEventHelper::DecodeWindowSuspendEvent(const NativeWindowEvent& event, bool& rSuspend)
  {
    assert(event.Type == NativeWindowEventType::WindowActivation);
    rSuspend = event.Arg1 != 0;
  }

  NativeWindowEvent NativeWindowEventHelper::EncodeWindowResizedEvent()
  {
    return NativeWindowEvent(NativeWindowEventType::WindowResized);
  }


  NativeWindowEvent NativeWindowEventHelper::EncodeWindowDPIChanged()
  {
    return NativeWindowEvent(NativeWindowEventType::WindowDPIChanged);
  }


  NativeWindowEvent NativeWindowEventHelper::EncodeLowMemoryEvent()
  {
    return NativeWindowEvent(NativeWindowEventType::LowMemory);
  }


  NativeWindowEvent NativeWindowEventHelper::EncodeInputKeyEvent(const VirtualKey::Enum virtualKey, const bool isPressed)
  {
    const int32_t arg1 = virtualKey;
    const int32_t arg2 = (isPressed ? VirtualKeyFlag::IsPressed : 0);
    return NativeWindowEvent(NativeWindowEventType::InputKey, arg1, arg2);
  }


  void NativeWindowEventHelper::DecodeInputKeyEvent(const NativeWindowEvent& event, VirtualKey::Enum& rVirtualKey, bool& rIsPressed)
  {
    assert(event.Type == NativeWindowEventType::InputKey);
    rVirtualKey = static_cast<VirtualKey::Enum>(event.Arg1);
    rIsPressed = (event.Arg2 & VirtualKeyFlag::IsPressed) == VirtualKeyFlag::IsPressed;
  }


  NativeWindowEvent NativeWindowEventHelper::EncodeInputMouseButtonEvent(const VirtualMouseButton::Enum button, const bool isPressed, const Point2& position)
  {
    const int32_t arg1 = button;
    const int32_t arg2 = (isPressed ? VirtualKeyFlag::IsPressed : 0);
    const int32_t arg3 = EncodePosition(position);

    return NativeWindowEvent(NativeWindowEventType::InputMouseButton, arg1, arg2, arg3);
  }


  void NativeWindowEventHelper::DecodeInputMouseButtonEvent(const NativeWindowEvent& event, VirtualMouseButton::Enum& rButton, bool& rIsPressed, Point2& rPosition)
  {
    assert(event.Type == NativeWindowEventType::InputMouseButton);
    rButton = static_cast<VirtualMouseButton::Enum>(event.Arg1);
    rIsPressed = (event.Arg2 & VirtualKeyFlag::IsPressed) == VirtualKeyFlag::IsPressed;
    rPosition = DecodePosition(event.Arg3);
  }


  NativeWindowEvent NativeWindowEventHelper::EncodeInputMouseMoveEvent(const Point2& position, const VirtualMouseButtonFlags& buttonFlags)
  {
    const int32_t arg1 = EncodePosition(position);
    const int32_t arg2 = EncodeVirtualMouseButtonFlags(buttonFlags);
    return NativeWindowEvent(NativeWindowEventType::InputMouseMove, arg1, arg2);
  }


  void NativeWindowEventHelper::DecodeInputMouseMoveEvent(const NativeWindowEvent& event, Point2& rPosition, VirtualMouseButtonFlags& rFlags)
  {
    assert(event.Type == NativeWindowEventType::InputMouseMove);
    rPosition = DecodePosition(event.Arg1);
    rFlags = DecodeVirtualMouseButtonFlags(event.Arg2);
  }


  NativeWindowEvent NativeWindowEventHelper::EncodeInputMouseWheelEvent(const int32_t delta, const Point2& position)
  {
    const int32_t arg1 = delta;
    const int32_t arg2 = EncodePosition(position);

    return NativeWindowEvent(NativeWindowEventType::InputMouseWheel, arg1, arg2);
  }


  void NativeWindowEventHelper::DecodeInputMouseWheelEvent(const NativeWindowEvent& event, int32_t& rDelta, Point2& rPosition)
  {
    assert(event.Type == NativeWindowEventType::InputMouseWheel);
    rDelta = event.Arg1;
    rPosition = DecodePosition(event.Arg2);
  }


  int32_t NativeWindowEventHelper::EncodePosition(const Point2& position)
  {
    if (position.X < std::numeric_limits<int16_t>::min() || position.X > std::numeric_limits<int16_t>::max())
      throw UsageErrorException("the x-position is expected to fit inside a int16");
    if (position.Y < std::numeric_limits<int16_t>::min() || position.Y > std::numeric_limits<int16_t>::max())
      throw UsageErrorException("the y-position is expected to fit inside a int16");
    return ((position.Y & 0xFFFF) << 16) | (position.X & 0xFFFF);
  }


  Point2 NativeWindowEventHelper::DecodePosition(const int32_t encodedPosition)
  {
    const int16_t x = static_cast<int16_t>(encodedPosition & 0xFFFF);
    const int16_t y = static_cast<int16_t>((encodedPosition >> 16) & 0xFFFF);
    return Point2(x, y);
  }


  int32_t NativeWindowEventHelper::EncodeVirtualMouseButtonFlags(const VirtualMouseButtonFlags& flags)
  {
    return static_cast<int32_t>(flags.Flags);
  }


  VirtualMouseButtonFlags NativeWindowEventHelper::DecodeVirtualMouseButtonFlags(const int32_t encodedFlags)
  {
    return VirtualMouseButtonFlags(static_cast<uint32_t>(encodedFlags));
  }

}
