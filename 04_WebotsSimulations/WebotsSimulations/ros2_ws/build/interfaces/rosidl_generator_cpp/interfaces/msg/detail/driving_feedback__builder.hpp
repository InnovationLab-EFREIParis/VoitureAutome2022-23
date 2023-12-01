// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/DrivingFeedback.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__BUILDER_HPP_

#include "interfaces/msg/detail/driving_feedback__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_DrivingFeedback_todo
{
public:
  Init_DrivingFeedback_todo()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::DrivingFeedback todo(::interfaces::msg::DrivingFeedback::_todo_type arg)
  {
    msg_.todo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::DrivingFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::DrivingFeedback>()
{
  return interfaces::msg::builder::Init_DrivingFeedback_todo();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__BUILDER_HPP_
