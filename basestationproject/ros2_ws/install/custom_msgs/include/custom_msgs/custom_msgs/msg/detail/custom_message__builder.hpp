// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/CustomMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/custom_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_CustomMessage_right_drive
{
public:
  explicit Init_CustomMessage_right_drive(::custom_msgs::msg::CustomMessage & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::CustomMessage right_drive(::custom_msgs::msg::CustomMessage::_right_drive_type arg)
  {
    msg_.right_drive = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::CustomMessage msg_;
};

class Init_CustomMessage_left_drive
{
public:
  explicit Init_CustomMessage_left_drive(::custom_msgs::msg::CustomMessage & msg)
  : msg_(msg)
  {}
  Init_CustomMessage_right_drive left_drive(::custom_msgs::msg::CustomMessage::_left_drive_type arg)
  {
    msg_.left_drive = std::move(arg);
    return Init_CustomMessage_right_drive(msg_);
  }

private:
  ::custom_msgs::msg::CustomMessage msg_;
};

class Init_CustomMessage_flag
{
public:
  explicit Init_CustomMessage_flag(::custom_msgs::msg::CustomMessage & msg)
  : msg_(msg)
  {}
  Init_CustomMessage_left_drive flag(::custom_msgs::msg::CustomMessage::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return Init_CustomMessage_left_drive(msg_);
  }

private:
  ::custom_msgs::msg::CustomMessage msg_;
};

class Init_CustomMessage_data
{
public:
  explicit Init_CustomMessage_data(::custom_msgs::msg::CustomMessage & msg)
  : msg_(msg)
  {}
  Init_CustomMessage_flag data(::custom_msgs::msg::CustomMessage::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_CustomMessage_flag(msg_);
  }

private:
  ::custom_msgs::msg::CustomMessage msg_;
};

class Init_CustomMessage_epoch_time
{
public:
  Init_CustomMessage_epoch_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CustomMessage_data epoch_time(::custom_msgs::msg::CustomMessage::_epoch_time_type arg)
  {
    msg_.epoch_time = std::move(arg);
    return Init_CustomMessage_data(msg_);
  }

private:
  ::custom_msgs::msg::CustomMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::CustomMessage>()
{
  return custom_msgs::msg::builder::Init_CustomMessage_epoch_time();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__BUILDER_HPP_
