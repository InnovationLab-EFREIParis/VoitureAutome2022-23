// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/RaceParams.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__RACE_PARAMS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__RACE_PARAMS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__RaceParams __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__RaceParams __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RaceParams_
{
  using Type = RaceParams_<ContainerAllocator>;

  explicit RaceParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0ll;
      this->steering = 0ll;
    }
  }

  explicit RaceParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0ll;
      this->steering = 0ll;
    }
  }

  // field types and members
  using _speed_type =
    int64_t;
  _speed_type speed;
  using _steering_type =
    int64_t;
  _steering_type steering;

  // setters for named parameter idiom
  Type & set__speed(
    const int64_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__steering(
    const int64_t & _arg)
  {
    this->steering = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::RaceParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::RaceParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::RaceParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::RaceParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::RaceParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::RaceParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::RaceParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::RaceParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::RaceParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::RaceParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__RaceParams
    std::shared_ptr<interfaces::msg::RaceParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__RaceParams
    std::shared_ptr<interfaces::msg::RaceParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RaceParams_ & other) const
  {
    if (this->speed != other.speed) {
      return false;
    }
    if (this->steering != other.steering) {
      return false;
    }
    return true;
  }
  bool operator!=(const RaceParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RaceParams_

// alias to use template instance with default allocator
using RaceParams =
  interfaces::msg::RaceParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__RACE_PARAMS__STRUCT_HPP_
