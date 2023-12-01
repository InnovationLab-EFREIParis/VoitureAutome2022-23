// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/RaceParams.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__RACE_PARAMS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__RACE_PARAMS__BUILDER_HPP_

#include "interfaces/msg/detail/race_params__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_RaceParams_steering
{
public:
  explicit Init_RaceParams_steering(::interfaces::msg::RaceParams & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::RaceParams steering(::interfaces::msg::RaceParams::_steering_type arg)
  {
    msg_.steering = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::RaceParams msg_;
};

class Init_RaceParams_speed
{
public:
  Init_RaceParams_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RaceParams_steering speed(::interfaces::msg::RaceParams::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_RaceParams_steering(msg_);
  }

private:
  ::interfaces::msg::RaceParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::RaceParams>()
{
  return interfaces::msg::builder::Init_RaceParams_speed();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__RACE_PARAMS__BUILDER_HPP_
