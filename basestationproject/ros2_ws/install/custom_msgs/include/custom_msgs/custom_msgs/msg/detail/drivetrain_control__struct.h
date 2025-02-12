// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/DrivetrainControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/DrivetrainControl in the package custom_msgs.
typedef struct custom_msgs__msg__DrivetrainControl
{
  int64_t epoch_time;
  int8_t lf_drive;
  int8_t lb_drive;
  int8_t rb_drive;
  int8_t rf_drive;
} custom_msgs__msg__DrivetrainControl;

// Struct for a sequence of custom_msgs__msg__DrivetrainControl.
typedef struct custom_msgs__msg__DrivetrainControl__Sequence
{
  custom_msgs__msg__DrivetrainControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__DrivetrainControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__STRUCT_H_
