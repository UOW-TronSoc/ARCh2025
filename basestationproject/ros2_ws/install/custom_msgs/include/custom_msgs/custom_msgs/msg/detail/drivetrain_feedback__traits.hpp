// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/DrivetrainFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/drivetrain_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DrivetrainFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: epoch_time
  {
    out << "epoch_time: ";
    rosidl_generator_traits::value_to_yaml(msg.epoch_time, out);
    out << ", ";
  }

  // member: wheel_position
  {
    if (msg.wheel_position.size() == 0) {
      out << "wheel_position: []";
    } else {
      out << "wheel_position: [";
      size_t pending_items = msg.wheel_position.size();
      for (auto item : msg.wheel_position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: wheel_velocity
  {
    if (msg.wheel_velocity.size() == 0) {
      out << "wheel_velocity: []";
    } else {
      out << "wheel_velocity: [";
      size_t pending_items = msg.wheel_velocity.size();
      for (auto item : msg.wheel_velocity) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: wheel_torque
  {
    if (msg.wheel_torque.size() == 0) {
      out << "wheel_torque: []";
    } else {
      out << "wheel_torque: [";
      size_t pending_items = msg.wheel_torque.size();
      for (auto item : msg.wheel_torque) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DrivetrainFeedback & msg,
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

  // member: wheel_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.wheel_position.size() == 0) {
      out << "wheel_position: []\n";
    } else {
      out << "wheel_position:\n";
      for (auto item : msg.wheel_position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: wheel_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.wheel_velocity.size() == 0) {
      out << "wheel_velocity: []\n";
    } else {
      out << "wheel_velocity:\n";
      for (auto item : msg.wheel_velocity) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: wheel_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.wheel_torque.size() == 0) {
      out << "wheel_torque: []\n";
    } else {
      out << "wheel_torque:\n";
      for (auto item : msg.wheel_torque) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DrivetrainFeedback & msg, bool use_flow_style = false)
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
  const custom_msgs::msg::DrivetrainFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::DrivetrainFeedback & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::DrivetrainFeedback>()
{
  return "custom_msgs::msg::DrivetrainFeedback";
}

template<>
inline const char * name<custom_msgs::msg::DrivetrainFeedback>()
{
  return "custom_msgs/msg/DrivetrainFeedback";
}

template<>
struct has_fixed_size<custom_msgs::msg::DrivetrainFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msgs::msg::DrivetrainFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msgs::msg::DrivetrainFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__TRAITS_HPP_
