// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/ScienceFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__ScienceFeedback __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__ScienceFeedback __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ScienceFeedback_
{
  using Type = ScienceFeedback_<ContainerAllocator>;

  explicit ScienceFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->water_percent = 0.0f;
      this->temperature = 0.0f;
      this->ilmenite_percent = 0.0f;
    }
  }

  explicit ScienceFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->water_percent = 0.0f;
      this->temperature = 0.0f;
      this->ilmenite_percent = 0.0f;
    }
  }

  // field types and members
  using _water_percent_type =
    float;
  _water_percent_type water_percent;
  using _temperature_type =
    float;
  _temperature_type temperature;
  using _ilmenite_percent_type =
    float;
  _ilmenite_percent_type ilmenite_percent;

  // setters for named parameter idiom
  Type & set__water_percent(
    const float & _arg)
  {
    this->water_percent = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__ilmenite_percent(
    const float & _arg)
  {
    this->ilmenite_percent = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::ScienceFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::ScienceFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::ScienceFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::ScienceFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__ScienceFeedback
    std::shared_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__ScienceFeedback
    std::shared_ptr<custom_msgs::msg::ScienceFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ScienceFeedback_ & other) const
  {
    if (this->water_percent != other.water_percent) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->ilmenite_percent != other.ilmenite_percent) {
      return false;
    }
    return true;
  }
  bool operator!=(const ScienceFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ScienceFeedback_

// alias to use template instance with default allocator
using ScienceFeedback =
  custom_msgs::msg::ScienceFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SCIENCE_FEEDBACK__STRUCT_HPP_
