// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/MonAckermannDrive.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__BUILDER_HPP_

#include "interfaces/msg/detail/mon_ackermann_drive__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_MonAckermannDrive_jerk
{
public:
  explicit Init_MonAckermannDrive_jerk(::interfaces::msg::MonAckermannDrive & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::MonAckermannDrive jerk(::interfaces::msg::MonAckermannDrive::_jerk_type arg)
  {
    msg_.jerk = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::MonAckermannDrive msg_;
};

class Init_MonAckermannDrive_acceleration
{
public:
  explicit Init_MonAckermannDrive_acceleration(::interfaces::msg::MonAckermannDrive & msg)
  : msg_(msg)
  {}
  Init_MonAckermannDrive_jerk acceleration(::interfaces::msg::MonAckermannDrive::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_MonAckermannDrive_jerk(msg_);
  }

private:
  ::interfaces::msg::MonAckermannDrive msg_;
};

class Init_MonAckermannDrive_speed
{
public:
  explicit Init_MonAckermannDrive_speed(::interfaces::msg::MonAckermannDrive & msg)
  : msg_(msg)
  {}
  Init_MonAckermannDrive_acceleration speed(::interfaces::msg::MonAckermannDrive::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_MonAckermannDrive_acceleration(msg_);
  }

private:
  ::interfaces::msg::MonAckermannDrive msg_;
};

class Init_MonAckermannDrive_steering_angle_velocity
{
public:
  explicit Init_MonAckermannDrive_steering_angle_velocity(::interfaces::msg::MonAckermannDrive & msg)
  : msg_(msg)
  {}
  Init_MonAckermannDrive_speed steering_angle_velocity(::interfaces::msg::MonAckermannDrive::_steering_angle_velocity_type arg)
  {
    msg_.steering_angle_velocity = std::move(arg);
    return Init_MonAckermannDrive_speed(msg_);
  }

private:
  ::interfaces::msg::MonAckermannDrive msg_;
};

class Init_MonAckermannDrive_steering_angle
{
public:
  Init_MonAckermannDrive_steering_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MonAckermannDrive_steering_angle_velocity steering_angle(::interfaces::msg::MonAckermannDrive::_steering_angle_type arg)
  {
    msg_.steering_angle = std::move(arg);
    return Init_MonAckermannDrive_steering_angle_velocity(msg_);
  }

private:
  ::interfaces::msg::MonAckermannDrive msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::MonAckermannDrive>()
{
  return interfaces::msg::builder::Init_MonAckermannDrive_steering_angle();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__BUILDER_HPP_
