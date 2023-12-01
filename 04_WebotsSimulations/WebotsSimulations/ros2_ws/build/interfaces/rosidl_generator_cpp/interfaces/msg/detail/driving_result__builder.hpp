// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/DrivingResult.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_RESULT__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__DRIVING_RESULT__BUILDER_HPP_

#include "interfaces/msg/detail/driving_result__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_DrivingResult_instruction
{
public:
  Init_DrivingResult_instruction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::DrivingResult instruction(::interfaces::msg::DrivingResult::_instruction_type arg)
  {
    msg_.instruction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::DrivingResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::DrivingResult>()
{
  return interfaces::msg::builder::Init_DrivingResult_instruction();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DRIVING_RESULT__BUILDER_HPP_
