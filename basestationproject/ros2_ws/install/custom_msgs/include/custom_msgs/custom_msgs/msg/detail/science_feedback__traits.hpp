// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/ScienceFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/science_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ScienceFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: water_percent
  {
    out << "water_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.water_percent, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: ilmenite_percent
  {
    out << "ilmenite_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.ilmenite_percent, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ScienceFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: water_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "water_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.water_percent, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: ilmenite_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ilmenite_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.ilmenite_percent, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScienceFeedback & msg, bool use_flow_style = false)
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
  const custom_msgs::msg::ScienceFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::ScienceFeedback & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::ScienceFeedback>()
{
  return "custom_msgs::msg::ScienceFeedback";
}

template<>
inline const char * name<custom_msgs::msg::ScienceFeedback>()
{
  return "custom_msgs/msg/ScienceFeedback";
}

template<>
struct has_fixed_size<custom_msgs::msg::ScienceFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msgs::msg::ScienceFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msgs::msg::ScienceFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__TRAITS_HPP_
