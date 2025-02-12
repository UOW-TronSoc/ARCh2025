// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/DrivetrainFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/drivetrain_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_DrivetrainFeedback_wheel_torque
{
public:
  explicit Init_DrivetrainFeedback_wheel_torque(::custom_msgs::msg::DrivetrainFeedback & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::DrivetrainFeedback wheel_torque(::custom_msgs::msg::DrivetrainFeedback::_wheel_torque_type arg)
  {
    msg_.wheel_torque = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainFeedback msg_;
};

class Init_DrivetrainFeedback_wheel_velocity
{
public:
  explicit Init_DrivetrainFeedback_wheel_velocity(::custom_msgs::msg::DrivetrainFeedback & msg)
  : msg_(msg)
  {}
  Init_DrivetrainFeedback_wheel_torque wheel_velocity(::custom_msgs::msg::DrivetrainFeedback::_wheel_velocity_type arg)
  {
    msg_.wheel_velocity = std::move(arg);
    return Init_DrivetrainFeedback_wheel_torque(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainFeedback msg_;
};

class Init_DrivetrainFeedback_wheel_position
{
public:
  explicit Init_DrivetrainFeedback_wheel_position(::custom_msgs::msg::DrivetrainFeedback & msg)
  : msg_(msg)
  {}
  Init_DrivetrainFeedback_wheel_velocity wheel_position(::custom_msgs::msg::DrivetrainFeedback::_wheel_position_type arg)
  {
    msg_.wheel_position = std::move(arg);
    return Init_DrivetrainFeedback_wheel_velocity(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainFeedback msg_;
};

class Init_DrivetrainFeedback_epoch_time
{
public:
  Init_DrivetrainFeedback_epoch_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DrivetrainFeedback_wheel_position epoch_time(::custom_msgs::msg::DrivetrainFeedback::_epoch_time_type arg)
  {
    msg_.epoch_time = std::move(arg);
    return Init_DrivetrainFeedback_wheel_position(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::DrivetrainFeedback>()
{
  return custom_msgs::msg::builder::Init_DrivetrainFeedback_epoch_time();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__BUILDER_HPP_
