// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___ITERATOR_SIZE_H
#define _LIBCPP___ITERATOR_SIZE_H

#include <__config>
#include <cstddef>
#include <type_traits>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#  pragma clang include_instead(<iterator>)
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

#if _LIBCPP_STD_VER > 14

template <class _Cont>
_LIBCPP_INLINE_VISIBILITY
constexpr auto size(const _Cont& __c)
_NOEXCEPT_(noexcept(__c.size()))
-> decltype        (__c.size())
{ return            __c.size(); }

template <class _Tp, size_t _Sz>
_LIBCPP_INLINE_VISIBILITY
constexpr size_t size(const _Tp (&)[_Sz]) noexcept { return _Sz; }

#if _LIBCPP_STD_VER > 17
template <class _Cont>
_LIBCPP_INLINE_VISIBILITY
constexpr auto ssize(const _Cont& __c)
_NOEXCEPT_(noexcept(static_cast<common_type_t<ptrdiff_t, make_signed_t<decltype(__c.size())>>>(__c.size())))
->                              common_type_t<ptrdiff_t, make_signed_t<decltype(__c.size())>>
{ return            static_cast<common_type_t<ptrdiff_t, make_signed_t<decltype(__c.size())>>>(__c.size()); }

template <class _Tp, ptrdiff_t _Sz>
_LIBCPP_INLINE_VISIBILITY
constexpr ptrdiff_t ssize(const _Tp (&)[_Sz]) noexcept { return _Sz; }
#endif

#endif // _LIBCPP_STD_VER > 14

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___ITERATOR_SIZE_H
