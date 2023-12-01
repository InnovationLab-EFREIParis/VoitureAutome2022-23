// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Sensors.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SENSORS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__SENSORS__BUILDER_HPP_

#include "interfaces/msg/detail/sensors__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Sensors_example_sensor3_value
{
public:
  explicit Init_Sensors_example_sensor3_value(::interfaces::msg::Sensors & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Sensors example_sensor3_value(::interfaces::msg::Sensors::_example_sensor3_value_type arg)
  {
    msg_.example_sensor3_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Sensors msg_;
};

class Init_Sensors_example_sensor3_name
{
public:
  explicit Init_Sensors_example_sensor3_name(::interfaces::msg::Sensors & msg)
  : msg_(msg)
  {}
  Init_Sensors_example_sensor3_value example_sensor3_name(::interfaces::msg::Sensors::_example_sensor3_name_type arg)
  {
    msg_.example_sensor3_name = std::move(arg);
    return Init_Sensors_example_sensor3_value(msg_);
  }

private:
  ::interfaces::msg::Sensors msg_;
};

class Init_Sensors_example_sensor2_value
{
public:
  explicit Init_Sensors_example_sensor2_value(::interfaces::msg::Sensors & msg)
  : msg_(msg)
  {}
  Init_Sensors_example_sensor3_name example_sensor2_value(::interfaces::msg::Sensors::_example_sensor2_value_type arg)
  {
    msg_.example_sensor2_value = std::move(arg);
    return Init_Sensors_example_sensor3_name(msg_);
  }

private:
  ::interfaces::msg::Sensors msg_;
};

class Init_Sensors_example_sensor2_name
{
public:
  explicit Init_Sensors_example_sensor2_name(::interfaces::msg::Sensors & msg)
  : msg_(msg)
  {}
  Init_Sensors_example_sensor2_value example_sensor2_name(::interfaces::msg::Sensors::_example_sensor2_name_type arg)
  {
    msg_.example_sensor2_name = std::move(arg);
    return Init_Sensors_example_sensor2_value(msg_);
  }

private:
  ::interfaces::msg::Sensors msg_;
};

class Init_Sensors_example_sensor1_value
{
public:
  explicit Init_Sensors_example_sensor1_value(::interfaces::msg::Sensors & msg)
  : msg_(msg)
  {}
  Init_Sensors_example_sensor2_name example_sensor1_value(::interfaces::msg::Sensors::_example_sensor1_value_type arg)
  {
    msg_.example_sensor1_value = std::move(arg);
    return Init_Sensors_example_sensor2_name(msg_);
  }

private:
  ::interfaces::msg::Sensors msg_;
};

class Init_Sensors_example_sensor1_name
{
public:
  Init_Sensors_example_sensor1_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sensors_example_sensor1_value example_sensor1_name(::interfaces::msg::Sensors::_example_sensor1_name_type arg)
  {
    msg_.example_sensor1_name = std::move(arg);
    return Init_Sensors_example_sensor1_value(msg_);
  }

private:
  ::interfaces::msg::Sensors msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Sensors>()
{
  return interfaces::msg::builder::Init_Sensors_example_sensor1_name();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__SENSORS__BUILDER_HPP_
