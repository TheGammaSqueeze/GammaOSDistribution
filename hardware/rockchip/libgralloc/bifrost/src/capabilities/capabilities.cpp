/*
 * Copyright (C) 2020, 2022 ARM Limited. All rights reserved.
 *
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "capabilities.h"

#include <string.h>
#include <inttypes.h>
#include <assert.h>
#include <type_traits>

#include "xml_configuration.h"

static bool caps_supports_feature_cpu(const std::string &feature_name)
{
	if (feature_name == "FORMAT_R10G10B10A2")
	{
		return true;
	}
	if (feature_name == "FORMAT_R16G16B16A16_FLOAT")
	{
		return true;
	}
	return false;
}

bool ip_support_feature(mali_gralloc_ip producers, mali_gralloc_ip consumers, const char *name)
{
	static ip_capability capability_handles[] = {
		/* clang-format off */
		{ MALI_GRALLOC_IP_GPU, "gpu" },
		{ MALI_GRALLOC_IP_DPU, "dpu" },
		{ MALI_GRALLOC_IP_DPU_AEU, "dpu_aeu" },
		{ MALI_GRALLOC_IP_VPU, "vpu" },
		{ MALI_GRALLOC_IP_CAM, "cam" },
		/* clang-format on */
	};

	if ((producers & MALI_GRALLOC_IP_CPU || consumers & MALI_GRALLOC_IP_CPU) && !caps_supports_feature_cpu(name))
	{
		MALI_GRALLOC_LOGV("Feature %s not supported on CPU", name);
		return false;
	}

	for (auto &handle : capability_handles)
	{
		/* We handle a missing IP by posing no restrictions for that IP on format allocation. */
		if (!handle.caps_have_value())
		{
			LOG_ALWAYS_FATAL_IF(!strcmp(name, "gpu"), "gpu.xml not found.");
			continue;
		}

		auto ip = handle.get_ip();
		if (producers & ip)
		{
			if (!handle.is_feature_supported(name, ip_capability::permission_t::write))
			{
				MALI_GRALLOC_LOGV("Feature %s not supported on producer %s", name, handle.get_path());
				return false;
			}
		}

		if (consumers & ip)
		{
			if (!handle.is_feature_supported(name, ip_capability::permission_t::read))
			{
				MALI_GRALLOC_LOGV("Feature %s not supported on consumer %s", name, handle.get_path());
				return false;
			}
		}
	}

	return true;
}

/* This is used by the unit tests to get the capabilities for each IP. */
extern "C" bool mali_gralloc_ip_supports_feature(
	mali_gralloc_ip producers, mali_gralloc_ip consumers, const char *feature_name)
{
	return ip_support_feature(producers, consumers, feature_name);
}

static_assert(std::is_same<decltype(&mali_gralloc_ip_supports_feature),
              mali_gralloc_ip_supports_feature_ptr>());
