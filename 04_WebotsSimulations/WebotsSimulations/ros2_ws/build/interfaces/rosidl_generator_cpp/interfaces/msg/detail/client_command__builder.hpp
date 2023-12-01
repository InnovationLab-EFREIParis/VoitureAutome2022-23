// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/ClientCommand.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__CLIENT_COMMAND__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__CLIENT_COMMAND__BUILDER_HPP_

#include "interfaces/msg/detail/client_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_ClientCommand_left
{
public:
  explicit Init_ClientCommand_left(::interfaces::msg::ClientCommand & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::ClientCommand left(::interfaces::msg::ClientCommand::_left_type arg)
  {
    msg_.left = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::ClientCommand msg_;
};

class Init_ClientCommand_right
{
public:
  explicit Init_ClientCommand_right(::interfaces::msg::ClientCommand & msg)
  : msg_(msg)
  {}
  Init_ClientCommand_left right(::interfaces::msg::ClientCommand::_right_type arg)
  {
    msg_.right = std::move(arg);
    return Init_ClientCommand_left(msg_);
  }

private:
  ::interfaces::msg::ClientCommand msg_;
};

class Init_ClientCommand_down
{
public:
  explicit Init_ClientCommand_down(::interfaces::msg::ClientCommand & msg)
  : msg_(msg)
  {}
  Init_ClientCommand_right down(::interfaces::msg::ClientCommand::_down_type arg)
  {
    msg_.down = std::move(arg);
    return Init_ClientCommand_right(msg_);
  }

private:
  ::interfaces::msg::ClientCommand msg_;
};

class Init_ClientCommand_up
{
public:
  Init_ClientCommand_up()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ClientCommand_down up(::interfaces::msg::ClientCommand::_up_type arg)
  {
    msg_.up = std::move(arg);
    return Init_ClientCommand_down(msg_);
  }

private:
  ::interfaces::msg::ClientCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::ClientCommand>()
{
  return interfaces::msg::builder::Init_ClientCommand_up();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__CLIENT_COMMAND__BUILDER_HPP_
