// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/ScienceControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__ScienceControl __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__ScienceControl __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ScienceControl_
{
  using Type = ScienceControl_<ContainerAllocator>;

  explicit ScienceControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heat_status = false;
      this->water_status = false;
      this->ilmenite_status = false;
      this->deploy_heat = false;
      this->deploy_sensors = false;
    }
  }

  explicit ScienceControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heat_status = false;
      this->water_status = false;
      this->ilmenite_status = false;
      this->deploy_heat = false;
      this->deploy_sensors = false;
    }
  }

  // field types and members
  using _heat_status_type =
    bool;
  _heat_status_type heat_status;
  using _water_status_type =
    bool;
  _water_status_type water_status;
  using _ilmenite_status_type =
    bool;
  _ilmenite_status_type ilmenite_status;
  using _deploy_heat_type =
    bool;
  _deploy_heat_type deploy_heat;
  using _deploy_sensors_type =
    bool;
  _deploy_sensors_type deploy_sensors;

  // setters for named parameter idiom
  Type & set__heat_status(
    const bool & _arg)
  {
    this->heat_status = _arg;
    return *this;
  }
  Type & set__water_status(
    const bool & _arg)
  {
    this->water_status = _arg;
    return *this;
  }
  Type & set__ilmenite_status(
    const bool & _arg)
  {
    this->ilmenite_status = _arg;
    return *this;
  }
  Type & set__deploy_heat(
    const bool & _arg)
  {
    this->deploy_heat = _arg;
    return *this;
  }
  Type & set__deploy_sensors(
    const bool & _arg)
  {
    this->deploy_sensors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::ScienceControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::ScienceControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::ScienceControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::ScienceControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__ScienceControl
    std::shared_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__ScienceControl
    std::shared_ptr<custom_msgs::msg::ScienceControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ScienceControl_ & other) const
  {
    if (this->heat_status != other.heat_status) {
      return false;
    }
    if (this->water_status != other.water_status) {
      return false;
    }
    if (this->ilmenite_status != other.ilmenite_status) {
      return false;
    }
    if (this->deploy_heat != other.deploy_heat) {
      return false;
    }
    if (this->deploy_sensors != other.deploy_sensors) {
      return false;
    }
    return true;
  }
  bool operator!=(const ScienceControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ScienceControl_

// alias to use template instance with default allocator
using ScienceControl =
  custom_msgs::msg::ScienceControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SCIENCE_CONTROL__STRUCT_HPP_
