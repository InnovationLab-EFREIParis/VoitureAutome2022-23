// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/DrivingFeedback.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__DrivingFeedback __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__DrivingFeedback __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DrivingFeedback_
{
  using Type = DrivingFeedback_<ContainerAllocator>;

  explicit DrivingFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->todo = "";
    }
  }

  explicit DrivingFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : todo(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->todo = "";
    }
  }

  // field types and members
  using _todo_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _todo_type todo;

  // setters for named parameter idiom
  Type & set__todo(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->todo = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::DrivingFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::DrivingFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::DrivingFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::DrivingFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__DrivingFeedback
    std::shared_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__DrivingFeedback
    std::shared_ptr<interfaces::msg::DrivingFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrivingFeedback_ & other) const
  {
    if (this->todo != other.todo) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrivingFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrivingFeedback_

// alias to use template instance with default allocator
using DrivingFeedback =
  interfaces::msg::DrivingFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__STRUCT_HPP_
