// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/DrivingFeedback.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__STRUCT_H_
#define INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'todo'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/DrivingFeedback in the package interfaces.
typedef struct interfaces__msg__DrivingFeedback
{
  rosidl_runtime_c__String todo;
} interfaces__msg__DrivingFeedback;

// Struct for a sequence of interfaces__msg__DrivingFeedback.
typedef struct interfaces__msg__DrivingFeedback__Sequence
{
  interfaces__msg__DrivingFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__DrivingFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__DRIVING_FEEDBACK__STRUCT_H_
