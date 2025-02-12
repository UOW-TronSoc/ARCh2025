// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/ScienceFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/science_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_ScienceFeedback_ilmenite_percent
{
public:
  explicit Init_ScienceFeedback_ilmenite_percent(::custom_msgs::msg::ScienceFeedback & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::ScienceFeedback ilmenite_percent(::custom_msgs::msg::ScienceFeedback::_ilmenite_percent_type arg)
  {
    msg_.ilmenite_percent = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::ScienceFeedback msg_;
};

class Init_ScienceFeedback_temperature
{
public:
  explicit Init_ScienceFeedback_temperature(::custom_msgs::msg::ScienceFeedback & msg)
  : msg_(msg)
  {}
  Init_ScienceFeedback_ilmenite_percent temperature(::custom_msgs::msg::ScienceFeedback::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_ScienceFeedback_ilmenite_percent(msg_);
  }

private:
  ::custom_msgs::msg::ScienceFeedback msg_;
};

class Init_ScienceFeedback_water_percent
{
public:
  Init_ScienceFeedback_water_percent()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScienceFeedback_temperature water_percent(::custom_msgs::msg::ScienceFeedback::_water_percent_type arg)
  {
    msg_.water_percent = std::move(arg);
    return Init_ScienceFeedback_temperature(msg_);
  }

private:
  ::custom_msgs::msg::ScienceFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::ScienceFeedback>()
{
  return custom_msgs::msg::builder::Init_ScienceFeedback_water_percent();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__BUILDER_HPP_
