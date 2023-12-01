// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/RaceParams.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__RACE_PARAMS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__RACE_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RaceParams in the package interfaces.
typedef struct interfaces__msg__RaceParams
{
  int64_t speed;
  int64_t steering;
} interfaces__msg__RaceParams;

// Struct for a sequence of interfaces__msg__RaceParams.
typedef struct interfaces__msg__RaceParams__Sequence
{
  interfaces__msg__RaceParams * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__RaceParams__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__RACE_PARAMS__STRUCT_H_
