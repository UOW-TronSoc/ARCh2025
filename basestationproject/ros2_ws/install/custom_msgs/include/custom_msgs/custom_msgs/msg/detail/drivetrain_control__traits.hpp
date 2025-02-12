// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/DrivetrainControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/drivetrain_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DrivetrainControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: epoch_time
  {
    out << "epoch_time: ";
    rosidl_generator_traits::value_to_yaml(msg.epoch_time, out);
    out << ", ";
  }

  // member: lf_drive
  {
    out << "lf_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.lf_drive, out);
    out << ", ";
  }

  // member: lb_drive
  {
    out << "lb_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.lb_drive, out);
    out << ", ";
  }

  // member: rb_drive
  {
    out << "rb_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.rb_drive, out);
    out << ", ";
  }

  // member: rf_drive
  {
    out << "rf_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.rf_drive, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DrivetrainControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: epoch_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "epoch_time: ";
    rosidl_generator_traits::value_to_yaml(msg.epoch_time, out);
    out << "\n";
  }

  // member: lf_drive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lf_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.lf_drive, out);
    out << "\n";
  }

  // member: lb_drive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lb_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.lb_drive, out);
    out << "\n";
  }

  // member: rb_drive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rb_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.rb_drive, out);
    out << "\n";
  }

  // member: rf_drive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rf_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.rf_drive, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DrivetrainControl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::msg::DrivetrainControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::DrivetrainControl & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::DrivetrainControl>()
{
  return "custom_msgs::msg::DrivetrainControl";
}

template<>
inline const char * name<custom_msgs::msg::DrivetrainControl>()
{
  return "custom_msgs/msg/DrivetrainControl";
}

template<>
struct has_fixed_size<custom_msgs::msg::DrivetrainControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msgs::msg::DrivetrainControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msgs::msg::DrivetrainControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__TRAITS_HPP_
