// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Sensors.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SENSORS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__SENSORS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Sensors __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Sensors __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Sensors_
{
  using Type = Sensors_<ContainerAllocator>;

  explicit Sensors_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->example_sensor1_name = "";
      this->example_sensor1_value = 0ll;
      this->example_sensor2_name = "";
      this->example_sensor2_value = 0ll;
      this->example_sensor3_name = "";
      this->example_sensor3_value = 0ll;
    }
  }

  explicit Sensors_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : example_sensor1_name(_alloc),
    example_sensor2_name(_alloc),
    example_sensor3_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->example_sensor1_name = "";
      this->example_sensor1_value = 0ll;
      this->example_sensor2_name = "";
      this->example_sensor2_value = 0ll;
      this->example_sensor3_name = "";
      this->example_sensor3_value = 0ll;
    }
  }

  // field types and members
  using _example_sensor1_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _example_sensor1_name_type example_sensor1_name;
  using _example_sensor1_value_type =
    int64_t;
  _example_sensor1_value_type example_sensor1_value;
  using _example_sensor2_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _example_sensor2_name_type example_sensor2_name;
  using _example_sensor2_value_type =
    int64_t;
  _example_sensor2_value_type example_sensor2_value;
  using _example_sensor3_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _example_sensor3_name_type example_sensor3_name;
  using _example_sensor3_value_type =
    int64_t;
  _example_sensor3_value_type example_sensor3_value;

  // setters for named parameter idiom
  Type & set__example_sensor1_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->example_sensor1_name = _arg;
    return *this;
  }
  Type & set__example_sensor1_value(
    const int64_t & _arg)
  {
    this->example_sensor1_value = _arg;
    return *this;
  }
  Type & set__example_sensor2_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->example_sensor2_name = _arg;
    return *this;
  }
  Type & set__example_sensor2_value(
    const int64_t & _arg)
  {
    this->example_sensor2_value = _arg;
    return *this;
  }
  Type & set__example_sensor3_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->example_sensor3_name = _arg;
    return *this;
  }
  Type & set__example_sensor3_value(
    const int64_t & _arg)
  {
    this->example_sensor3_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Sensors_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Sensors_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Sensors_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Sensors_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Sensors_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Sensors_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Sensors_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Sensors_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Sensors_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Sensors_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Sensors
    std::shared_ptr<interfaces::msg::Sensors_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Sensors
    std::shared_ptr<interfaces::msg::Sensors_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Sensors_ & other) const
  {
    if (this->example_sensor1_name != other.example_sensor1_name) {
      return false;
    }
    if (this->example_sensor1_value != other.example_sensor1_value) {
      return false;
    }
    if (this->example_sensor2_name != other.example_sensor2_name) {
      return false;
    }
    if (this->example_sensor2_value != other.example_sensor2_value) {
      return false;
    }
    if (this->example_sensor3_name != other.example_sensor3_name) {
      return false;
    }
    if (this->example_sensor3_value != other.example_sensor3_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Sensors_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Sensors_

// alias to use template instance with default allocator
using Sensors =
  interfaces::msg::Sensors_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__SENSORS__STRUCT_HPP_
