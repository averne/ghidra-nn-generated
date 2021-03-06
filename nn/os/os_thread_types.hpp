/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <vapours.hpp>
#include <nn/os/os_thread_common.hpp>
#include <nn/os/os_thread_local_storage_common.hpp>
#include <nn/os/os_thread_local_storage_api.hpp>
#include <nn/os/impl/os_internal_critical_section.hpp>
#include <nn/os/impl/os_internal_condition_variable.hpp>

namespace nn::os {

    namespace impl {

        class WaitableObjectList;

    }

    using ThreadId = u64;

    /* TODO */
    using ThreadImpl = ::Thread;

    struct ThreadType {
        enum State {
            State_NotInitialized         = 0,
            State_Initialized            = 1,
            State_DestroyedBeforeStarted = 2,
            State_Started                = 3,
            State_Terminated             = 4,
        };

        TYPED_STORAGE(util::IntrusiveListNode) all_threads_node;
        util::TypedStorage<impl::WaitableObjectList, sizeof(util::IntrusiveListNode), alignof(util::IntrusiveListNode)> waitlist;
        uintptr_t reserved[4];
        u8 state;
        u8 suspend_count;
        s32 base_priority;
        char name_buffer[ThreadNameLengthMax];
        const char *name_pointer;
        ThreadId thread_id;
        void *stack;
        size_t stack_size;
        ThreadFunction function;
        void *argument;
        mutable impl::InternalCriticalSectionStorage cs_thread;
        mutable impl::InternalConditionVariableStorage cv_thread;

        ThreadImpl *thread_impl;
        ThreadImpl thread_impl_storage;
    };


    constexpr inline s32 IdealCoreDontCare   = -1;
    constexpr inline s32 IdealCoreUseDefault = -2;
    constexpr inline s32 IdealCoreNoUpdate   = -3;

}
