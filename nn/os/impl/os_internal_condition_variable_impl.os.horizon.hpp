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
#include <nn/os/os_condition_variable_common.hpp>
#include <nn/os/impl/os_internal_critical_section.hpp>

namespace nn::os::impl {

    class TimeoutHelper;

    class InternalConditionVariableImpl {
        private:
            u32 value;
        public:
            constexpr InternalConditionVariableImpl() : value(0) { /* ... */ }

            constexpr void Initialize() {
                this->value = 0;
            }

            void Signal();
            void Broadcast();

            void Wait(InternalCriticalSection *cs);
            ConditionVariableStatus TimedWait(InternalCriticalSection *cs, const TimeoutHelper &timeout_helper);
    };

}
