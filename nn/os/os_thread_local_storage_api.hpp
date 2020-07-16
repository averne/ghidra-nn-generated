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
#include <nn/os/os_common_types.hpp>
#include <nn/os/os_memory_common.hpp>
#include <nn/os/os_thread_local_storage_common.hpp>

namespace nn::os {

    Result AllocateTlsSlot(TlsSlot *out, TlsDestructor destructor);

    void FreeTlsSlot(TlsSlot slot);

    uintptr_t GetTlsValue(TlsSlot slot);
    void SetTlsValue(TlsSlot slot, uintptr_t value);

}
