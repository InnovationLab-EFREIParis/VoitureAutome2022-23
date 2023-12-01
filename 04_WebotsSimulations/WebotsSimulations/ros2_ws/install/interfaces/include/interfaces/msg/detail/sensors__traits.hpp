// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/Sensors.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SENSORS__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__SENSORS__TRAITS_HPP_

#include "interfaces/msg/detail/sensors__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::msg::Sensors>()
{
  return "interfaces::msg::Sensors";
}

template<>
inline const char * name<interfaces::msg::Sensors>()
{
  return "interfaces/msg/Sensors";
}

template<>
struct has_fixed_size<interfaces::msg::Sensors>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::msg::Sensors>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::msg::Sensors>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__SENSORS__TRAITS_HPP_
