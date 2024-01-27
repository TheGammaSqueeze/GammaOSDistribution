/*
 * Copyright (C) 2022 ARM Limited. All rights reserved.
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
#pragma once

#include <string>
#include <string_view>

#include "gralloc/formats.h"
#include "capabilities_type.h"

/*
 * @brief class for handling access to a capabilities xml file.
 */
class ip_capability
{
public:
	enum class permission_t
	{
		read,
		write
	};

	ip_capability(mali_gralloc_ip ip, const char *base_name);
	ip_capability(mali_gralloc_ip ip, const char *base_name, std::string_view base_path);

	/*
	 * @brief Check if a feature is supported by the ip.
	 *
	 * @param feature Feature's name.
	 * @param perm    Requested permission for the feature.
	 *
	 * @return true if the feature is supported with the given permission,
	 *         false otherwise.
	 */
	bool is_feature_supported(const std::string &feature, permission_t permission);

	mali_gralloc_ip get_ip()
	{
		return m_ip;
	}

	const char *get_path()
	{
		return m_path.c_str();
	}

	bool caps_have_value()
	{
		return m_caps.has_value();
	}

private:
	mali_gralloc_ip m_ip;
	std::string m_path;
	std::optional<capabilities_type::Capabilities> m_caps;
};
