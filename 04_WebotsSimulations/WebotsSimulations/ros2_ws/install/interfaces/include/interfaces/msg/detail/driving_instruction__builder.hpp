// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/DrivingInstruction.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__BUILDER_HPP_

#include "interfaces/msg/detail/driving_instruction__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_DrivingInstruction_lidar_scan
{
public:
  Init_DrivingInstruction_lidar_scan()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::DrivingInstruction lidar_scan(::interfaces::msg::DrivingInstruction::_lidar_scan_type arg)
  {
    msg_.lidar_scan = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::DrivingInstruction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::DrivingInstruction>()
{
  return interfaces::msg::builder::Init_DrivingInstruction_lidar_scan();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__BUILDER_HPP_
