// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/DrivingResult.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_RESULT__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__DRIVING_RESULT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'instruction'
#include "interfaces/msg/detail/mon_ackermann_drive__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__msg__DrivingResult __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__DrivingResult __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DrivingResult_
{
  using Type = DrivingResult_<ContainerAllocator>;

  explicit DrivingResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : instruction(_init)
  {
    (void)_init;
  }

  explicit DrivingResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : instruction(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _instruction_type =
    interfaces::msg::MonAckermannDrive_<ContainerAllocator>;
  _instruction_type instruction;

  // setters for named parameter idiom
  Type & set__instruction(
    const interfaces::msg::MonAckermannDrive_<ContainerAllocator> & _arg)
  {
    this->instruction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::DrivingResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::DrivingResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::DrivingResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::DrivingResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::DrivingResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::DrivingResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::DrivingResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::DrivingResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::DrivingResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::DrivingResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__DrivingResult
    std::shared_ptr<interfaces::msg::DrivingResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__DrivingResult
    std::shared_ptr<interfaces::msg::DrivingResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrivingResult_ & other) const
  {
    if (this->instruction != other.instruction) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrivingResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrivingResult_

// alias to use template instance with default allocator
using DrivingResult =
  interfaces::msg::DrivingResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DRIVING_RESULT__STRUCT_HPP_
