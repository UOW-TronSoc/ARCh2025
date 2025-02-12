// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/ScienceControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/science_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ScienceControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: heat_status
  {
    out << "heat_status: ";
    rosidl_generator_traits::value_to_yaml(msg.heat_status, out);
    out << ", ";
  }

  // member: water_status
  {
    out << "water_status: ";
    rosidl_generator_traits::value_to_yaml(msg.water_status, out);
    out << ", ";
  }

  // member: ilmenite_status
  {
    out << "ilmenite_status: ";
    rosidl_generator_traits::value_to_yaml(msg.ilmenite_status, out);
    out << ", ";
  }

  // member: deploy_heat
  {
    out << "deploy_heat: ";
    rosidl_generator_traits::value_to_yaml(msg.deploy_heat, out);
    out << ", ";
  }

  // member: deploy_sensors
  {
    out << "deploy_sensors: ";
    rosidl_generator_traits::value_to_yaml(msg.deploy_sensors, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ScienceControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: heat_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heat_status: ";
    rosidl_generator_traits::value_to_yaml(msg.heat_status, out);
    out << "\n";
  }

  // member: water_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "water_status: ";
    rosidl_generator_traits::value_to_yaml(msg.water_status, out);
    out << "\n";
  }

  // member: ilmenite_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ilmenite_status: ";
    rosidl_generator_traits::value_to_yaml(msg.ilmenite_status, out);
    out << "\n";
  }

  // member: deploy_heat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deploy_heat: ";
    rosidl_generator_traits::value_to_yaml(msg.deploy_heat, out);
    out << "\n";
  }

  // member: deploy_sensors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deploy_sensors: ";
    rosidl_generator_traits::value_to_yaml(msg.deploy_sensors, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScienceControl & msg, bool use_flow_style = false)
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
  const custom_msgs::msg::ScienceControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::ScienceControl & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::ScienceControl>()
{
  return "custom_msgs::msg::ScienceControl";
}

template<>
inline const char * name<custom_msgs::msg::ScienceControl>()
{
  return "custom_msgs/msg/ScienceControl";
}

template<>
struct has_fixed_size<custom_msgs::msg::ScienceControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msgs::msg::ScienceControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msgs::msg::ScienceControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__TRAITS_HPP_
