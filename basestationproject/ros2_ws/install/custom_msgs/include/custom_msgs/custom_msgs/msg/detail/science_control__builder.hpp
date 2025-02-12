// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/ScienceControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/science_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_ScienceControl_deploy_sensors
{
public:
  explicit Init_ScienceControl_deploy_sensors(::custom_msgs::msg::ScienceControl & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::ScienceControl deploy_sensors(::custom_msgs::msg::ScienceControl::_deploy_sensors_type arg)
  {
    msg_.deploy_sensors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::ScienceControl msg_;
};

class Init_ScienceControl_deploy_heat
{
public:
  explicit Init_ScienceControl_deploy_heat(::custom_msgs::msg::ScienceControl & msg)
  : msg_(msg)
  {}
  Init_ScienceControl_deploy_sensors deploy_heat(::custom_msgs::msg::ScienceControl::_deploy_heat_type arg)
  {
    msg_.deploy_heat = std::move(arg);
    return Init_ScienceControl_deploy_sensors(msg_);
  }

private:
  ::custom_msgs::msg::ScienceControl msg_;
};

class Init_ScienceControl_ilmenite_status
{
public:
  explicit Init_ScienceControl_ilmenite_status(::custom_msgs::msg::ScienceControl & msg)
  : msg_(msg)
  {}
  Init_ScienceControl_deploy_heat ilmenite_status(::custom_msgs::msg::ScienceControl::_ilmenite_status_type arg)
  {
    msg_.ilmenite_status = std::move(arg);
    return Init_ScienceControl_deploy_heat(msg_);
  }

private:
  ::custom_msgs::msg::ScienceControl msg_;
};

class Init_ScienceControl_water_status
{
public:
  explicit Init_ScienceControl_water_status(::custom_msgs::msg::ScienceControl & msg)
  : msg_(msg)
  {}
  Init_ScienceControl_ilmenite_status water_status(::custom_msgs::msg::ScienceControl::_water_status_type arg)
  {
    msg_.water_status = std::move(arg);
    return Init_ScienceControl_ilmenite_status(msg_);
  }

private:
  ::custom_msgs::msg::ScienceControl msg_;
};

class Init_ScienceControl_heat_status
{
public:
  Init_ScienceControl_heat_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScienceControl_water_status heat_status(::custom_msgs::msg::ScienceControl::_heat_status_type arg)
  {
    msg_.heat_status = std::move(arg);
    return Init_ScienceControl_water_status(msg_);
  }

private:
  ::custom_msgs::msg::ScienceControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::ScienceControl>()
{
  return custom_msgs::msg::builder::Init_ScienceControl_heat_status();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__BUILDER_HPP_
