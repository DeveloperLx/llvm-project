//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___CONCEPTS_COMMON_REFERENCE_WITH_H
#define _LIBCPP___CONCEPTS_COMMON_REFERENCE_WITH_H

#include <__concepts/convertible_to.h>
#include <__concepts/same_as.h>
#include <__config>
#include <type_traits>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#  pragma clang include_instead(<concepts>)
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

#if !defined(_LIBCPP_HAS_NO_CONCEPTS)

// [concept.commonref]

template<class _Tp, class _Up>
concept common_reference_with =
  same_as<common_reference_t<_Tp, _Up>, common_reference_t<_Up, _Tp>> &&
  convertible_to<_Tp, common_reference_t<_Tp, _Up>> &&
  convertible_to<_Up, common_reference_t<_Tp, _Up>>;

#endif // !defined(_LIBCPP_HAS_NO_CONCEPTS)

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___CONCEPTS_COMMON_REFERENCE_WITH_H
