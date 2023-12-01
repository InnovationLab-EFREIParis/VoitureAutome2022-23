// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/MonAckermannDrive.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__MonAckermannDrive __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__MonAckermannDrive __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MonAckermannDrive_
{
  using Type = MonAckermannDrive_<ContainerAllocator>;

  explicit MonAckermannDrive_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steering_angle = 0.0f;
      this->steering_angle_velocity = 0.0f;
      this->speed = 0.0f;
      this->acceleration = 0.0f;
      this->jerk = 0.0f;
    }
  }

  explicit MonAckermannDrive_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steering_angle = 0.0f;
      this->steering_angle_velocity = 0.0f;
      this->speed = 0.0f;
      this->acceleration = 0.0f;
      this->jerk = 0.0f;
    }
  }

  // field types and members
  using _steering_angle_type =
    float;
  _steering_angle_type steering_angle;
  using _steering_angle_velocity_type =
    float;
  _steering_angle_velocity_type steering_angle_velocity;
  using _speed_type =
    float;
  _speed_type speed;
  using _acceleration_type =
    float;
  _acceleration_type acceleration;
  using _jerk_type =
    float;
  _jerk_type jerk;

  // setters for named parameter idiom
  Type & set__steering_angle(
    const float & _arg)
  {
    this->steering_angle = _arg;
    return *this;
  }
  Type & set__steering_angle_velocity(
    const float & _arg)
  {
    this->steering_angle_velocity = _arg;
    return *this;
  }
  Type & set__speed(
    const float & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__acceleration(
    const float & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__jerk(
    const float & _arg)
  {
    this->jerk = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::MonAckermannDrive_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::MonAckermannDrive_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::MonAckermannDrive_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::MonAckermannDrive_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__MonAckermannDrive
    std::shared_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__MonAckermannDrive
    std::shared_ptr<interfaces::msg::MonAckermannDrive_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MonAckermannDrive_ & other) const
  {
    if (this->steering_angle != other.steering_angle) {
      return false;
    }
    if (this->steering_angle_velocity != other.steering_angle_velocity) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->jerk != other.jerk) {
      return false;
    }
    return true;
  }
  bool operator!=(const MonAckermannDrive_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MonAckermannDrive_

// alias to use template instance with default allocator
using MonAckermannDrive =
  interfaces::msg::MonAckermannDrive_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__STRUCT_HPP_
