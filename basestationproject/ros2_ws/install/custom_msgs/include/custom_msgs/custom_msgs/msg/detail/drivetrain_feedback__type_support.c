// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msgs:msg/DrivetrainFeedback.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msgs/msg/detail/drivetrain_feedback__rosidl_typesupport_introspection_c.h"
#include "custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msgs/msg/detail/drivetrain_feedback__functions.h"
#include "custom_msgs/msg/detail/drivetrain_feedback__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msgs__msg__DrivetrainFeedback__init(message_memory);
}

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_fini_function(void * message_memory)
{
  custom_msgs__msg__DrivetrainFeedback__fini(message_memory);
}

size_t custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__size_function__DrivetrainFeedback__wheel_position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_position(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_position(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__fetch_function__DrivetrainFeedback__wheel_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_position(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__assign_function__DrivetrainFeedback__wheel_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_position(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__size_function__DrivetrainFeedback__wheel_velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_velocity(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_velocity(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__fetch_function__DrivetrainFeedback__wheel_velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__assign_function__DrivetrainFeedback__wheel_velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__size_function__DrivetrainFeedback__wheel_torque(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_torque(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_torque(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__fetch_function__DrivetrainFeedback__wheel_torque(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_torque(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__assign_function__DrivetrainFeedback__wheel_torque(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_torque(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_member_array[4] = {
  {
    "epoch_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__DrivetrainFeedback, epoch_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wheel_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__DrivetrainFeedback, wheel_position),  // bytes offset in struct
    NULL,  // default value
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__size_function__DrivetrainFeedback__wheel_position,  // size() function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_position,  // get_const(index) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_position,  // get(index) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__fetch_function__DrivetrainFeedback__wheel_position,  // fetch(index, &value) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__assign_function__DrivetrainFeedback__wheel_position,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wheel_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__DrivetrainFeedback, wheel_velocity),  // bytes offset in struct
    NULL,  // default value
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__size_function__DrivetrainFeedback__wheel_velocity,  // size() function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_velocity,  // get_const(index) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_velocity,  // get(index) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__fetch_function__DrivetrainFeedback__wheel_velocity,  // fetch(index, &value) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__assign_function__DrivetrainFeedback__wheel_velocity,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wheel_torque",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__DrivetrainFeedback, wheel_torque),  // bytes offset in struct
    NULL,  // default value
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__size_function__DrivetrainFeedback__wheel_torque,  // size() function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_const_function__DrivetrainFeedback__wheel_torque,  // get_const(index) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__get_function__DrivetrainFeedback__wheel_torque,  // get(index) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__fetch_function__DrivetrainFeedback__wheel_torque,  // fetch(index, &value) function pointer
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__assign_function__DrivetrainFeedback__wheel_torque,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_members = {
  "custom_msgs__msg",  // message namespace
  "DrivetrainFeedback",  // message name
  4,  // number of fields
  sizeof(custom_msgs__msg__DrivetrainFeedback),
  custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_member_array,  // message members
  custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_type_support_handle = {
  0,
  &custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, msg, DrivetrainFeedback)() {
  if (!custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_type_support_handle.typesupport_identifier) {
    custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msgs__msg__DrivetrainFeedback__rosidl_typesupport_introspection_c__DrivetrainFeedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
