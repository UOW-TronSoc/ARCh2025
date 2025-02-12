// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/DrivetrainFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__DrivetrainFeedback __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__DrivetrainFeedback __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DrivetrainFeedback_
{
  using Type = DrivetrainFeedback_<ContainerAllocator>;

  explicit DrivetrainFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->epoch_time = 0ll;
      std::fill<typename std::array<float, 4>::iterator, float>(this->wheel_position.begin(), this->wheel_position.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->wheel_velocity.begin(), this->wheel_velocity.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->wheel_torque.begin(), this->wheel_torque.end(), 0.0f);
    }
  }

  explicit DrivetrainFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : wheel_position(_alloc),
    wheel_velocity(_alloc),
    wheel_torque(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->epoch_time = 0ll;
      std::fill<typename std::array<float, 4>::iterator, float>(this->wheel_position.begin(), this->wheel_position.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->wheel_velocity.begin(), this->wheel_velocity.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->wheel_torque.begin(), this->wheel_torque.end(), 0.0f);
    }
  }

  // field types and members
  using _epoch_time_type =
    int64_t;
  _epoch_time_type epoch_time;
  using _wheel_position_type =
    std::array<float, 4>;
  _wheel_position_type wheel_position;
  using _wheel_velocity_type =
    std::array<float, 4>;
  _wheel_velocity_type wheel_velocity;
  using _wheel_torque_type =
    std::array<float, 4>;
  _wheel_torque_type wheel_torque;

  // setters for named parameter idiom
  Type & set__epoch_time(
    const int64_t & _arg)
  {
    this->epoch_time = _arg;
    return *this;
  }
  Type & set__wheel_position(
    const std::array<float, 4> & _arg)
  {
    this->wheel_position = _arg;
    return *this;
  }
  Type & set__wheel_velocity(
    const std::array<float, 4> & _arg)
  {
    this->wheel_velocity = _arg;
    return *this;
  }
  Type & set__wheel_torque(
    const std::array<float, 4> & _arg)
  {
    this->wheel_torque = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__DrivetrainFeedback
    std::shared_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__DrivetrainFeedback
    std::shared_ptr<custom_msgs::msg::DrivetrainFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrivetrainFeedback_ & other) const
  {
    if (this->epoch_time != other.epoch_time) {
      return false;
    }
    if (this->wheel_position != other.wheel_position) {
      return false;
    }
    if (this->wheel_velocity != other.wheel_velocity) {
      return false;
    }
    if (this->wheel_torque != other.wheel_torque) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrivetrainFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrivetrainFeedback_

// alias to use template instance with default allocator
using DrivetrainFeedback =
  custom_msgs::msg::DrivetrainFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DRIVETRAIN_FEEDBACK__STRUCT_HPP_
