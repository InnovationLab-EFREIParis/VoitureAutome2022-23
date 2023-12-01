// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/MonAckermannDrive.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__TRAITS_HPP_

#include "interfaces/msg/detail/mon_ackermann_drive__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::msg::MonAckermannDrive>()
{
  return "interfaces::msg::MonAckermannDrive";
}

template<>
inline const char * name<interfaces::msg::MonAckermannDrive>()
{
  return "interfaces/msg/MonAckermannDrive";
}

template<>
struct has_fixed_size<interfaces::msg::MonAckermannDrive>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::MonAckermannDrive>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::MonAckermannDrive>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__MON_ACKERMANN_DRIVE__TRAITS_HPP_
