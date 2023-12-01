// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/RaceParams.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__RACE_PARAMS__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__RACE_PARAMS__TRAITS_HPP_

#include "interfaces/msg/detail/race_params__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::msg::RaceParams>()
{
  return "interfaces::msg::RaceParams";
}

template<>
inline const char * name<interfaces::msg::RaceParams>()
{
  return "interfaces/msg/RaceParams";
}

template<>
struct has_fixed_size<interfaces::msg::RaceParams>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::RaceParams>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::RaceParams>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__RACE_PARAMS__TRAITS_HPP_
