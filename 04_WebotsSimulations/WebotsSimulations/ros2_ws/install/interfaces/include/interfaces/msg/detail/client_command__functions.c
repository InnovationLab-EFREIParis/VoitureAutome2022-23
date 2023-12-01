// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/ClientCommand.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/client_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interfaces__msg__ClientCommand__init(interfaces__msg__ClientCommand * msg)
{
  if (!msg) {
    return false;
  }
  // up
  // down
  // right
  // left
  return true;
}

void
interfaces__msg__ClientCommand__fini(interfaces__msg__ClientCommand * msg)
{
  if (!msg) {
    return;
  }
  // up
  // down
  // right
  // left
}

bool
interfaces__msg__ClientCommand__are_equal(const interfaces__msg__ClientCommand * lhs, const interfaces__msg__ClientCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // up
  if (lhs->up != rhs->up) {
    return false;
  }
  // down
  if (lhs->down != rhs->down) {
    return false;
  }
  // right
  if (lhs->right != rhs->right) {
    return false;
  }
  // left
  if (lhs->left != rhs->left) {
    return false;
  }
  return true;
}

bool
interfaces__msg__ClientCommand__copy(
  const interfaces__msg__ClientCommand * input,
  interfaces__msg__ClientCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // up
  output->up = input->up;
  // down
  output->down = input->down;
  // right
  output->right = input->right;
  // left
  output->left = input->left;
  return true;
}

interfaces__msg__ClientCommand *
interfaces__msg__ClientCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__ClientCommand * msg = (interfaces__msg__ClientCommand *)allocator.allocate(sizeof(interfaces__msg__ClientCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__ClientCommand));
  bool success = interfaces__msg__ClientCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__ClientCommand__destroy(interfaces__msg__ClientCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__ClientCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__ClientCommand__Sequence__init(interfaces__msg__ClientCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__ClientCommand * data = NULL;

  if (size) {
    data = (interfaces__msg__ClientCommand *)allocator.zero_allocate(size, sizeof(interfaces__msg__ClientCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__ClientCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__ClientCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__msg__ClientCommand__Sequence__fini(interfaces__msg__ClientCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__msg__ClientCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__msg__ClientCommand__Sequence *
interfaces__msg__ClientCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__ClientCommand__Sequence * array = (interfaces__msg__ClientCommand__Sequence *)allocator.allocate(sizeof(interfaces__msg__ClientCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__ClientCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__ClientCommand__Sequence__destroy(interfaces__msg__ClientCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__ClientCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__ClientCommand__Sequence__are_equal(const interfaces__msg__ClientCommand__Sequence * lhs, const interfaces__msg__ClientCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__ClientCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__ClientCommand__Sequence__copy(
  const interfaces__msg__ClientCommand__Sequence * input,
  interfaces__msg__ClientCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__ClientCommand);
    interfaces__msg__ClientCommand * data =
      (interfaces__msg__ClientCommand *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__ClientCommand__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__msg__ClientCommand__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__ClientCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
