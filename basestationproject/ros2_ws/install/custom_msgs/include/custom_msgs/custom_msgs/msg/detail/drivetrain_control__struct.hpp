// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/DrivetrainControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__DrivetrainControl __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__DrivetrainControl __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DrivetrainControl_
{
  using Type = DrivetrainControl_<ContainerAllocator>;

  explicit DrivetrainControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->epoch_time = 0ll;
      this->lf_drive = 0;
      this->lb_drive = 0;
      this->rb_drive = 0;
      this->rf_drive = 0;
    }
  }

  explicit DrivetrainControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->epoch_time = 0ll;
      this->lf_drive = 0;
      this->lb_drive = 0;
      this->rb_drive = 0;
      this->rf_drive = 0;
    }
  }

  // field types and members
  using _epoch_time_type =
    int64_t;
  _epoch_time_type epoch_time;
  using _lf_drive_type =
    int8_t;
  _lf_drive_type lf_drive;
  using _lb_drive_type =
    int8_t;
  _lb_drive_type lb_drive;
  using _rb_drive_type =
    int8_t;
  _rb_drive_type rb_drive;
  using _rf_drive_type =
    int8_t;
  _rf_drive_type rf_drive;

  // setters for named parameter idiom
  Type & set__epoch_time(
    const int64_t & _arg)
  {
    this->epoch_time = _arg;
    return *this;
  }
  Type & set__lf_drive(
    const int8_t & _arg)
  {
    this->lf_drive = _arg;
    return *this;
  }
  Type & set__lb_drive(
    const int8_t & _arg)
  {
    this->lb_drive = _arg;
    return *this;
  }
  Type & set__rb_drive(
    const int8_t & _arg)
  {
    this->rb_drive = _arg;
    return *this;
  }
  Type & set__rf_drive(
    const int8_t & _arg)
  {
    this->rf_drive = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::DrivetrainControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::DrivetrainControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::DrivetrainControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::DrivetrainControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__DrivetrainControl
    std::shared_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__DrivetrainControl
    std::shared_ptr<custom_msgs::msg::DrivetrainControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrivetrainControl_ & other) const
  {
    if (this->epoch_time != other.epoch_time) {
      return false;
    }
    if (this->lf_drive != other.lf_drive) {
      return false;
    }
    if (this->lb_drive != other.lb_drive) {
      return false;
    }
    if (this->rb_drive != other.rb_drive) {
      return false;
    }
    if (this->rf_drive != other.rf_drive) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrivetrainControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrivetrainControl_

// alias to use template instance with default allocator
using DrivetrainControl =
  custom_msgs::msg::DrivetrainControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_CONTROL__STRUCT_HPP_
