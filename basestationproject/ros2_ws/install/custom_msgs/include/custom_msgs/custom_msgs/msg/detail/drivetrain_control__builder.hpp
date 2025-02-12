// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/DrivetrainControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/drivetrain_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_DrivetrainControl_rf_drive
{
public:
  explicit Init_DrivetrainControl_rf_drive(::custom_msgs::msg::DrivetrainControl & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::DrivetrainControl rf_drive(::custom_msgs::msg::DrivetrainControl::_rf_drive_type arg)
  {
    msg_.rf_drive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainControl msg_;
};

class Init_DrivetrainControl_rb_drive
{
public:
  explicit Init_DrivetrainControl_rb_drive(::custom_msgs::msg::DrivetrainControl & msg)
  : msg_(msg)
  {}
  Init_DrivetrainControl_rf_drive rb_drive(::custom_msgs::msg::DrivetrainControl::_rb_drive_type arg)
  {
    msg_.rb_drive = std::move(arg);
    return Init_DrivetrainControl_rf_drive(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainControl msg_;
};

class Init_DrivetrainControl_lb_drive
{
public:
  explicit Init_DrivetrainControl_lb_drive(::custom_msgs::msg::DrivetrainControl & msg)
  : msg_(msg)
  {}
  Init_DrivetrainControl_rb_drive lb_drive(::custom_msgs::msg::DrivetrainControl::_lb_drive_type arg)
  {
    msg_.lb_drive = std::move(arg);
    return Init_DrivetrainControl_rb_drive(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainControl msg_;
};

class Init_DrivetrainControl_lf_drive
{
public:
  explicit Init_DrivetrainControl_lf_drive(::custom_msgs::msg::DrivetrainControl & msg)
  : msg_(msg)
  {}
  Init_DrivetrainControl_lb_drive lf_drive(::custom_msgs::msg::DrivetrainControl::_lf_drive_type arg)
  {
    msg_.lf_drive = std::move(arg);
    return Init_DrivetrainControl_lb_drive(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainControl msg_;
};

class Init_DrivetrainControl_epoch_time
{
public:
  Init_DrivetrainControl_epoch_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DrivetrainControl_lf_drive epoch_time(::custom_msgs::msg::DrivetrainControl::_epoch_time_type arg)
  {
    msg_.epoch_time = std::move(arg);
    return Init_DrivetrainControl_lf_drive(msg_);
  }

private:
  ::custom_msgs::msg::DrivetrainControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::DrivetrainControl>()
{
  return custom_msgs::msg::builder::Init_DrivetrainControl_epoch_time();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__BUILDER_HPP_
