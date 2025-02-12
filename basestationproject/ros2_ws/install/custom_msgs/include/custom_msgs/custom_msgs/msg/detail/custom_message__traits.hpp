// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/CustomMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/custom_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CustomMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: epoch_time
  {
    out << "epoch_time: ";
    rosidl_generator_traits::value_to_yaml(msg.epoch_time, out);
    out << ", ";
  }

  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << ", ";
  }

  // member: flag
  {
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
    out << ", ";
  }

  // member: left_drive
  {
    out << "left_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.left_drive, out);
    out << ", ";
  }

  // member: right_drive
  {
    out << "right_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.right_drive, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CustomMessage & msg,
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

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }

  // member: flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
    out << "\n";
  }

  // member: left_drive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.left_drive, out);
    out << "\n";
  }

  // member: right_drive
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_drive: ";
    rosidl_generator_traits::value_to_yaml(msg.right_drive, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CustomMessage & msg, bool use_flow_style = false)
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
  const custom_msgs::msg::CustomMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::CustomMessage & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::CustomMessage>()
{
  return "custom_msgs::msg::CustomMessage";
}

template<>
inline const char * name<custom_msgs::msg::CustomMessage>()
{
  return "custom_msgs/msg/CustomMessage";
}

template<>
struct has_fixed_size<custom_msgs::msg::CustomMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::msg::CustomMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::msg::CustomMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__TRAITS_HPP_
