// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/DrivingInstruction.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__DrivingInstruction __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__DrivingInstruction __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DrivingInstruction_
{
  using Type = DrivingInstruction_<ContainerAllocator>;

  explicit DrivingInstruction_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DrivingInstruction_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _lidar_scan_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _lidar_scan_type lidar_scan;

  // setters for named parameter idiom
  Type & set__lidar_scan(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->lidar_scan = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::DrivingInstruction_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::DrivingInstruction_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::DrivingInstruction_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::DrivingInstruction_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__DrivingInstruction
    std::shared_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__DrivingInstruction
    std::shared_ptr<interfaces::msg::DrivingInstruction_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrivingInstruction_ & other) const
  {
    if (this->lidar_scan != other.lidar_scan) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrivingInstruction_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrivingInstruction_

// alias to use template instance with default allocator
using DrivingInstruction =
  interfaces::msg::DrivingInstruction_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__STRUCT_HPP_
