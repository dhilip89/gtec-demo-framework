/****************************************************************************************************************************************************
* Copyright (c) 2015 Freescale Semiconductor, Inc.
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

#include <FslSimpleUI/System/UIManager.hpp>
#include <FslBase/Log/Log.hpp>
#include <FslDemoApp/DemoTime.hpp>
#include <FslDemoApp/Service/Events/Basic/KeyEvent.hpp>
#include <FslDemoApp/Service/Events/Basic/MouseButtonEvent.hpp>
#include <FslDemoApp/Service/Events/Basic/MouseMoveEvent.hpp>
#include <FslDemoApp/Service/Events/Basic/MouseWheelEvent.hpp>
#include <FslSimpleUI/Event/WindowEventPool.hpp>
#include <FslSimpleUI/Event/WindowEventSender.hpp>
#include "Modules/ModuleHost.hpp"
#include "Modules/ModuleCallbackRegistry.hpp"
#include "Modules/Input/InputModule.hpp"
#include "Event/EventRouter.hpp"
#include "Event/WindowEventQueueEx.hpp"
#include "UITree.hpp"
#include <cassert>

namespace Fsl
{
  namespace UI
  {

    UIManager::UIManager(const Point2& size)
      : m_moduleCallbackRegistry(std::make_shared<ModuleCallbackRegistry>())
      , m_eventPool(std::make_shared<WindowEventPool>())
      , m_eventQueue(std::make_shared<WindowEventQueueEx>())
      , m_tree(std::make_shared<UITree>(m_moduleCallbackRegistry, m_eventPool, m_eventQueue, Vector2(static_cast<float>(size.X), static_cast<float>(size.Y))))
      , m_eventSender(std::make_shared<WindowEventSender>(m_eventQueue, m_eventPool, m_tree))
      , m_moduleHost(std::make_shared<ModuleHost>(m_moduleCallbackRegistry, m_tree, m_tree->GetRootNode(), m_tree, m_tree, m_eventPool))
      , m_inputModule(std::make_shared<InputModule>(m_moduleHost))
      , m_leftButtonDown(false)
    {
    }


    UIManager::~UIManager()
    {
    }


    std::shared_ptr<IWindowManager> UIManager::GetWindowManager() const
    {
      return m_tree;
    }


    std::shared_ptr<WindowEventPool> UIManager::GetEventPool() const
    {
      return m_eventPool;
    }


    std::shared_ptr<WindowEventSender> UIManager::GetEventSender() const
    {
      return m_eventSender;
    }


    //bool UIManager::SendKeyEvent(const KeyEvent& event)
    //{
    //}


    bool UIManager::SendMouseButtonEvent(const MouseButtonEvent& event)
    {
      assert(m_inputModule);
      if (event.GetButton() != VirtualMouseButton::Left)
        return false;

      m_leftButtonDown = event.IsPressed();
      const auto transactionState = m_leftButtonDown ? EventTransactionState::Begin : EventTransactionState::End;
      const auto position = event.GetPosition();
      const bool isHandled = m_inputModule->SendClickEvent(0, 0, transactionState, false, Vector2(position.X, position.Y));
      if (isHandled && !event.IsHandled())
      {
        event.Handled();
      }
      return isHandled;
    }


    bool UIManager::SendMouseMoveEvent(const MouseMoveEvent& event)
    {
      if (!m_leftButtonDown)
        return false;

      const auto position = event.GetPosition();
      const bool isHandled = m_inputModule->SendClickEvent(0, 0, EventTransactionState::Begin, true, Vector2(position.X, position.Y));
      if (isHandled && !event.IsHandled())
      {
        event.Handled();
      }
      return isHandled;
    }


    //bool UIManager::SendMouseWheelEvent(const MouseWheelEvent& event)
    //{
    //}


    void UIManager::Resized(const Point2& size)
    {
      m_tree->Resized(Vector2(static_cast<float>(size.X), static_cast<float>(size.Y)));
    }


    void UIManager::FixedUpdate(const DemoTime& demoTime)
    {
    }


    void UIManager::Update(const DemoTime& demoTime)
    {
      m_tree->Update(demoTime);
    }


    void UIManager::Draw()
    {
      m_tree->Draw();
    }


    void UIManager::RegisterEventListener(const std::weak_ptr<IEventListener>& eventListener)
    {
      m_tree->RegisterEventListener(eventListener);
    }


    void UIManager::UnregisterEventListener(const std::weak_ptr<IEventListener>& eventListener)
    {
      m_tree->UnregisterEventListener(eventListener);
    }
  }
}
