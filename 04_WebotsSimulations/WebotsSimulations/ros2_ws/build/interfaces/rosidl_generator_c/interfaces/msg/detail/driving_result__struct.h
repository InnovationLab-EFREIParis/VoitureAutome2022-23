// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/DrivingResult.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_RESULT__STRUCT_H_
#define INTERFACES__MSG__DETAIL__DRIVING_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'instruction'
#include "interfaces/msg/detail/mon_ackermann_drive__struct.h"

// Struct defined in msg/DrivingResult in the package interfaces.
typedef struct interfaces__msg__DrivingResult
{
  interfaces__msg__MonAckermannDrive instruction;
} interfaces__msg__DrivingResult;

// Struct for a sequence of interfaces__msg__DrivingResult.
typedef struct interfaces__msg__DrivingResult__Sequence
{
  interfaces__msg__DrivingResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__DrivingResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__DRIVING_RESULT__STRUCT_H_
