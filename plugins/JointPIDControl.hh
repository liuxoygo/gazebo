/*
 * Copyright 2011 Nate Koenig & Andrew Howard
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef __GAZEBO_JOINTPIDCONTROL_PLUGIN_HH__
#define __GAZEBO_JOINTPIDCONTROL_PLUGIN_HH__

#include "common/common.h"
#include "physics/physics.h"
#include "transport/TransportTypes.hh"
#include "gazebo.h"

namespace gazebo
{
  class JointPIDControlPlugin : public ModelPlugin
  {
    public: JointPIDControlPlugin();
    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);
    public: virtual void Init();

    private: void OnUpdate();

    private: void OnVelMsg(ConstPosePtr &_msg);

    private: transport::NodePtr node;
    private: transport::SubscriberPtr velSub;

    private: physics::ModelPtr model;
    private: physics::JointPtr leftJoint, rightJoint;
    private: event::ConnectionPtr updateConnection;
    private: double wheelSpeed[2];
    private: double torque;
    private: double wheelSeparation;
    private: double wheelRadius;
    private: common::Time prevUpdateTime;

    private: physics::LinkPtr link, leftWheelLink, rightWheelLink;

    private: common::PID leftPID, rightPID;
    private: double sum;
  };
}
#endif
