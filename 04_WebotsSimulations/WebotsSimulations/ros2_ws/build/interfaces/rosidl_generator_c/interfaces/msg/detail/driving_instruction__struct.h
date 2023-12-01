// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/DrivingInstruction.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__STRUCT_H_
#define INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'lidar_scan'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/DrivingInstruction in the package interfaces.
typedef struct interfaces__msg__DrivingInstruction
{
  rosidl_runtime_c__float__Sequence lidar_scan;
} interfaces__msg__DrivingInstruction;

// Struct for a sequence of interfaces__msg__DrivingInstruction.
typedef struct interfaces__msg__DrivingInstruction__Sequence
{
  interfaces__msg__DrivingInstruction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__DrivingInstruction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__DRIVING_INSTRUCTION__STRUCT_H_
