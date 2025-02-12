// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/DrivetrainFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/DrivetrainFeedback in the package custom_msgs.
typedef struct custom_msgs__msg__DrivetrainFeedback
{
  int64_t epoch_time;
  float wheel_position[4];
  float wheel_velocity[4];
  float wheel_torque[4];
} custom_msgs__msg__DrivetrainFeedback;

// Struct for a sequence of custom_msgs__msg__DrivetrainFeedback.
typedef struct custom_msgs__msg__DrivetrainFeedback__Sequence
{
  custom_msgs__msg__DrivetrainFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__DrivetrainFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__STRUCT_H_
