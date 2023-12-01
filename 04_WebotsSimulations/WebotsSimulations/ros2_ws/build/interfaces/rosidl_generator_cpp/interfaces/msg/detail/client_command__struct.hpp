// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/ClientCommand.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__CLIENT_COMMAND__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__CLIENT_COMMAND__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__ClientCommand __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__ClientCommand __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ClientCommand_
{
  using Type = ClientCommand_<ContainerAllocator>;

  explicit ClientCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->up = false;
      this->down = false;
      this->right = false;
      this->left = false;
    }
  }

  explicit ClientCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->up = false;
      this->down = false;
      this->right = false;
      this->left = false;
    }
  }

  // field types and members
  using _up_type =
    bool;
  _up_type up;
  using _down_type =
    bool;
  _down_type down;
  using _right_type =
    bool;
  _right_type right;
  using _left_type =
    bool;
  _left_type left;

  // setters for named parameter idiom
  Type & set__up(
    const bool & _arg)
  {
    this->up = _arg;
    return *this;
  }
  Type & set__down(
    const bool & _arg)
  {
    this->down = _arg;
    return *this;
  }
  Type & set__right(
    const bool & _arg)
  {
    this->right = _arg;
    return *this;
  }
  Type & set__left(
    const bool & _arg)
  {
    this->left = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::ClientCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::ClientCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::ClientCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::ClientCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::ClientCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::ClientCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::ClientCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::ClientCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::ClientCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::ClientCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__ClientCommand
    std::shared_ptr<interfaces::msg::ClientCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__ClientCommand
    std::shared_ptr<interfaces::msg::ClientCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ClientCommand_ & other) const
  {
    if (this->up != other.up) {
      return false;
    }
    if (this->down != other.down) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    if (this->left != other.left) {
      return false;
    }
    return true;
  }
  bool operator!=(const ClientCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ClientCommand_

// alias to use template instance with default allocator
using ClientCommand =
  interfaces::msg::ClientCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__CLIENT_COMMAND__STRUCT_HPP_
