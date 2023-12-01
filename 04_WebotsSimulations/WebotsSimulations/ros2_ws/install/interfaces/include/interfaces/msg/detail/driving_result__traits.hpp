// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/DrivingResult.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_RESULT__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__DRIVING_RESULT__TRAITS_HPP_

#include "interfaces/msg/detail/driving_result__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'instruction'
#include "interfaces/msg/detail/mon_ackermann_drive__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::msg::DrivingResult>()
{
  return "interfaces::msg::DrivingResult";
}

template<>
inline const char * name<interfaces::msg::DrivingResult>()
{
  return "interfaces/msg/DrivingResult";
}

template<>
struct has_fixed_size<interfaces::msg::DrivingResult>
  : std::integral_constant<bool, has_fixed_size<interfaces::msg::MonAckermannDrive>::value> {};

template<>
struct has_bounded_size<interfaces::msg::DrivingResult>
  : std::integral_constant<bool, has_bounded_size<interfaces::msg::MonAckermannDrive>::value> {};

template<>
struct is_message<interfaces::msg::DrivingResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__DRIVING_RESULT__TRAITS_HPP_
