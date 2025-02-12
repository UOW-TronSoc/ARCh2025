// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_msgs:msg/DrivetrainFeedback.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_msgs/msg/detail/drivetrain_feedback__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DrivetrainFeedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_msgs::msg::DrivetrainFeedback(_init);
}

void DrivetrainFeedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_msgs::msg::DrivetrainFeedback *>(message_memory);
  typed_message->~DrivetrainFeedback();
}

size_t size_function__DrivetrainFeedback__wheel_position(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DrivetrainFeedback__wheel_position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DrivetrainFeedback__wheel_position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DrivetrainFeedback__wheel_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__DrivetrainFeedback__wheel_position(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__DrivetrainFeedback__wheel_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__DrivetrainFeedback__wheel_position(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__DrivetrainFeedback__wheel_velocity(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DrivetrainFeedback__wheel_velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DrivetrainFeedback__wheel_velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DrivetrainFeedback__wheel_velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__DrivetrainFeedback__wheel_velocity(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__DrivetrainFeedback__wheel_velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__DrivetrainFeedback__wheel_velocity(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__DrivetrainFeedback__wheel_torque(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__DrivetrainFeedback__wheel_torque(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__DrivetrainFeedback__wheel_torque(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__DrivetrainFeedback__wheel_torque(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__DrivetrainFeedback__wheel_torque(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__DrivetrainFeedback__wheel_torque(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__DrivetrainFeedback__wheel_torque(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DrivetrainFeedback_message_member_array[4] = {
  {
    "epoch_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::DrivetrainFeedback, epoch_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "wheel_position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::DrivetrainFeedback, wheel_position),  // bytes offset in struct
    nullptr,  // default value
    size_function__DrivetrainFeedback__wheel_position,  // size() function pointer
    get_const_function__DrivetrainFeedback__wheel_position,  // get_const(index) function pointer
    get_function__DrivetrainFeedback__wheel_position,  // get(index) function pointer
    fetch_function__DrivetrainFeedback__wheel_position,  // fetch(index, &value) function pointer
    assign_function__DrivetrainFeedback__wheel_position,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "wheel_velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::DrivetrainFeedback, wheel_velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__DrivetrainFeedback__wheel_velocity,  // size() function pointer
    get_const_function__DrivetrainFeedback__wheel_velocity,  // get_const(index) function pointer
    get_function__DrivetrainFeedback__wheel_velocity,  // get(index) function pointer
    fetch_function__DrivetrainFeedback__wheel_velocity,  // fetch(index, &value) function pointer
    assign_function__DrivetrainFeedback__wheel_velocity,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "wheel_torque",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::DrivetrainFeedback, wheel_torque),  // bytes offset in struct
    nullptr,  // default value
    size_function__DrivetrainFeedback__wheel_torque,  // size() function pointer
    get_const_function__DrivetrainFeedback__wheel_torque,  // get_const(index) function pointer
    get_function__DrivetrainFeedback__wheel_torque,  // get(index) function pointer
    fetch_function__DrivetrainFeedback__wheel_torque,  // fetch(index, &value) function pointer
    assign_function__DrivetrainFeedback__wheel_torque,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DrivetrainFeedback_message_members = {
  "custom_msgs::msg",  // message namespace
  "DrivetrainFeedback",  // message name
  4,  // number of fields
  sizeof(custom_msgs::msg::DrivetrainFeedback),
  DrivetrainFeedback_message_member_array,  // message members
  DrivetrainFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  DrivetrainFeedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DrivetrainFeedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DrivetrainFeedback_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msgs::msg::DrivetrainFeedback>()
{
  return &::custom_msgs::msg::rosidl_typesupport_introspection_cpp::DrivetrainFeedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msgs, msg, DrivetrainFeedback)() {
  return &::custom_msgs::msg::rosidl_typesupport_introspection_cpp::DrivetrainFeedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
