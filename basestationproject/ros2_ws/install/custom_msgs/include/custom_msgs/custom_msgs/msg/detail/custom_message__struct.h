// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/CustomMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CustomMessage in the package custom_msgs.
typedef struct custom_msgs__msg__CustomMessage
{
  int64_t epoch_time;
  rosidl_runtime_c__String data;
  bool flag;
  int8_t left_drive;
  int8_t right_drive;
} custom_msgs__msg__CustomMessage;

// Struct for a sequence of custom_msgs__msg__CustomMessage.
typedef struct custom_msgs__msg__CustomMessage__Sequence
{
  custom_msgs__msg__CustomMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__CustomMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_H_
